/*
** pasv_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:52:44 2017 florian lentz
** Last update Sat May 20 19:44:21 2017 florian lentz
*/

#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

static void		start_pasv(t_server *server)
{
  int			i;
  int			port;
  int			first_port;
  int			second_port;
  char			buf[256];

  i = -1;
  bzero(buf, 256);
  port = ntohs(server->data.s_in_pasv.sin_port);
  first_port = port / 256;
  second_port = port % 256;
  while (server->ip_client[++i])
    if (server->ip_client[i] == '.')
      server->ip_client[i] = ',';
  snprintf(buf, 256, "%s,%d,%d", server->ip_client, first_port, second_port);
  server->mod_pasv = 1;
  send_to_client(server, 227, buf);
}

int			accept_data(t_server *server)
{
  int			ret;

  ret = accept(server->data.fd,
	       (struct sockaddr *)&server->data.s_in_pasv,
	       &server->data.s_in_size);
  return (ret);
}

void			pasv_server(t_server *server, char* param)
{
  struct protoent	*pe;

  (void)param;
  if ((pe = getprotobyname("TCP")) == NULL)
    send_to_client(server, 227, "Command PASV fail.");
  else if ((server->data.fd =
	    socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    send_to_client(server, 227, "Command PASV fail.");
  server->data.s_in_pasv.sin_family = AF_INET;
  server->data.s_in_pasv.sin_port = 0;
  server->data.s_in_pasv.sin_addr.s_addr = INADDR_ANY;
  if ((bind(server->data.fd,
	    (const struct sockaddr *)&server->data.s_in_pasv,
	    sizeof(server->data.s_in_pasv))) == -1)
    send_to_client(server, 227, "Command PASV fail.");
  else if ((listen(server->data.fd, 1)) == -1)
    send_to_client(server, 227, "Command PASV fail.");
  server->data.s_in_size = sizeof(server->data.s_in_pasv);
  if ((getsockname(server->data.fd,
		   (struct sockaddr *)&server->data.s_in_pasv,
		   &server->data.s_in_size)) == -1)
    send_to_client(server, 227, "Command PASV fail.");
  start_pasv(server);
}
