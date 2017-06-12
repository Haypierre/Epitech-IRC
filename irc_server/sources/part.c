/*
** part.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Sun Jun 11 13:19:10 2017 Salim Habchi
** Last update Sun Jun 11 23:01:25 2017 habchi_s
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

static void
kick_client(t_server *server, t_channel *channel, t_client *client)
{
  t_elem	*walker;

  walker = server->channels->head;
  while (walker)
    {
      if (!strcmp(GETFIELD(t_channel, name), channel->name))
	remove_by_param(GETFIELD(t_channel, clients),
			(void *)client, sizeof(t_client));
      walker = walker->next;
    }
}

static void
leave_channel(t_server *server, t_channel *channel, t_client *client)
{
  t_elem	*walker;

  walker = server->clients->head;
  while (walker)
    {
      if (!strcmp(GETFIELD(t_client, nickname), client->nickname))
	remove_by_param(GETFIELD(t_client, channels),
			(void *)channel, sizeof(t_channel));
      walker = walker->next;
    }
}

static void
leave_chan(t_server *server, t_channel *to_leave, t_client *client, char **arg)
{
  char		buffer[REPLIESIZE];

  memset(buffer, 0, REPLIESIZE);
  if (!delet_channel(client->channels, to_leave, client))
    {
      sprintf(buffer, ERR_NOTONCHANNEL, client->nickname, arg[0]);
      feed_rb(buffer, client->rb_snd);
      return ;
    }
  leave_channel(server, to_leave, client);
  kick_client(server, to_leave, client);
  if (to_leave->clients->len == 0)
    remove_by_param(server->channels, (void *)to_leave, sizeof(t_channel));
}

void		part(t_server *server, t_client *client, char **args)
{
  char		buffer[REPLIESIZE];
  t_elem	*walker;

  memset(buffer, 0, REPLIESIZE);
  walker = server->channels->head;
  if (args[0])
    {
      while (walker)
	{
	  if (!strcmp(GETFIELD(t_channel, name), args[0]))
	    {
	      leave_chan(server, (t_channel *)walker->data, client, args);
	      return ;
	    }
	  walker = walker->next;
	}
      sprintf(buffer, ERR_NOSUCHCHANNEL, client->nickname, args[0]);
    }
  else
    sprintf(buffer, ERR_NEEDMOREPARAMS, client->nickname, "PART");
  feed_rb(buffer, client->rb_snd);
}
