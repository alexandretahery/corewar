/*
** error_next.c for error_next in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Sat Aug 27 16:21:17 2016 jordan barbé
** Last update Sat Aug 27 23:36:47 2016 Tahery Alexandre
*/

#include "asm.h"

int	print_err_or_xor(t_data *data, int i, char *str)
{
  if (data->array_cor[i][3] > 0)
    {
      my_puterror(str);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}

int	print_err_full_r(t_data *data, int i, char *str)
{
  if (data->array_cor[i][1] > 0 ||
      data->array_cor[i][2] > 0 ||
      data->array_cor[i][3] > 0)
    {
      my_puterror(str);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);

}

int	and_err(t_data *data, int i)
{
  if (data->array_cor[i][3] > 0)
    {
      my_puterror(ARG_AND);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}
