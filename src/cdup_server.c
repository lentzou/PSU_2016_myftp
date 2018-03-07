/*
** cdup_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:50:47 2017 florian lentz
** Last update Sat May 20 01:27:06 2017 florian lentz
*/

#include <unistd.h>
#include "server.h"

void		cdup_server(t_server *server, char *param)
{
  (void)param;
  if (chdir("..") != 0)
    send_to_client(server, 550, "Failed to change directory.");
  else
    {
      server->path = get_current_dir_name();
      send_to_client(server, 250, (char*)0);
    }
}
