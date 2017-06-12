/*
** server.h for irc in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myirc/irc_server
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Tue May 23 10:39:25 2017 Pierre Hay
** Last update Sun Jun 11 22:19:42 2017 habchi_s
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/select.h>
# include "common.h"

# define NB_COMMAND 10

typedef enum	state
  {
    UNDEFINED,
    LOGGED,
    REGISTERED
  }		e_state;

typedef struct	s_client
{
  bool		in_chat;
  char		*nickname;
  t_list	*channels;
  t_ring	*rb_rcv;
  t_ring	*rb_snd;
  int		sockfd;
  e_state	state;
}		t_client;

typedef struct	s_channel
{
  char		*name;
  char		*topic;
  t_list	*clients;
}		t_channel;

typedef struct	s_message
{
  char		*editor;
  t_client	*client;
  t_channel	*channel;
  size_t	size;
  bool		delivered;
  char		content[BUFFERSIZE];
}		t_message;

typedef struct	s_server
{
  int		listenfd;
  int		port;
  fd_set	read_fds;
  fd_set	write_fds;
  fd_set	error_fds;
  t_list	*channels;
  t_list	*clients;
}		t_server;

typedef struct	s_cmd
{
  char	*name;
  void	(*fptr)(t_server *, t_client *, char **);
}		t_cmd;

extern t_cmd	*g_protocol;

/*
** basics.c
*/
bool		sep_connection(char);
int		tablen(char **);

/*
** channel.c
*/
int		next_replie(char *);
t_channel	*get_channel(t_list *, char *);
void		join_channel(char *, t_client *, t_channel *);
void		create_channel(char *, t_client *, t_list *, char *);

/*
** delete.c
*/
bool		delet_channel(t_list *, t_channel *, t_client *);

/*
** init_protocol.c
*/
void		init_proto();

/*
** list.c
*/
void		list_with_args(t_server *, t_client *, char *);
void		simple_list(t_server *, t_client *);
void		list(t_server *, t_client *, char **);

/*
** message.c
*/
void		privmsg(t_server *, t_client *, char **);

/*
** names.c
*/
void		names_error(t_client *);
void		names(t_server *, t_client *, char **);

/*
** notify.c
*/
void		notify_all(t_list *, char *);

/*
** part.c
*/
void		part(t_server *, t_client *, char **);

/*
** process.c
*/
int		process(t_server *, t_client *);
int		select_function(t_server *, t_client *, int, char **);

/*
** protocol_log.c
*/
void		nick(t_server *, t_client *, char **);
void		join(t_server *, t_client *, char **);
void		user(t_server *, t_client *, char **);

/*
** quit.c
*/
void		quit(t_server *, t_client *, char **);

/*
** server.c
*/
void		init_client(t_client *);
void		handle_clients(t_server *);
void		run_server(t_server *);

/*
** socket.c
*/
void		init_addr_in(struct sockaddr_in *, int);
int		bind_socket(int, int *);
int		create_socket(int *);

/*
** users.c
*/
void		users(t_server *, t_client *, char **);

/*
** utils.c
*/
int		my_strcmp(char *, char *);
void		delete_client(t_list *, t_client *);
int		get_max_fd(t_server *);
void		init_select(t_server *);
int		my_select(t_server *);

#endif /* !SERVER_H_ */
