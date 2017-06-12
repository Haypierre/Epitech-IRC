/*
** main.c for test in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/common/lib/ring_buffer/source
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Wed Jun  7 17:08:56 2017 Pierre Hay
** Last update Wed Jun  7 17:13:12 2017 Pierre Hay
*/

#include <stdio.h>
#include <unistd.h>
#include "ring_buffer.h"

int		main()
{
  char		*lol = NULL;
  char		c;
  t_ring	*rb;

  rb = new_ring_by_param(10, sizeof(char));
  while (read(0, &c, 1))
    {
      if (rb_push(rb, &c, sizeof(char)) == 1)
	break ;
    }
  lol = rb_pop(rb, lol);
  printf("lol : %s\n", lol);
  return (0);
}
