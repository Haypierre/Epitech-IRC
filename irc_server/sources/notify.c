/*
** notify.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Sat Jun 10 13:39:45 2017 Salim Habchi
** Last update Sun Jun 11 15:12:23 2017 Pierre Hay
*/

#include <stdio.h>
#include "server.h"

void		notify_all(t_list *clients, char *msg)
{
  t_elem	*walker;

  walker = clients->head;
  while (walker)
    {
      dprintf(GETFIELD(t_client, sockfd), "%s", msg);
      walker = walker->next;
    }
}
