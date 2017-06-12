/*
** common.h for common in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/common/include
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Sat Jun  3 12:11:48 2017 Pierre Hay
** Last update Sun Jun 11 22:12:39 2017 habchi_s
*/

#ifndef COMMON_H_
# define COMMON_H_

# define UNUSED(...) (void)(__VA_ARGS__)
# define BUFFERSIZE 4096

# define MAX_PORT 65535
# define MIN_PORT 1023

# include "ring_buffer.h"
# include "list.h"
# include "protocol.h"

/*
** stwb.c
*/
char	**my_str_to_wordtab(char *, bool (*separator)(char));

/*
** get_proto.c
*/
int	get_proto(char *);

/*
** reader.c
*/
int	reader(int, t_ring *);
int	writer(int, t_ring *);

/*
** get_port.c
*/
bool	is_num(char *);
int	get_port(char *);

/*
** grammar.c
*/
bool    is_channel(char *);
bool    is_command(char *);
bool    is_nickname(char *);

#endif /* !COMMON_H_ */
