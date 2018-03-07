/*
** user_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:49:34 2017 florian lentz
** Last update Sat May 20 10:49:01 2017 florian lentz
*/

#include <string.h>
#include "server.h"

void		user_server(t_server *server, char *param)
{
  server->name = strdup(param);
  if (param[0] == 0)
    send_to_client(server, 530, "Permission denied.");
  else if (strncmp("Anonymous ", param, 9) == 0 && server->client_connect == 0)
    {
      server->user_connect = 1;
      send_to_client(server, 331, (char*)0);
    }
  else if (server->client_connect == 1)
    send_to_client(server, 530, "Can't change from guest user.");
  else
    {
      server->user_connect = 0;
      send_to_client(server, 331, (char*)0);
    }
}
