/*
** utils.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_client/sources
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu Jun  8 11:10:03 2017 Pierre Hay
** Last update Thu Jun  8 21:31:01 2017 Pierre Hay
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

bool	sep_connection(char to_check)
{
  return (to_check == ' ' || to_check == '\t'
	  || to_check == ':' || to_check == '\n' ? true : false);
}

void	select_init(t_client *client)
{
  FD_ZERO(&client->read);
  FD_ZERO(&client->write);
  FD_SET(0, &client->read);
  FD_SET(0, &client->write);
  FD_SET(client->sockfd, &client->read);
  FD_SET(client->sockfd, &client->write);
}
