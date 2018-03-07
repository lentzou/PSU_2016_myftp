/*
** quit_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:51:15 2017 florian lentz
** Last update Sat May 20 10:56:38 2017 florian lentz
*/

#include <unistd.h>
#include "server.h"

void		quit_server(t_server *server, char *param)
{
  (void)param;
  send_to_client(server, 221, (char*)0);
  close(server->fd_client);
}
