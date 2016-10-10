/*
** stock_array.c for array in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Wed Aug 24 05:38:41 2016 jordan barbé
** Last update Sun Aug 28 20:47:25 2016 jordan barbé
*/

#include <stdlib.h>
#include "asm.h"

static int	stock_next_mod(t_data *data, int count_y, int c)
{
  c = remove_space_tab(data->array[count_y], c);
  while (data->array[count_y][c] &&
         data->array[count_y][c] >= 'a' &&
         data->array[count_y][c] <= 'z')
    {
      if (data->array[count_y][c] == 'r' &&
          (data->array[count_y][c + 1] >= '0' &&
           data->array[count_y][c + 1] <= '9'))
        return (c);
      c++;
    }
  c = remove_space_tab(data->array[count_y], c);
  if (data->array[count_y][c] == '%')
    c++;
  return (c);
}

static char	*stock_next(t_data *data, int count_y,
			    int c, char *str)
{
  int		i;

  if (data->array[count_y][c] == 'r')
    data->array[count_y][c] = '-';
  i = 0;
  while (data->array[count_y][c] &&
	 data->array[count_y][c] != ' ' &&
	 data->array[count_y][c] != '\t')
        {
          c++;
          i++;
        }
  if (!(str = malloc(sizeof(char) * i + 1)))
    return (NULL);
  return (str);
}

int		stock_in_my_array(t_data *data, int y,
                                  int count_y, int *count_x)
{
  char		*str;

  data->c = 0;
  while (data->array[count_y][data->c])
    {
      data->c = stock_next_mod(data, count_y, data->c);
      data->save = data->c;
      if (!(str = stock_next(data, count_y, data->c, str)))
	return (-1);
      data->c = data->save;
      data->i = 0;
      while (data->array[count_y][data->c] &&
             data->array[count_y][data->c] != ' ' &&
             data->array[count_y][data->c] != '\t')
        {
          if (data->array[count_y][data->c] != ',')
	    str[data->i++] = data->array[count_y][data->c];
	  data->c++;
        }
      str[data->i] = 0;
      data->array_cor[y][*count_x] = my_getnbr(str);
      (*count_x)++;
      free(str);
    }
  return (0);
}
