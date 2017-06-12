/*
** list.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Sun Jun 11 13:13:59 2017 Salim Habchi
** Last update Sun Jun 11 23:01:25 2017 habchi_s
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

void		simple_list(t_server *server, t_client *client)
{
  t_elem	*tmp;
  char		buffer[REPLIESIZE];

  tmp = server->channels->head;
  memset(buffer, 0, REPLIESIZE);
  feed_rb(RPL_LISTSTART, client->rb_snd);
  while (tmp)
    {
      sprintf(buffer, "322 %s %s\r\n",
	      client->nickname, ((t_channel *)tmp->data)->name);
      feed_rb(buffer, client->rb_snd);
      tmp = tmp->next;
    }
  feed_rb(RPL_LISTEND, client->rb_snd);
}

void	list(t_server *server, t_client *client, char **args)
{
  UNUSED(args);
  simple_list(server, client);
}
