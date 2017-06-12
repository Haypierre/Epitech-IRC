/*
** channel.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Fri Jun  9 14:32:42 2017 Pierre Hay
** Last update Sun Jun 11 22:31:56 2017 habchi_s
*/

#include <stdio.h>
#include <string.h>
#include <err.h>
#include <stdlib.h>
#include "server.h"

int	next_replie(char *buffer)
{
  int	index;

  index = 0;
  while (buffer[index] && buffer[index] != '\n')
    index++;
  return (index);
}

t_channel	*get_channel(t_list *channels, char *c_name)
{
  t_elem	*walker;

  walker = channels->head;
  if (walker)
    {
      while (walker && my_strcmp(GETFIELD(t_channel, name), c_name))
	walker = walker->next;
    }
  return (walker ? (t_channel *)walker->data : NULL);
}

void	join_channel(char *buffer, t_client *client, t_channel *target)
{
  if (push_back(client->channels,
		(void *)target, sizeof(t_channel)) == -1
      || push_back(target->clients,
		   (void *)client, sizeof(t_client)) == -1)
    err(1, "malloc");
  sprintf(buffer, RPL_NAMREPLY, target->name, client->nickname);
  sprintf(buffer + next_replie(buffer) + 1,
	  RPL_ENDOFNAMES, client->nickname, target->name);
}

void
create_channel(char *buffer, t_client *client, t_list *channels, char *name)
{
  t_channel	*new_channel;

  if (!(new_channel = malloc(sizeof(t_channel))))
    err(1, "malloc");
  new_channel->name = strdup(name);
  new_channel->topic = NULL;
  new_channel->clients = new_list_by_default();
  if (!new_channel->clients
      || push_back(channels, (void *)new_channel, sizeof(t_channel)) == -1)
    err(1, "malloc");
  printf("Channel creation succeed.\n");
  join_channel(buffer, client, new_channel);
}
