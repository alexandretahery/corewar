/*
** core_main.c for main in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Wed Aug 24 00:10:02 2016 jordan barbé
** Last update Sun Aug 28 20:21:06 2016 jordan barbé
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int	remove_space_tab(char *str, int i)
{
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  return (i);
}

static int	check_nemo(t_data *data, int y)
{
  int		i;
  int		comp;
  char		*str;

  comp = 0;
  i = remove_space_tab(data->array[y], 0);
  if ((str = the_strdup(&data->array[y][i], ' ')) != NULL)
    {
      str[my_strlen(str) - 1] = '\0';
      while (comp != 16)
	{
	  if (my_strcmp(str, op_tab[comp].mnemonique) == 0)
	    {
	      data->in.hexa = comp + 1;
	      return (0);
	    }
	  comp++;
	}
      return (-1);
    }
  else
    return (-1);
  return (0);
}

static int	malloc_array_cor(t_data *data, int y)
{
  int		i;

  i = 1;
  if (!(data->array_cor[y] = malloc(sizeof(int) *
				    op_tab[data->in.hexa - 1]
				    .nbr_args * 2)))
    return (-1);
  data->array_cor[y][0] = data->in.hexa;
  while (i != op_tab[data->in.hexa - 1].nbr_args)
    {
      data->array_cor[y][i] = 0;
      i++;
    }
  return (0);
}

int		core_main(t_data *data)
{
  int		count_y;
  int		count_x;
  int		y;

  count_y = 2;
  y = 0;
  count_x = 1;
  if (!(data->array_cor = malloc(sizeof(int *)
				 * data->lines - 2)))
    return (-1);
  while (count_y != data->lines)
    {
      if (check_nemo(data, count_y) == -1)
	return (my_puterror(ERROR_MNEMO));
      if (malloc_array_cor(data, y) == -1)
	return (my_puterror(ERROR_MALLOC));
      if (check_arg(data->array[count_y], data) == -1)
	return (my_puterror(ERROR_NBR_ARG));
      if (stock_in_my_array(data, y++, count_y, &count_x) == -1)
	return (my_puterror(ERROR_MALLOC));
      count_octet(data->array_cor, data);
      count_x = 1;
      count_y++;
    }
  return (0);
}
