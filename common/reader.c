/*
** reader.c for Project-Master in /vagrant/PSU_2016_myirc/irc_client/sources
**
** Made by Salim Habchi
** Login   <habchi_s@epitech.eu>
**
** Started on  Wed Jun  7 12:53:50 2017 Salim Habchi
** Last update Sun Jun 11 22:19:43 2017 habchi_s
*/

#include <unistd.h>
#include <stdio.h>
#include "common.h"

int	reader(int fd, t_ring *rb)
{
  char	buffer[1];

  while (read(fd, buffer, 1) == 1)
    {
      rb_push(rb, &buffer[0], sizeof(char));
      if (buffer[0] == '\n')
	{
	  printf("%s", get_buffer_light(rb));
	  return (0);
	}
    }
  return (-1);
}

int	writer(int fd, t_ring *rb)
{
  char	*buffer;
  int	ret;
  int	i;
  int	max;

  i = 0;
  buffer = (char *)rb->buffer + rb->tail;
  max = rb->count;
  while (i < max)
    {
      ret = write(fd, &buffer[0], 1);
      buffer = rb_pop(rb);
      if (ret < 1)
	return (ret);
      i++;
    }
  return (0);
}
