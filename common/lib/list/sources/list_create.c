/*
** list_create.c for list in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Wed May 24 10:54:29 2017 Pierre Hay
** Last update Sun Jun 11 22:12:36 2017 habchi_s
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list		*alloc_list()
{
  t_list	*new_list;

  new_list = NULL;
  new_list = malloc(sizeof(t_list));
  return (new_list);
}

t_list	*init_list_by_default(t_list *list)
{
  if (list)
    {
      list->empty = true;
      list->len = 0;
      list->head = NULL;
      list->tail = NULL;
    }
  return (list);
}

t_list		*new_list_by_default()
{
  t_list	*list;

  list = alloc_list();
  list = init_list_by_default(list);
  return (list);
}

static int	delete_list_elems(t_elem *elem)
{
  if (elem)
    {
      if (elem->next)
	delete_list_elems(elem->next);
      delete_elem(elem);
    }
  return (0);
}

int	delete_list(t_list *list)
{
  if (list)
    delete_list_elems(list->head);
  free(list);
  return (0);
}
