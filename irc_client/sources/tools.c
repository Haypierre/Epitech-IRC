/*
** tools.c for Project-Master in /Users/salimhabchi/vagrant/PSU_2016_myirc/irc_client/sources
** 
** Made by habchi_s
** Login   <habchi_s@epitech.eu>
** 
** Started on  Sun Jun 11 22:33:37 2017 habchi_s
** Last update Sun Jun 11 23:01:26 2017 habchi_s
*/

#include "client.h"

void	init_client(t_client *client)
{
  client->ip = NULL;
  client->port = -1;
  client->sockfd = -1;
  if (!(client->rb = new_ring_by_param(4096, sizeof(char))))
    err(1, "malloc");
}

int	check_command(char *cmd)
{
  if (is_command(cmd))
    {
      if (strcasecmp("/server", cmd))
        {
          fprintf(stderr, "Error : Not connected.\n");
          return (1);
        }
    }
  else
    {
      fprintf(stderr, "Command Unknown.\n");
      return (1);
    }
  return (0);
}

int			connect_socket(t_client *client)
{
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(client->port);
  s_in.sin_addr.s_addr = inet_addr(client->ip);
  if (connect(client->sockfd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      client->sockfd = -1;
      perror("connect");
      return (1);
    }
  printf("Connection established\n");
  return (0);
}

void	wait_for_connection(t_client *client)
{
  while (client->sockfd == -1)
    {
      reader(0, client->rb);
      if (!get_connection(client))
        return;
    }
}
