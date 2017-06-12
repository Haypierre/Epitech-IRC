/*
** basics.c for Project-Master in /vagrant/PSU_2016_myirc/irc_server/sources
** 
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
** 
** Started on  Sun Jun 11 13:11:06 2017 Salim Habchi
** Last update Sun Jun 11 23:01:26 2017 habchi_s
*/

#include "server.h"

bool	sep_connection(char to_check)
{
  return (to_check == ' ' || to_check == '\t'
          || to_check == '\n' || to_check == '\r' ? true : false);
}

int	tablen(char **tab)
{
  int	index;

  index = 0;
  while (tab[index])
    index++;
  return (index);
}
