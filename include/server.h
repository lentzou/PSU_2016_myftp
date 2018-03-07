/*
** server.h for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Fri May 12 12:04:23 2017 florian lentz
** Last update Sat May 20 11:43:08 2017 florian lentz
*/

#ifndef _SERVER_H_
# define _SERVER_H_

#include "myftp.h"

typedef struct		s_cmds
{
  char			*name;
  void			(*func)(t_server *server, char *param);
  int			log;
}			t_cmds;

void		user_server(t_server *server, char *param);
void		pass_server(t_server *server, char *param);
void		cwd_server(t_server *server, char *param);
void		cdup_server(t_server *server, char *param);
void		quit_server(t_server *server, char *param);
void		dele_server(t_server *server, char *param);
void		pwd_server(t_server *server, char *param);
void		pasv_server(t_server *server, char *param);
void		port_server(t_server *server, char *param);
void		help_server(t_server *server, char *param);
void		noop_server(t_server *server, char *param);
void		retr_server(t_server *server, char *param);
void		stor_server(t_server *server, char *param);
void		list_server(t_server *server, char *param);

static const t_cmds	g_cmds[] =
{
  { "USER", user_server, 0 },
  { "PASS", pass_server, 0 },
  { "CWD", cwd_server, 1 },
  { "CDUP", cdup_server, 1 },
  { "QUIT", quit_server, 0 },
  { "DELE", dele_server, 1 },
  { "PWD", pwd_server, 1 },
  { "PASV", pasv_server, 1 },
  { "PORT", port_server, 1 },
  { "HELP", help_server, 1 },
  { "NOOP", noop_server, 1 },
  { "RETR", retr_server, 1 },
  { "STOR", stor_server, 1 },
  { "LIST", list_server, 1 },
  { (char*)0, (void*)0, -1 }
};

typedef struct		s_reply
{
  int			num;
  char			*msg;
  int			option;
}			t_reply;

static const t_reply	g_reply[] =
{
  { 120, "%d Service ready in %s minutes.\r\n", 1 },
  { 125, "%d Data connection already open; transfer starting.\r\n", 0 },
  { 150, "%d File status okay; about to open data connection.\r\n", 0 },
  { 200, "%d Command okay.\r\n", 0 },
  { 214, "%d %s\r\n", 1 },
  { 220, "%d Service ready for new user.\r\n", 0 },
  { 221, "%d Service closing control connection.\r\n", 0 },
  { 226, "%d Closing data connection.\r\n", 0 },
  { 227, "%d Entering Passive Mode (%s).\r\n", 1 },
  { 230, "%d User logged in, proceed.\r\n", 0 },
  { 250, "%d Requested file action okay, completed.\r\n", 0 },
  { 257, "%d \"%s\"\r\n", 1 },
  { 331, "%d User name okay, need password.\r\n", 0 },
  { 332, "%d Need account for login.\r\n", 0 },
  { 425, "%d Use PORT or PASV first.\r\n", 0 },
  { 500, "%d Command not implemented.\r\n", 0 },
  { 503, "%d Login with USER first.\r\n", 0 },
  { 530, "%d %s\r\n", 1 },
  { 550, "%d %s\r\n", 1 },
  { -1, (char*)0, -1 }
};

typedef struct		s_help
{
  char			*cmd;
  char			*msg;
}			t_help;

static const t_help	g_help[] =
{
  { "USER", "Specify user for authentification" },
  { "PASS", "Specify password for authentification" },
  { "CWD", "Change working directory" },
  { "CDUP", "Change working directory to parent directory" },
  { "QUIT", "Disconnection" },
  { "DELE", "Delete file on the server" },
  { "PWD", "Print working directory" },
  { "PASV", "Enable \"passive\" mode" },
  { "PORT", "Enable \"active\" mode" },
  { "HELP", "List available commands" },
  { "NOOP", "Do nothing" },
  { "RETR", "Download file from server to client" },
  { "STOR", "Upload file from client to server" },
  { "LIST", "List files in the current working directory" },
  { (char*)0, (char*)0 }
};

#endif /* !_SERVER_H_ */
