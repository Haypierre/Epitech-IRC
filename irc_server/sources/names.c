/*
** names.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Sun Jun 11 13:21:00 2017 Salim Habchi
** Last update Sun Jun 11 23:01:25 2017 habchi_s
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

void		names(t_server *server, t_client *client, char **args)
{
  char		buffer[REPLIESIZE];
  t_elem	*tmp;
  t_elem	*users;

  memset(buffer, 0, REPLIESIZE);
  tmp = server->channels->head;
  if (args[0])
    {
      while (tmp)
	{
	  if (!strcmp(((t_channel *)tmp->data)->name, args[0]))
	    {
	      users = ((t_channel *)tmp->data)->clients->head;
	      while (users)
		{
		  feed_rb(((t_client *)users->data)->nickname, client->rb_snd);
		  feed_rb("\r\n", client->rb_snd);
		  users = users->next;
		}
	    }
	  tmp = tmp->next;
	}
    }
  sprintf(buffer, RPL_ENDOFNAMES, client->nickname, args[0]);
  feed_rb(buffer, client->rb_snd);
}
