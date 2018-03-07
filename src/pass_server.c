/*
** pass_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:49:59 2017 florian lentz
** Last update Sat May 20 10:47:21 2017 florian lentz
*/

#include <string.h>
#include "server.h"

void		pass_server(t_server *server, char *param)
{
  if (server->name == NULL || server->name[0] == 0)
    send_to_client(server, 503, (char*)0);
  else if (server->user_connect == 1 && (param[0] == 0 || param[0] == ' ')
      && strncmp(server->name, "Anonymous", 9) == 0)
    {
      server->client_connect = 1;
      send_to_client(server, 230, (char*)0);
    }
  else if (server->user_connect == 0 && (param[0] == 0 || param[0] == ' ')
	   && strncmp(server->name, "Anonymous", 9) != 0)
    send_to_client(server, 530, "Login incorrect.");
  else if (server->client_connect == 1)
    send_to_client(server, 230, (char*)0);
  else
    send_to_client(server, 332, (char*)0);
}
