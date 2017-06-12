##
## Makefile for Project-Master in /Users/salimhabchi/vagrant/PSU_2016_myirc
## 
## Made by habchi_s
## Login   <habchi_s@epitech.eu>
## 
## Started on  Sun Jun 11 22:07:57 2017 habchi_s
## Last update Sun Jun 11 22:07:59 2017 habchi_s
####

MAKE1	= make --no-print-directory -C irc_server/

MAKE2	= make --no-print-directory -C irc_client/

PRINTF	= @printf


all: allmake

allmake:
	$(PRINTF) '\033[1;35m> Compiled server\033[0m\n'
	$(MAKE1)
	$(PRINTF) '\033[1;35m> Compiled client\033[0m\n'
	$(MAKE2)

server:
	$(MAKE1)
	$(PRINTF) '\033[1;35m> Compiled server\033[0m\n'

client:
	$(PRINTF) '\033[1;35m> Compiled client\033[0m\n'
	$(MAKE2)

clean:
	$(MAKE1) clean
	$(MAKE2) clean

fclean:
	$(MAKE1) fclean
	$(MAKE2) fclean

re: fclean all

.PHONY: all server client clean fclean re
