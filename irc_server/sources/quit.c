/*
** quit.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
** 
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
** 
** Started on  Sun Jun 11 13:21:30 2017 Salim Habchi
** Last update Sun Jun 11 23:01:24 2017 habchi_s
*/

#include "server.h"

void	quit(t_server *server, t_client *client, char **args)
{
  (void)args;
  delete_client(server->clients, client);
}
