/*
** process.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Thu Jun  8 17:17:20 2017 Salim Habchi
** Last update Sun Jun 11 22:50:27 2017 habchi_s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

void	unknown_cmd(t_client *client, char *cmd)
{
  char	buffer[REPLIESIZE];

  memset(buffer, 0, REPLIESIZE);
  sprintf(buffer, ERR_UNKNOWNCMD, cmd);
  feed_rb(buffer, client->rb_snd);
}

char	*get_msg(char *str, int stop)
{
  int	index;
  int	count;

  index = 0;
  count = 0;
  while (str[index])
    {
      if (str[index] != ' ' && str[index] != '\t')
	{
	  count++;
	  if (count == stop)
	    return (&str[index]);
	  while (str[index] != ' ' && str[index] != '\t')
	    index++;
	}
      else
	index++;
    }
  return (NULL);
}

void	msg_cmd(t_server *server, t_client *client, char *cmd, char **args)
{
  char	*tab[3];

  tab[0] = args[1];
  if (tablen(args) > 2)
      tab[1] = get_msg(cmd, 3);
  else
    tab[1] = NULL;
  tab[2] = NULL;
  privmsg(server, client, tab);
}

int	select_function(t_server *server, t_client *client, int i, char **tab)
{
  char	buffer[REPLIESIZE];
  char	*tmp;

  tmp = get_buffer(client->rb_rcv);
  memset(buffer, 0, REPLIESIZE);
  if (i == 7)
    {
      g_protocol[i].fptr(server, client, &tab[1]);
      return (1);
    }
  else if (client->state == REGISTERED && i == 8)
    msg_cmd(server, client, tmp, tab);
  else if (client->state == REGISTERED || i < 2)
    g_protocol[i].fptr(server, client, &tab[1]);
  else
    {
      sprintf(buffer, ERR_NOTREGISTERED, client->nickname ?
	      client->nickname : "*");
      feed_rb(buffer, client->rb_snd);
    }
  free(tab[0]);
  free(tab);
  free(tmp);
  return (0);
}

int	process(t_server *server, t_client *client)
{
  char	*tmp;
  char	**tab;
  int	index;

  index = 0;
  tmp = get_buffer_light(client->rb_rcv);
  if (!(tab = my_str_to_wordtab(tmp, &sep_connection)))
    return (-1);
  if (tab[0])
    {
      while (g_protocol[index].name)
	{
	  if (!strcmp(g_protocol[index].name, tab[0]))
	    return (select_function(server, client, index, tab));
	  index++;
	}
      unknown_cmd(client, tab[0]);
    }
  free(get_buffer(client->rb_rcv));
  free(tmp);
  free(tab);
  return (0);
}
