/*
** client.h for c in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_client/include
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Tue May 23 17:15:47 2017 Pierre Hay
** Last update Sun Jun 11 23:01:24 2017 habchi_s
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/select.h>
# include <unistd.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <string.h>
# include <netinet/in.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "common.h"

typedef struct	s_client
{
  char		*ip;
  int		port;
  int		sockfd;
  fd_set	read;
  fd_set	write;
  fd_set	err;
  t_ring	*rb;
}		t_client;

/*
** client.c
*/
int	get_connection(t_client *);
void	launcher();

/*
** utils.c
*/
int	tablen();
bool	sep_connection(char);
bool	is_num(char *);
int	get_port(char *);
void	select_init(t_client *);

/*
** tools.c
*/
void	init_client(t_client *);
int	check_command(char *);
int	connect_socket(t_client *);
void	wait_for_connection(t_client *);

#endif /* !CLIENT_H_ */
