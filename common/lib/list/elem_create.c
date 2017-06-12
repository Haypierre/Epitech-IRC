/*
** elem_create.c for list in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Wed May 24 12:12:39 2017 Pierre Hay
** Last update Sun Jun 11 23:01:27 2017 habchi_s
*/

#include <string.h>
#include <stdlib.h>
#include "list.h"

t_elem		*alloc_elem(void)
{
  t_elem	*new;

  new = malloc(sizeof(t_elem));
  return (new);
}

t_elem	*init_elem_by_default(t_elem *elem)
{
  if (elem)
    {
      elem->data = NULL;
      elem->size = -1;
      elem->next = NULL;
      elem->prev = NULL;
    }
  return (elem);
}

t_elem	*init_elem_by_param(t_elem *elem, void *data, int size)
{
  if (elem)
    {
      elem->data = malloc(size);
      if (elem->data)
	{
	  elem->data = memcpy(elem->data, data, size);
	  elem->size = size;
	}
    }
  return (elem);
}

t_elem		*new_elem_by_default(void)
{
  t_elem	*elem;

  elem = alloc_elem();
  return (elem != NULL ? init_elem_by_default(elem) : NULL);

}

t_elem		*new_elem_by_param(void *data, int size)
{
  t_elem	*elem;

  elem = alloc_elem();
  return (elem != NULL ? init_elem_by_param(elem, data, size) : NULL);
}
