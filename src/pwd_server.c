/*
** pwd_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:52:24 2017 florian lentz
** Last update Fri May 19 23:37:20 2017 florian lentz
*/

#include "server.h"

void		pwd_server(t_server *server, char *param)
{
  (void)param;
  send_to_client(server, 257, server->path);
}
