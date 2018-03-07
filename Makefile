##
## Makefile<PSU_2016_myftp> for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp
##
## Made by florian lentz
## Login   <florian.lentz@epitech.net>
##
## Started on  Tue May  9 14:36:10 2017 florian lentz
## Last update Sat May 20 20:26:23 2017 florian lentz
##

NAME	=	server

SRC	=	src/server.c \
		src/server_socket.c \
		src/transfer.c \
		src/user_server.c \
		src/pass_server.c \
		src/cwd_server.c \
		src/cdup_server.c \
		src/quit_server.c \
		src/dele_server.c \
		src/pwd_server.c \
		src/pasv_server.c \
		src/port_server.c \
		src/help_server.c \
		src/noop_server.c \
		src/retr_server.c \
		src/stor_server.c \
		src/list_server.c \
		src/get_next_line.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -D_GNU_SOURCE -I./include

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY	=	all clean fclean re
