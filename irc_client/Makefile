##
## Makefile for Project-Master in /Users/salimhabchi/vagrant/PSU_2016_myirc
## 
## Made by habchi_s
## Login   <habchi_s@epitech.eu>
## 
## Started on  Sun Jun 11 22:08:20 2017 habchi_s
## Last update Sun Jun 11 22:42:34 2017 habchi_s
####

CC	= gcc

NAME	= ../client

CFLAGS	+= -W -Wall -Wextra -pedantic
CFLAGS	+= -Iinclude -I../common/includes/

SRCS	= sources/client.c \
	sources/utils.c \
	sources/tools.c \
	../common/lib/ring_buffer/source/ring_buffer.c \
	../common/lib/ring_buffer/source/rb_content.c \
	../common/stwb.c \
	../common/reader.c \
	../common/get_port.c \
	../common/grammar.c \
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

re: fclean all

.PHONY: all clean fclean re
