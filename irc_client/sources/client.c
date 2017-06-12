/*
** client.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_client/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu May 25 09:22:42 2017 Pierre Hay
** Last update Sun Jun 11 22:46:39 2017 habchi_s
*/

#include "client.h"

int			get_connection(t_client *client)
{
  char			**tab;
  struct protoent	*pe;
  char			*tmp;

  if ((tmp = get_buffer(client->rb)) == NULL)
    err(1, "malloc");
  if (!(tab = my_str_to_wordtab(tmp, &sep_connection)))
      err(1, "malloc");
  if (!tab[0] || check_command(tab[0]) == 1)
      return (1);
  pe = getprotobyname("TCP");
  if (tablen(tab) != 3)
    {
      printf("Bad syntax : /server $host[:$port].\n");
      return (1);
    }
  client->ip = strdup(tab[1]);
  client->port = get_port(tab[2]);
  if (client->port == -1
      || (client->sockfd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (1);
  free(tab);
  free(tmp);
  return (connect_socket(client));
}

void		launcher()
{
  t_client	*client;

  if (!(client = malloc(sizeof(t_client))))
    err(1, "malloc");
  init_client(client);
  wait_for_connection(client);
  while (true)
    {
      select_init(client);
      if (select(client->sockfd + 1,
		 &client->read, &client->write, NULL, NULL) == -1)
	err(1, "select");
      if (FD_ISSET(0, &client->read) == true)
	{
	  reader(0, client->rb);
	  if (FD_ISSET(client->sockfd, &client->write) == true)
	    writer(client->sockfd, client->rb);
	}
      if (FD_ISSET(client->sockfd, &client->read) == true)
	{
	  reader(client->sockfd, client->rb);
	  if (FD_ISSET(0, &client->write) == true)
	    writer(1, client->rb);
	}
    }
}
