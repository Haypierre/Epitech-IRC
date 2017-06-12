/*
** list_tools.c for list in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Wed May 24 09:48:57 2017 Pierre Hay
** Last update Sun May 28 15:22:09 2017 Pierre Hay
*/

#include <stdlib.h>
#include "list.h"

bool	compare_void_pointer(t_elem *elem, void *data, int size)
{
  int	i;

  i = 0;
  if (elem->size == size)
    {
      while (i < size)
	{
	  if (((char *)elem->data)[i] != ((char *)data)[i])
	    break ;
	  ++i;
	}
    }
  return (i == size ? true : false);
}

bool		is_in_list(t_list *list, void *data, int size)
{
  t_elem	*current;

  current = NULL;
  if (!data || !size)
    return (false);
  if (list)
    {
      current = list->head;
      while (current)
	{
	  if (compare_void_pointer(current, data, size))
	    return (true);
	  current = current->next;
	}
    }
  return (false);
}

void		list_iterator(t_list *list, void (*f)(void *data, int size))
{
  t_elem	*current;

  current = NULL;
  if (list && f)
    {
      current = list->head;
      while (current)
	{
	  f(current->data, current->size);
	  current = current->next;
	}
    }
  return ;
}

t_list		*list_map(t_list *list, t_elem *(*f)(void *data, int size))
{
  t_list	*new_list;
  t_elem	*current;
  t_elem	*tmp;

  if (!(new_list = new_list_by_default()))
    return (NULL);
  if (list)
    {
      current = list->head;
      while (current)
	{
	  tmp = f(current->data, current->size);
	  list_add_back_real(new_list, tmp);
	  current = current->next;
	}
    }
  return (new_list);
}
