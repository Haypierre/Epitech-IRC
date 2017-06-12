/*
** message.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/sources
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Sat Jun 10 14:19:55 2017 Pierre Hay
** Last update Sun Jun 11 23:01:25 2017 habchi_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"

static bool
is_in_channel(char *nickname, t_channel *to_check)
{
  t_elem	*walker;

  walker = to_check->clients->head;
  while (walker)
    {
      if (!my_strcmp(nickname, GETFIELD(t_client, nickname)))
	return (true);
      walker = walker->next;
    }
  return (false);
}

static void
send_to_all(char *msg, t_channel *target, t_client *client)
{
  t_elem	*walker;

  walker = target->clients->head;
  while (walker)
    {
      if (my_strcmp(client->nickname, GETFIELD(t_client, nickname)))
	{
	  feed_rb(msg, GETFIELD(t_client, rb_snd));
	  writer(GETFIELD(t_client, sockfd), GETFIELD(t_client, rb_snd));
	}
      walker = walker->next;
    }
}

static void
send_to_channel(t_list *channels, t_client *client, char **args)
{
  char		buffer[REPLIESIZE];
  t_elem	*walker;

  walker = channels->head;
  memset(buffer, 0, REPLIESIZE);
  while (walker)
    {
      if (!my_strcmp(args[0], GETFIELD(t_channel, name)))
	{
	  if (!is_in_channel(client->nickname, (t_channel *)walker->data))
	    {
	      sprintf(buffer, ERR_CANNOTSENDTOCHAN, client->nickname, args[0]);
	      feed_rb(buffer, client->rb_snd);
	    }
	  else
	    {
	      sprintf(buffer, "%s: %s", client->nickname, args[1]);
	      send_to_all(buffer, (t_channel *)walker->data, client);
	    }
	  return ;
	}
      walker = walker->next;
    }
  sprintf(buffer, ERR_NOSUCHCHANNEL, client->nickname, args[0]);
  feed_rb(buffer, client->rb_snd);
}

static void
send_to_client(t_list *clients, t_client *client, char **args)
{
  char		buffer[REPLIESIZE];
  t_elem	*walker;

  walker = clients->head;
  memset(buffer, 0, REPLIESIZE);
  while (walker)
    {
      if (!my_strcmp(args[0], GETFIELD(t_client, nickname)))
	{
	  sprintf(buffer, "%s: %s", client->nickname, args[1]);
	  feed_rb(buffer, GETFIELD(t_client, rb_snd));
	  writer(GETFIELD(t_client, sockfd), GETFIELD(t_client, rb_snd));
	  return ;
	}
      walker = walker->next;
    }
  sprintf(buffer, ERR_NOSUCHNICK, args[0]);
  feed_rb(buffer, client->rb_snd);
}

void		privmsg(t_server *server, t_client *client, char **args)
{
  char		buffer[REPLIESIZE];
  int		ac;

  memset(buffer, 0, REPLIESIZE);
  ac = tablen(args);
  if (ac == 0)
    sprintf(buffer, ERR_NORECIPIENT, client->nickname);
  else if (ac == 1)
    sprintf(buffer, ERR_NOTEXTTOSEND, client->nickname);
  else
    {
      **args == '#' || **args == '&' ?
	send_to_channel(server->channels, client, args)
	: send_to_client(server->clients, client, args);
      return ;
    }
  feed_rb(buffer, client->rb_snd);
}
