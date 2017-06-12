/*
** ring_buffer.h for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/common/lib/ring_buffer/include
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Sat Jun  3 13:04:19 2017 Pierre Hay
** Last update Sun Jun 11 23:01:24 2017 habchi_s
*/

#ifndef	RING_BUFFER_H_
# define RING_BUFFER_H_

# include <stddef.h>
# include <stdbool.h>

typedef struct	s_ring
{
  void		*buffer;
  size_t	capacity;
  size_t	count;
  size_t	size;
  size_t	head;
  size_t	tail;
}		t_ring;

# define NEXTHEAD(RB)	((RB->head + RB->size) % (RB->capacity * RB->size))
# define NEXTTAIL(RB)	((RB->tail + RB->size) % (RB->capacity * RB->size))
# define ISBUFFEREMPTY(RB)	(RB->count == 0)
# define ISBUFFERFULL(RB)	(RB->count == RB->capacity)

/*
** ring_buffer.c
*/
t_ring	*new_ring_by_param(int, int);
int	rb_push(t_ring *, void *, size_t);
void	*rb_pop(t_ring *);

/*
**ring_content.c
*/
char	*get_buffer(t_ring *);
char	*get_buffer_light(t_ring *);
void	free_rb(t_ring *);
void	feed_rb(char *, t_ring *);

#endif /* !RING_BUFFER_H_ */
