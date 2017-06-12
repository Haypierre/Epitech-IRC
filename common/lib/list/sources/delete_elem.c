/*
** delete_elem.c for list in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Wed May 24 12:30:23 2017 Pierre Hay
** Last update Sun Jun 11 23:01:27 2017 habchi_s
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int	delete_elem(t_elem *elem)
{
  if (elem)
    {
      if (elem->data)
	free(elem->data);
      free(elem);
    }
  return (0);
}

int		remove_by_param(t_list *list, void *data, int size)
{
  t_elem	*current;

  if (!list || !data || !size)
    return (1);
  current = list->head;
  while (current)
    {
      if (compare_void_pointer(current, data, size))
	{
	  if (current->prev)
	    current->prev->next = current->next;
	  if (current->next)
	    current->next->prev = current->prev;
	  if (list->head == current)
	    list->head = current->next;
	  if (list->tail == current)
	    list->tail = current->prev;
	  delete_elem(current);
	  list->len -= 1;
	  return (0);
	}
      current = current->next;
    }
  return (1);
}
