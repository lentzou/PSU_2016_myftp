/*
** stor_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:54:31 2017 florian lentz
** Last update Sat May 20 20:09:00 2017 florian lentz
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

static void	stor(t_server *server, int fd, int fd_pasv)
{
  int		count;
  char		buf[4096];

  count = 0;
  bzero(buf, 4096);
  send_to_client(server, 150, (char*)0);
  while ((count = read(fd_pasv, buf, 4096)) > 0)
    write(fd, buf, count);
  close(fd);
  close(fd_pasv);
  server->mod_pasv = 0;
  send_to_client(server, 226, (char*)0);
}

void		stor_server(t_server *server, char *param)
{
  int		fd;
  int		fd_pasv;

  if (server->mod_pasv == 1)
    {
      if ((fd = open(param, O_CREAT | O_WRONLY,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	  send_to_client(server, 550, "Permission denied.");
      else if ((fd_pasv = accept_data(server)) == -1)
	{
	  close(fd);
	  send_to_client(server, 550, "Accept data socket fail.");
	  server->mod_pasv = 0;
	}
      else
	stor(server, fd, fd_pasv);
    }
  else
    send_to_client(server, 425, (char*)0);
}
