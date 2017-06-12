/*
** socket.c for ftp in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myftp/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu May 18 13:51:11 2017 Pierre Hay
** Last update Sun Jun 11 13:53:49 2017 Salim Habchi
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"

void	init_addr_in(struct sockaddr_in *s_in, int port)
{
  bzero(s_in, sizeof(*s_in));
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
}

int			bind_socket(int sockfd, int *port)
{
  struct sockaddr_in	s_in;

  if (*port > MAX_PORT)
    {
      close(sockfd);
      fprintf(stderr,
	      "System not able to bind a free port to the new socket\n");
      return (-1);
    }
  init_addr_in(&s_in, *port);
  if (bind(sockfd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (errno == EADDRINUSE)
	{
	  *port += 1;
	  bind_socket(sockfd, port);
	}
      else
	{
	  close(sockfd);
	  perror("Bind failed");
	  return (-1);
	}
    }
  return (0);
}

int			create_socket(int *port)
{
  struct protoent	*pe;
  int			sockfd;

  if (!(*port > MIN_PORT && *port < MAX_PORT))
    {
      printf("Bad port specified");
      return (-1);
    }
  if (!(pe = getprotobyname("TCP")))
    return (-1);
  if ((sockfd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      perror("socket");
      return (-1);
    }
  if (bind_socket(sockfd, port) == -1)
    return (-1);
  if (listen(sockfd, 42) == -1)
    {
      close(sockfd);
      perror("Listen failed");
      return (-1);
    }
  return (sockfd);
}
