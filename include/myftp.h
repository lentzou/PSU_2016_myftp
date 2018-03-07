/*
** myftp.h for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Tue May  9 13:59:23 2017 florian lentz
** Last update Sat May 20 19:43:49 2017 florian lentz
*/

#ifndef _MYFTP_
# define _MYFTP_

#include <arpa/inet.h>

typedef struct		s_data
{
  int			fd;
  socklen_t		s_in_size;
  struct sockaddr_in	s_in_pasv;
}			t_data;

typedef struct		s_server
{
  int			port;
  int			mod_pasv;
  int			fd_client;
  int			user_connect;
  int			client_connect;
  char			*name;
  char			*path;
  char			*ip_client;
  t_data		data;
}			t_server;

extern int		g_fd_socket;

void			print_err_server(const char *str);
void			build_server(t_server *server);
void			execute_cmd(t_server *server, char *buf);
void			send_to_client(t_server *server, int num, char *opt);
int			accept_data(t_server *server);

#endif /* !_MYFTP_ */
