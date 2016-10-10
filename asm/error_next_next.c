/*
** error_next_next.c for next in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Sat Aug 27 16:44:10 2016 jordan barbé
** Last update Sat Aug 27 23:34:56 2016 Tahery Alexandre
*/

#include "asm.h"

int     or_err(t_data *data, int i)
{
  return (print_err_or_xor(data, i, ARG_OR));
}

int     xor_err(t_data *data, int i)
{
  return (print_err_or_xor(data, i, ARG_XOR));
}

int     ldi_err(t_data *data, int i)
{
  return (print_err_or_xor(data, i, ARG_LDI));
}

int     sub_err(t_data *data, int i)
{
  return (print_err_full_r(data, i, ARG_SUB));
}

int	zjmp_err(t_data *data, int i)
{
  if (data->array_cor[i][1] < 0)
    {
      my_puterror(ARG_ZJMP);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}
