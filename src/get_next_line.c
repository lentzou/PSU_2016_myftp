/*
** gnl.c for myftp in /home/florian.lentz/rendu/project/PSU_2016_myftp/src/server
**
** Made by florian lentz
** Login   <florian.lentz@epitech.net>
**
** Started on  Sat May 13 01:09:14 2017 florian lentz
** Last update Fri May 19 23:42:30 2017 florian lentz
*/

#include "get_next_line.h"

static char	*my_realloc(char *str, int count)
{
  int		i;
  char		*rea;

  i = 0;
  if (count == 0 && ((str = malloc(READ_SIZE + 1)) == NULL))
    return (NULL);
  if ((rea = malloc(count + READ_SIZE + 1)) == NULL)
    return (NULL);
  while (i <= count)
    {
      rea[i] = str[i];
      ++i;
    }
  rea[i] = '\0';
  free(str);
  return (rea);
}

static char	*init_function(char **line, int *count)
{
  if ((*line = my_realloc(*line, *count)) == NULL)
    return (NULL);
  return (*line);
}

static void	end_function(char *line, int *count, int *index)
{
  line[*count] = '\0';
  *index = 0;
}

static char	*control_d(char *line, int count)
{
  if (count == 0)
    return (NULL);
  return (line);
}

char		*get_next_line(const int fd)
{
  static int	ret;
  static int	index;
  static int	count;
  static char	*line;
  static char	buffer[READ_SIZE];

  if (index == 0 && (ret = read(fd, buffer, READ_SIZE)) < 1)
    return (control_d(line, count));
  init_function(&line, &count);
  while (index < ret)
    {
      if (buffer[index] == '\n')
	{
	  ++index;
	  line[count] = '\0';
	  count = 0;
	  return (line);
	}
      line[count++] = buffer[index++];
    }
  end_function(line, &count, &index);
  if ((get_next_line(fd)) == NULL)
    return (NULL);
  return (line);
}
