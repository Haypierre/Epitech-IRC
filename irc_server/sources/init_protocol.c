/*
** init_protocol.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/sources
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Thu Jun  8 18:27:31 2017 Pierre Hay
** Last update Sun Jun 11 13:21:46 2017 Salim Habchi
*/

#include <stdlib.h>
#include <err.h>
#include "server.h"

t_cmd	 *g_protocol = NULL;

void	init_proto()
{
  if ((g_protocol = malloc(sizeof(t_cmd) * NB_COMMAND)) == NULL)
    return;
  g_protocol[0].name = "NICK";
  g_protocol[0].fptr = &nick;
  g_protocol[1].name = "USER";
  g_protocol[1].fptr = &user;
  g_protocol[2].name = "JOIN";
  g_protocol[2].fptr = &join;
  g_protocol[3].name = "PART";
  g_protocol[3].fptr = &part;
  g_protocol[4].name = "USERS";
  g_protocol[4].fptr = &users;
  g_protocol[5].name = "NAMES";
  g_protocol[5].fptr = &names;
  g_protocol[6].name = "LIST";
  g_protocol[6].fptr = &list;
  g_protocol[7].name = "QUIT";
  g_protocol[7].fptr = &quit;
  g_protocol[8].name = "PRIVMSG";
  g_protocol[8].fptr = &privmsg;
  g_protocol[9].name = NULL;
  g_protocol[9].fptr = NULL;
}
