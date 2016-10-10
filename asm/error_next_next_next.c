/*
** error_next_next_next.c for next in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Aug 27 16:55:47 2016 jordan barbé
** Last update Sat Aug 27 23:29:40 2016 Tahery Alexandre
*/

#include "asm.h"

int	sti_err(t_data *data, int i)
{
  if (data->array_cor[i][1] > 0)
    {
      my_puterror(ARG_STI);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}

int	fork_err(t_data *data, int i)
{
  if (data->array_cor[i][1] < 0)
    {
      my_puterror(ARG_FORK);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}

int	lld_err(t_data *data, int i)
{
  if (data->array_cor[i][1] < 0)
    {
      my_puterror(ARG_LLD);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  else if (data->array_cor[i][2] > 0)
    {
      my_puterror(ARG_LLD);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}

int	lldi_err(t_data *in, int i)
{
  (void)in;
  (void)i;
  return (0);
}

int	aff_err(t_data *data, int i)
{
  if (data->array_cor[i][1] > 0)
    {
      my_puterror(ARG_AFF);
      my_putnbr(i + 3);
      my_putchar('\n');
      return (-1);
    }
  return (0);
}
