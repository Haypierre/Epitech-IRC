/*
** utils.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/sources
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu Jun  8 13:38:18 2017 Pierre Hay
** Last update Sun Jun 11 22:19:39 2017 habchi_s
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include "server.h"

int	my_strcmp(char *s1, char *s2)
{
  if (!s1 || !s2)
    return (1);
  return (strcmp(s1, s2));
}

void	delete_client(t_list *clients, t_client *client)
{
  close(client->sockfd);
  if (client->nickname)
    free(client->nickname);
  free_rb(client->rb_rcv);
  free_rb(client->rb_snd);
  free(client->channels);
  remove_by_param(clients, (void *)client, sizeof(t_client));
}

int		get_max_fd(t_server *server)
{
  t_elem	*walker;
  int		max;

  walker = server->clients->head;
  if (!walker)
    return (server->listenfd);
  walker = server->clients->head;
  max = ((t_client *)walker->data)->sockfd;
  while (walker)
    {
      if (((t_client *)walker->data)->sockfd > max)
	max = ((t_client *)walker->data)->sockfd;
      walker = walker->next;
    }
  return (max);
}

void		init_select(t_server *server)
{
  t_elem	*walker;

  FD_ZERO(&server->read_fds);
  FD_ZERO(&server->write_fds);
  FD_ZERO(&server->error_fds);
  FD_SET(server->listenfd, &server->read_fds);
  FD_SET(0, &server->read_fds);
  FD_SET(0, &server->write_fds);
  FD_SET(0, &server->error_fds);
  FD_SET(1, &server->read_fds);
  FD_SET(1, &server->write_fds);
  FD_SET(1, &server->error_fds);
  walker = server->clients->head;
  while (walker)
    {
      FD_SET(GETFIELD(t_client, sockfd), &server->read_fds);
      FD_SET(GETFIELD(t_client, sockfd), &server->write_fds);
      FD_SET(GETFIELD(t_client, sockfd), &server->error_fds);
      walker = walker->next;
    }
}

int			my_select(t_server *server)
{
  struct timeval	time;

  time.tv_sec = 1;
  time.tv_usec = 0;
  return (select(get_max_fd(server) + 1,
		 &server->read_fds, &server->write_fds, NULL, &time));
}
