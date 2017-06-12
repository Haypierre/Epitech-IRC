/*
** delet.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Fri Jun  9 12:57:50 2017 Salim Habchi
** Last update Sun Jun 11 18:09:33 2017 Pierre Hay
*/

#include "server.h"

bool	delet_channel(t_list *channels, t_channel *channel, t_client *client)
{
  if (remove_by_param(channel->clients, (void *)client, sizeof(t_client))
      && remove_by_param(channels, (void *)channel, sizeof(t_channel)))
    return (false);
  return (true);
}
