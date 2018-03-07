/*
** server.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Tue May  9 13:56:45 2017 florian lentz
** Last update Sat May 20 10:54:29 2017 florian lentz
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "myftp.h"

int		g_fd_socket = 0;

void		print_err_server(const char *str)
{
  fprintf(stderr, "%s", str);
  exit(1);
}

static void	catch_signal_server(int sig)
{
  (void)sig;
  close(g_fd_socket);
  exit(1);
}

static void	check_arg(char **av, t_server *server)
{
  if ((server->port = atoi(av[1])) == 0)
    print_err_server("Bad port\n");
  server->path = av[2];
  if (chdir(server->path) != 0)
    print_err_server("Path incorrect\n");
  build_server(server);
}

int		main(const int ac, char**av)
{
  t_server	server;

  if (ac != 3)
    print_err_server("Usage : ./server [port] [path]\n");
  signal(SIGINT, catch_signal_server);
  check_arg(av, &server);
  return (0);
}
