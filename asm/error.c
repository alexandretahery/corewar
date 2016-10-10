/*
** error.c for error in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Aug 27 15:13:44 2016 jordan barbé
** Last update Sat Aug 27 17:13:01 2016 jordan barbé
*/

#include "asm_error.h"
#include "asm.h"

int	ld_live_err(t_data *data, int i)
{
  if (data->array_cor[i][1] < 0)
    {
      my_puterror(ARG_LIVE);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}

int	ld_err(t_data *data, int i)
{
  if (data->array_cor[i][1] < 0)
    {
      my_puterror(ARG_LD);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  else if (data->array_cor[i][2] > 0)
    {
      my_puterror(ARG_LD);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}

int	st_err(t_data *data, int i)
{
  if (data->array_cor[i][1] > 0)
    {
      my_puterror(ARG_ST);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  else if (data->array_cor[i][2] < 0)
    {
      my_puterror(ARG_ST);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}

int	add_err(t_data *data, int i)
{
  return (print_err_full_r(data, i, ARG_ADD));
}

int	gest_err(t_data *data)
{
  int	i;
  int	check;

  i = 0;
  check = 0;
  while (i != data->lines - 2)
    {
      if (ptr_err[data->array_cor[i][0] - 1](data, i) == -1)
	check++;
      i++;
    }
  if (check > 0)
    {
      my_puterror(CHECK_ERR);
      my_putnbr(check);
      my_puterror(CHECK_ERR_NEXT);
      exit(2);
    }
  return (0);
}
