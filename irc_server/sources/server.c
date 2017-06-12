/*
** server.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu May 25 16:41:44 2017 Pierre Hay
** Last update Sun Jun 11 22:22:02 2017 habchi_s
*/

#include <err.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include "server.h"

void		init_client(t_client *client)
{
  client->state = UNDEFINED;
  client->channels = new_list_by_default();
  client->nickname = NULL;
  client->rb_rcv = new_ring_by_param(BUFFERSIZE, sizeof(char));
  client->rb_snd = new_ring_by_param(BUFFERSIZE, sizeof(char));
  if (!client->channels || !client->rb_snd || !client->rb_rcv)
    err(1, "malloc");
}

void		handle_clients(t_server *server)
{
  t_elem	*walker;
  t_elem	*tmp;

  walker = server->clients->head;
  while (walker)
    {
      if (FD_ISSET(GETFIELD(t_client, sockfd), &server->read_fds))
	{
	  tmp = walker->next;
	  if (reader(GETFIELD(t_client, sockfd), GETFIELD(t_client, rb_rcv)))
	    {
	      delete_client(server->clients, (t_client *)walker->data);
	      walker = tmp;
	      continue;
	    }
	  if (process(server, (t_client *)walker->data) == 1)
	    {
	      walker = tmp;
	      continue;
	    }
	  if (FD_ISSET(GETFIELD(t_client, sockfd), &server->write_fds))
	    writer(GETFIELD(t_client, sockfd), GETFIELD(t_client, rb_snd));
	}
      walker = walker->next;
    }
}

void			run_server(t_server *server)
{
  t_client		new_client;
  socklen_t		size_addr;
  struct sockaddr_in	cli_addr;

  size_addr = sizeof(cli_addr);
  init_proto();
  while (true)
    {
      init_select(server);
      if (my_select(server) == -1)
	err(1, "select");
      if (FD_ISSET(server->listenfd, &server->read_fds))
	{
	  if ((new_client.sockfd = accept(server->listenfd,
					  (struct sockaddr *)&cli_addr,
					  &size_addr)) == -1)
	    continue ;
	  init_client(&new_client);
	  if (push_back(server->clients, (void *)&new_client,
			sizeof(new_client)) == -1)
	    err(1, "malloc");
	  printf("Client number %d accepted\n", new_client.sockfd);
	}
      handle_clients(server);
    }
}
