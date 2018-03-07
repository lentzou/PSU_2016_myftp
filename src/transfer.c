/*
** transfer.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Fri May 12 23:37:04 2017 florian lentz
** Last update Sat May 20 12:06:26 2017 florian lentz
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "server.h"

void			send_to_client(t_server *server, int num, char *opt)
{
  int			i;
  char			buf[256];

  i = 0;
  bzero(buf, 256);
  while (g_reply[i].num && g_reply[i].num != num)
    ++i;
  if (g_reply[i].option == 1)
    snprintf(buf, 256, g_reply[i].msg, g_reply[i].num, opt);
  else
    snprintf(buf, 256, g_reply[i].msg, g_reply[i].num);
  write(server->fd_client, buf, strlen(buf));
}

void			execute_cmd(t_server *server, char *buf)
{
  int			i;
  char			*param;

  i = 0;
  while (g_cmds[i].name
	 && strncmp(g_cmds[i].name, buf, strlen(g_cmds[i].name)))
    ++i;
  if (g_cmds[i].name)
    {
      if ((g_cmds[i].log == 1 && server->client_connect == 1)
	  || g_cmds[i].log == 0)
	{
	  param = buf + strlen(g_cmds[i].name) + 1;
	  (g_cmds[i].func)(server, param);
	}
      else
	send_to_client(server, 530, "Not logged in.");
    }
  else if (server->client_connect == 0 && buf[0] != '\0')
    send_to_client(server, 530, "Not logged in.");
  else if (buf[0] != '\0')
    send_to_client(server, 500, (char*)0);
}
