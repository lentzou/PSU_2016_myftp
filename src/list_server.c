/*
** list_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:54:55 2017 florian lentz
** Last update Sat May 20 20:22:38 2017 florian lentz
*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "server.h"

void			list_server(t_server *server, char *param)
{
  DIR			*dir;
  struct dirent		*file;
  char			buf[4096];

  (void)param;
  if (server->mod_pasv == 1)
    {
      bzero(buf, 4096);
      dir = opendir(".");
      send_to_client(server, 150, (char*)0);
      while ((file = readdir(dir)) != NULL)
	{
	  snprintf(buf, 4096, "%s ", file->d_name);
	  write(server->fd_client, buf, strlen(buf));
	}
      write(server->fd_client, "\n", 1);
      send_to_client(server, 226, (char*)0);
      closedir(dir);
    }
  else
    send_to_client(server, 425, (char*)0);
}
