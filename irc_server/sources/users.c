/*
** users.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Sun Jun 11 13:20:03 2017 Salim Habchi
** Last update Sun Jun 11 23:01:24 2017 habchi_s
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

void		users(t_server *server, t_client *client, char **args)
{
  char		buffer[REPLIESIZE];
  t_elem	*tmp;

  (void)args;
  memset(buffer, 0, REPLIESIZE);
  tmp = server->clients->head;
  feed_rb("353 :", client->rb_snd);
  while (tmp)
    {
      if (((t_client *)tmp->data)->nickname)
	{
	  feed_rb(" ", client->rb_snd);
	  feed_rb(((t_client *)tmp->data)->nickname, client->rb_snd);
	}
      tmp = tmp->next;
    }
  sprintf(buffer, RPL_ENDOFNAMES, client->nickname, client->nickname);
  feed_rb(".\r\n", client->rb_snd);
  feed_rb(buffer, client->rb_snd);
}
