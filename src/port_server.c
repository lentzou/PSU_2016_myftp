/*
** port_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:53:10 2017 florian lentz
** Last update Sat May 20 19:56:55 2017 florian lentz
*/

#include "server.h"

void		port_server(t_server *server, char *param)
{
  (void)param;
  send_to_client(server, 200, (char*)0);
}
