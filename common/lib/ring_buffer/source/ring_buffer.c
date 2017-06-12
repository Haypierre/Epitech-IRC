/*
** ring_buffer.c for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/common/lib/ring_buffer
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Sat Jun  3 16:13:49 2017 Pierre Hay
** Last update Wed Jun  7 17:48:39 2017 Salim Habchi
*/

#include <string.h>
#include <stdio.h>
#include <err.h>
#include <strings.h>
#include <stdlib.h>
#include "ring_buffer.h"

static t_ring	*alloc_ring()
{
  t_ring	*ret;

  ret = malloc(sizeof(t_ring));
  return (ret);
}

static void	init_ring(t_ring *rb, int capacity, int size)
{
  if (rb)
    {
      !(rb->buffer = malloc(capacity * size)) ? err(1, "malloc")
	: bzero(rb->buffer, capacity * size);
      rb->size = size;
      rb->capacity = capacity;
      rb->head = 0;
      rb->tail = 0;
      rb->count = 0;
    }
}

t_ring		*new_ring_by_param(int capacity, int size)
{
  t_ring	*ret;

  ret = alloc_ring();
  if (ret)
    init_ring(ret, capacity, size);
  return (ret);
}

int	rb_push(t_ring *rb, void *item, size_t size)
{
  if (ISBUFFERFULL(rb) || size != rb->size || !item)
    return (1);
  memcpy((char *)rb->buffer + rb->head, item, size);
  rb->head = NEXTHEAD(rb);
  rb->count++;
  return (0);
}

void	*rb_pop(t_ring *rb)
{
  void	*dest;

  dest = NULL;
  if (!ISBUFFEREMPTY(rb))
    {
      rb->tail = NEXTTAIL(rb);
      dest = (char *)rb->buffer + rb->tail;
      rb->count--;
    }
  return (dest);
}
