/*
** get_port.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/common
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu Jun  8 12:54:17 2017 Pierre Hay
** Last update Sun Jun 11 22:50:29 2017 habchi_s
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

bool	is_num(char *str)
{
  while (*str)
    {
      if (!(*str >= '0' && *str <= '9'))
	return (false);
      ++str;
    }
  return (true);
}

int	get_port(char *s_port)
{
  int	port;

  if (!is_num(s_port)
      || !((port = atoi(s_port)) > MIN_PORT && port < MAX_PORT))
    {
      fprintf(stderr, "Bad port specified.\n");
      return (-1);
    }
  return (port);
}
