/*
** list_basics.c for list in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Wed May 24 11:33:04 2017 Pierre Hay
** Last update Sun Jun 11 22:12:37 2017 habchi_s
*/

#include <stdlib.h>
#include "list.h"

int	list_add_back_real(t_list *list, t_elem *elem)
{
  if (list && elem)
    {
      elem->prev = list->tail;
      elem->next = NULL;
      if (list->tail)
	list->tail->next = elem;
      if (!list->head)
	list->head = elem;
      list->tail = elem;
      list->len += 1;
      list->empty = false;
      return (0);
    }
  return (1);
}

int	list_add_front_real(t_list *list, t_elem *elem)
{
  if (list && elem)
    {
      elem->prev = NULL;
      elem->next = list->head;
      if (list->head)
	list->head->prev = elem;
      if (!list->tail)
	list->tail = elem;
      list->head = elem;
      list->len += 1;
      list->empty = false;
      return (0);
    }
  return (1);
}

int	push_back(t_list *list, void *data, int size)
{
  return (list_add_back_real(list, new_elem_by_param(data, size)));
}

int		push_back_light(t_list *list, void *data, int size)
{
  t_elem	*elem;

  elem = alloc_elem();
  if (elem)
    {
      elem->data = data;
      elem->size = size;
    }
  return (list_add_back_real(list, elem));
}

int	push_front(t_list *list, void *data, int size)
{
  return (list_add_front_real(list, new_elem_by_param(data, size)));
}
