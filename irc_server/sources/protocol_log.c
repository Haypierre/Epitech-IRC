/*
** protocol_log.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Fri Jun  9 10:00:01 2017 Salim Habchi
** Last update Sun Jun 11 21:46:38 2017 Pierre Hay
*/

#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

static void
actualise_nickname(t_list *channels, t_client *client, char *new_name)
{
  t_elem	*walker;
  t_elem	*tmp;
  char		*old_name;

  tmp = channels->head;
  while (tmp)
    {
      walker = ((t_channel *)tmp->data)->clients->head;
      while (walker)
	{
	  old_name = GETFIELD(t_client, nickname);
	  if (!my_strcmp(old_name, client->nickname))
	    {
	      free(old_name);
	      if (!(GETFIELD(t_client, nickname) = strdup(new_name)))
		err(1, "malloc");
	    }
	  walker = walker->next;
	}
      tmp = tmp->next;
    }
}

static void
change_nickname(t_server *server, t_client *client, char **args)
{
  if (client->state == UNDEFINED)
    client->state = LOGGED;
  else
    actualise_nickname(server->channels, client, args[0]);
  if (!(client->nickname = strdup(args[0])))
    err(1, "malloc");
}

void		nick(t_server *server, t_client *client, char **args)
{
  char		buff[REPLIESIZE];
  t_elem	*walker;

  walker = server->clients->head;
  memset(buff, 0, REPLIESIZE);
  if (!args[0])
    sprintf(buff, ERR_NONICKNAMEGIVEN,
	    client->nickname ? client->nickname : "*");
  else if (!is_nickname(args[0]))
    sprintf(buff, ERR_ERRONEUSNICKNAME, args[0]);
  else
    {
      while (walker && my_strcmp(GETFIELD(t_client, nickname), args[0]))
	walker = walker->next;
      if (walker)
	sprintf(buff, ERR_NICKNAMEINUSE, args[0]);
      else
	change_nickname(server, client, args);
    }
  feed_rb(buff, client->rb_snd);
}

void		join(t_server *server, t_client *client, char **args)
{
  char		buffer[REPLIESIZE];
  t_channel	*target;

  memset(buffer, 0, REPLIESIZE);
  target = NULL;
  if (!args[0])
    sprintf(buffer, ERR_NEEDMOREPARAMS, client->nickname, "JOIN");
  else if (!is_channel(args[0]))
    sprintf(buffer, ERR_NOSUCHCHANNEL, client->nickname, args[0]);
  else if ((target = get_channel(client->channels, args[0])))
    return ;
  else if (client->channels->len == MAX_CHANNELS)
    sprintf(buffer, ERR_TOOMANYCHANNELS, client->nickname);
  else
    (target = get_channel(server->channels, args[0])) ?
      join_channel(buffer, client, target)
      : create_channel(buffer, client, server->channels, args[0]);
  feed_rb(buffer, client->rb_snd);
}

void	user(t_server *server, t_client *client, char **args)
{
  char	buffer[REPLIESIZE];

  UNUSED(server);
  memset(buffer, 0, REPLIESIZE);
  if (client->state == REGISTERED)
    sprintf(buffer, ERR_ALREADYREGISTERED);
  if (client->state == LOGGED)
    {
      if (tablen(args) < 4 || *args[3] != ':')
	sprintf(buffer, ERR_NEEDMOREPARAMS,
		client->nickname ? client->nickname : "*", "USER");
      else
	{
	  sprintf(buffer, RPL_AUTHENTIFIED, client->nickname);
	  client->state = REGISTERED;
	}
    }
  else
    sprintf(buffer, "Please log in\r\n");
  feed_rb(buffer, client->rb_snd);
}
