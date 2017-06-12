/*
** main.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Wed May 24 15:54:29 2017 Pierre Hay
** Last update Sun Jun 11 20:50:17 2017 Pierre Hay
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <signal.h>
#include "server.h"

t_server	*g_server = NULL;

void		sig_handler(int type)
{
  t_elem	*walker;

  (void)type;
  printf("I close everything\n");
  close(g_server->listenfd);
  walker = g_server->clients->head;
  while (walker)
    {
      close(GETFIELD(t_client, sockfd));
      walker = walker->next;
    }
}

int		main(int ac, char **av)
{
  t_server	*server;

  if (ac != 2)
    {
      fprintf(stderr, "USAGE: ./server port\n");
      return (1);
    }
  if (!(server = malloc(sizeof(t_server))))
    err(1, "malloc");
  if ((server->port = get_port(av[1])) == -1
      || (server->listenfd = create_socket(&server->port)) == -1)
    return (1);
  server->clients = new_list_by_default();
  server->channels = new_list_by_default();
  if (!server->clients || !server->channels)
    err(1, "malloc");
  signal(SIGINT, sig_handler);
  g_server = server;
  run_server(server);
  return (0);
}
