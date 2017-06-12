/*
** list.h for list in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server/includes
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Tue May 23 18:16:19 2017 Pierre Hay
** Last update Sun Jun 11 18:10:42 2017 Pierre Hay
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdbool.h>

# define GETFIELD(TYPE, FIELD) (((TYPE *)walker->data)->FIELD)

typedef struct	s_elem
{
  void		*data;
  int		size;
  struct s_elem	*next;
  struct s_elem	*prev;
}		t_elem;

typedef struct	s_list
{
  bool		empty;
  int		len;
  t_elem	*head;
  t_elem	*tail;
}		t_list;

/*
** list_create.c
*/
bool	compare_void_pointer(t_elem *, void *, int);
t_list	*alloc_list();
t_list	*init_list_by_default(t_list *);
t_list	*new_list_by_default(void);
int	delete_list(t_list *);

/*
** list_basics.c
*/
int	list_add_back_real(t_list *, t_elem *);
int	push_back(t_list *, void *, int);
int	push_back_light(t_list *, void *, int);
int	push_front(t_list *, void *, int);

/*
** list_tools.c
*/
bool	is_in_list(t_list *, void *, int);
void	list_iterator(t_list *, void (*f)(void *, int));
t_list	*list_map(t_list *, t_elem *(*f)(void *, int));

/*
** elem_create.c
*/
t_elem	*alloc_elem(void);
t_elem	*init_elem_by_default(t_elem *);
t_elem	*init_elem_by_param(t_elem *, void *, int);
t_elem	*new_elem_by_default(void);
t_elem	*new_elem_by_param(void *, int);

/*
** elem_delete.c
*/
int	delete_elem(t_elem *);
int	remove_by_param(t_list *, void *, int);

#endif /* !LIST_H_ */
