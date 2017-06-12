/*
** rb_content.c for Project-Master in /vagrant/PSU_2016_myirc/common/lib/ring_buffer/source
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Thu Jun  8 11:08:16 2017 Salim Habchi
** Last update Sun Jun 11 23:01:26 2017 habchi_s
*/

#include <stdlib.h>
#include "ring_buffer.h"

char		*get_buffer(t_ring *rb)
{
  char		*dest;
  char		*tmp;
  unsigned int	index;
  unsigned int	tail;

  if ((dest = malloc(sizeof(char) * (rb->count + 1))) == NULL)
    return (NULL);
  tmp = (char *)rb->buffer;
  index = 0;
  tail = rb->tail;
  while (index < rb->count)
    {
      dest[index] = tmp[tail];
      index++;
      tail = (tail + rb->size) % (rb->capacity * rb->size);
    }
  dest[index] = 0;
  while (rb_pop(rb));
  return (dest);
}

char		*get_buffer_light(t_ring *rb)
{
  char		*dest;
  char		*tmp;
  unsigned int	index;
  unsigned int	tail;

  if ((dest = malloc(sizeof(char) * (rb->count + 1))) == NULL)
    return (NULL);
  tmp = (char *)rb->buffer;
  index = 0;
  tail = rb->tail;
  while (index < rb->count)
    {
      dest[index] = tmp[tail];
      index++;
      tail = (tail + rb->size) % (rb->capacity * rb->size);
    }
  dest[index] = 0;
  return (dest);
}

void	free_rb(t_ring *rb)
{
  if (rb->buffer)
    free(rb->buffer);
  free(rb);
}

void	feed_rb(char *str, t_ring *rb)
{
  int	index;

  index = 0;
  while (str[index])
    {
      rb_push(rb, &str[index], sizeof(char));
      index++;
    }
}
