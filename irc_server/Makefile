##
## Makefile for Project-Master in /Users/salimhabchi/vagrant/PSU_2016_myirc
## 
## Made by habchi_s
## Login   <habchi_s@epitech.eu>
## 
## Started on  Sun Jun 11 22:08:11 2017 habchi_s
## Last update Sun Jun 11 22:22:48 2017 habchi_s
####

CC	= gcc

NAME	= ../server

CFLAGS	+= -W -Wall -Wextra -pedantic
CFLAGS	+= -Iinclude -I../common/includes

SRCS	= sources/utils.c \
	  sources/server.c \
	  sources/socket.c \
	  sources/process.c \
	  sources/init_protocol.c \
	  sources/protocol_log.c \
	  sources/notify.c \
	  sources/delete.c \
	  sources/channel.c \
	  sources/message.c \
	  sources/basics.c \
	  sources/list.c \
	  sources/names.c \
	  sources/part.c \
	  sources/users.c \
	  sources/quit.c \
	  ../common/get_port.c \
	  ../common/reader.c \
	  ../common/stwb.c \
	  ../common/grammar.c \
	  ../common/lib/ring_buffer/source/rb_content.c \
	  ../common/lib/ring_buffer/source/ring_buffer.c \
	  ../common/lib/list/sources/delete_elem.c \
	  ../common/lib/list/sources/elem_create.c \
	  ../common/lib/list/sources/list_basics.c \
	  ../common/lib/list/sources/list_create.c \
	  ../common/lib/list/sources/list_tools.c \
	  main.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

PRINTF	= @printf


all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(PRINTF) '\033[1;32m> Compiled\033[0m\n'

clean:
	$(RM) $(OBJS)
	$(PRINTF) '\033[1;35m> Directory cleaned\033[0m\n'

fclean: clean
	$(RM) $(NAME)
	$(PRINTF) '\033[1;35m> Remove executable\033[0m\n'

re:	fclean all

.PHONY: all clean fclean re
