/*
** dele_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:52:02 2017 florian lentz
** Last update Sat May 20 13:01:45 2017 florian lentz
*/

#include <stdio.h>
#include "server.h"

void		dele_server(t_server *server, char *param)
{
  if (remove(param) == 0)
    send_to_client(server, 250, (char*)0);
  else
    send_to_client(server, 550, "Requested action not taken.");
}
