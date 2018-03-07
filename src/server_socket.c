/*
** server_socket.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Tue May  9 14:24:53 2017 florian lentz
** Last update Sat May 20 19:43:29 2017 florian lentz
*/

#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"
#include "get_next_line.h"

static void		handle_client(t_server *server)
{
  char			*str;

  server->name = NULL;
  server->mod_pasv = 0;
  server->client_connect = 0;
  send_to_client(server, 220, (char*)0);
  while ((str = get_next_line(server->fd_client)) != NULL)
    {
      if (str[strlen(str) - 1] == '\r')
	str[strlen(str) - 1] = '\0';
      write(1, str, strlen(str));
      write(1, "\n", 1);
      execute_cmd(server, str);
      free(str);
    }
  free(server->name);
  printf("Disconnection from %s:%d\r\n", server->ip_client,
	 server->port);
}

static void		accept_connection(t_server *server)
{
  int			pid;
  socklen_t		s_in_size;
  struct sockaddr_in	s_in_client;

  while (1)
    {
      s_in_size = sizeof(s_in_client);
      if ((server->fd_client = accept(g_fd_socket, (struct sockaddr *)
				      &s_in_client, &s_in_size)) == -1)
	print_err_server("Accept fail\n");
      if ((pid = fork()) == -1)
	print_err_server("Fork fail\n");
      else if (pid == 0)
	{
	  server->ip_client = inet_ntoa(s_in_client.sin_addr);
	  printf("Connection from %s:%d\r\n", server->ip_client, server->port);
	  handle_client(server);
	}
      else
	close(server->fd_client);
    }
}

static void		config_socket(t_server *server)
{
  struct sockaddr_in	s_in_server;

  s_in_server.sin_family = AF_INET;
  s_in_server.sin_port = htons(server->port);
  s_in_server.sin_addr.s_addr = INADDR_ANY;
  if (bind(g_fd_socket, (const struct sockaddr *)&s_in_server,
	   sizeof(s_in_server)) == -1)
    print_err_server("Failed to launch the server\n");
  else if (listen(g_fd_socket, 128) == -1)
    print_err_server("Listen fail\n");
  else
    accept_connection(server);
}

void			build_server(t_server *server)
{
  struct protoent	*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    print_err_server("Getprotobyname fail\n");
  else if ((g_fd_socket = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    print_err_server("Creation of socket fail\n");
  else
    config_socket(server);
}
