/*
** gnl.h for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/include
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 01:18:12 2017 florian lentz
** Last update Sat May 13 01:19:24 2017 florian lentz
*/

#ifndef GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (256)
# endif /* !READ_SIZE */

#include <unistd.h>
#include <stdlib.h>

char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
