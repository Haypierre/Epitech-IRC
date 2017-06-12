/*
** parser.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_client/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu May 25 12:47:41 2017 Pierre Hay
** Last update Sun Jun 11 22:50:29 2017 habchi_s
*/

#include <string.h>
#include "protocol.h"
#include "common.h"

bool		is_channel(char *token)
{
  size_t	len;

  if (*token != '#' && *token != '&')
    return (false);
  len = 1;
  while (*token)
    {
      if (*token == 7 || *token == ' ' || *token == ',')
	return (false);
      ++token;
      ++len;
    }
  return (len <= MAX_LEN_CHANNEL ? true : false);
}

bool		is_command(char *token)
{
  const char	*commands[] = {"server", "nick", "list", "join"
			       , "part", "users", "names", "msg"
			       , "accept_file", "kick", "mode", "invite"
			       , "topic", "quit"};
  int		index;
  int		size;

  index = 0;
  if (*token && *token != '/')
    return (false);
  ++token;
  size = sizeof(commands) / sizeof(const char *);
  while (index < size)
    {
      if (!strcasecmp(token, commands[index]))
	break ;
      index++;
    }
  return (index < size ? true : false);
}

bool		is_special(char c)
{
  size_t	index;
  size_t	len;
  const char	*special;

  special = "-_[]\\`^{}";
  len = strlen(special);
  index = 0;
  while (index < len)
    {
      if (special[index] == c)
	return (true);
      ++index;
    }
  return (false);
}

bool		is_nickname(char *token)
{
  char		c;

  if (strlen(token) > MAX_LEN_NICKNAME)
    return (false);
  while (*token)
    {
      c = *token;
      if ((c >= '0' && c <= '9')  || (c >= 'A' && c <= 'Z')
	  || (c >= 'a' && c <= 'z') || is_special(c))
	{
	  ++token;
	  continue ;
	}
      return (false);
    }
  return (true);
}
