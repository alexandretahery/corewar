/*
** reader.c for corwar in /home/tahery_b/rendu/CPE/CPE_2015_corewar/v2
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Tue Aug 23 16:49:54 2016 Tahery Alexandre
** Last update Sun Aug 28 20:34:27 2016 jordan barbé
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "get_next_line.h"

static char		*first_read(t_data *data, char *name_file)
{
  char			*str;
  char			*ret;
  int			len;
  int			i;

  i = 0;
  if ((data->fd = open(name_file, O_RDONLY)) == -1)
    return (NULL);
  if ((ret = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  ret[0] = '\0';
  while ((str = get_next_line(data->fd)) != 0)
    {
      if (!str[i = check_2(str, i)])
	;
      else
	{
	  ret = my_strcat(ret, str);
	  len = my_strlen(ret);
	  ret[len] = '\n';
	  ret[len + 1] = '\0';
	}
    }
  ret[my_strlen(ret) - 1] = '\0';
  return (ret);
}

static void		nbr_line(t_data *data, char *str)
{
  int			i;

  i = 0;
  data->lines = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	data->lines++;
      i++;
    }
  data->lines++;
}

static int		my_malloc_array(t_data *data, char *str)
{
  int			count;
  int			cursor;
  int			count_m;

  cursor = 0;
  count = 0;
  count_m = 0;
  if (!(data->array = malloc(sizeof(char *) * data->lines + 2)))
    return (-1);
  while (count != data->lines)
    {
      while (str[cursor] != '\n' && str[cursor] != '\0')
	{
	  cursor++;
	  count_m++;
	}
      if (!(data->array[count] = malloc(sizeof(char) * count_m + 1)))
	return (-1);
      data->array[count][count_m] = '\0';
      count_m = 0;
      cursor++;
      count++;
    }
  return (0);
}

static void		put_str_into_array(t_data *data, char *str)
{
  int			count;
  int			count_x;
  int			count_y;

  count = 0;
  count_x = 0;
  count_y = 0;
  while (str[count] != '\0')
    {
      if (str[count] == '\n')
	{
	  data->array[count_y][count_x] = '\0';
	  count_x = 0;
	  count_y++;
	  count++;
	}
      data->array[count_y][count_x] = str[count];
      count_x++;
      count++;
    }
  data->array[count_y][count_x] = '\0';
}

int		reader(t_data *data, char *name_file)
{
  char		*str;

  if (!(str = first_read(data, name_file)))
    return (1);
  nbr_line(data, str);
  if (my_malloc_array(data, str) == -1)
    return (1);
  put_str_into_array(data, str);
  return (0);
}
