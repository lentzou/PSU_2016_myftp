/*
** help_server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 12:53:31 2017 florian lentz
** Last update Sat May 20 00:20:37 2017 florian lentz
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

void		help_server(t_server *server, char *param)
{
  int		i;
  char		buf[256];

  i = 0;
  bzero(buf, 256);
  if (param[0] == 0)
    send_to_client(server, 214, "HELP [\"USER, PASS, CWD, CDUP, QUIT, DELE, \
PWD, PASV, PORT, HELP, NOOP, RETR, STOR, LIST\"]");
  else
    {
      while (g_help[i].cmd && strcmp(g_help[i].cmd, param))
	++i;
      if (g_help[i].cmd)
	send_to_client(server, 214, g_help[i].msg);
      else
	{
	  snprintf(buf, 256, "%s : This command does not exist", param);
	  send_to_client(server, 214, buf);
	}
    }
}
