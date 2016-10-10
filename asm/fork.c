/*
** fork.c for corewar in /home/tahery_b/rendu/CPE/CPE_2015_corewar/v2
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Fri Aug 26 03:08:12 2016 Tahery Alexandre
** Last update Mon Sep  5 19:01:38 2016 jordan barbé
*/

#include <unistd.h>
#include "asm.h"

static void	write_fork_next(int i, int neg,
				t_data *in, unsigned char *c)
{
  int		count;

  count = 0;
  i = 1;
  if (neg == 1)
    write(in->fd, &c[0], sizeof(char));
  else
    while (i >= 0)
      {
	if (count < 2)
	  write(in->fd, &c[i], sizeof(char));
	i--;
	count++;
      }
}

int		write_fork(t_data *in, int check)
{
  unsigned char	c[4];
  int		i;
  int		x;
  int		end;
  int		neg;

  i = 0;
  x = 1;
  end = op_tab[in->array_cor[check][0] - 1].nbr_args;
  while (x <= end)
    {
      neg = 0;
      while (i != 4)
	{
	  if (in->array_cor[check][x] < 0)
	    neg += 1;
	  if (in->array_cor[check][x] <= -17)
	    return (my_puterror(SUP_REG));
	  c[i++] = calc_hexa(&in->array_cor[check][x]);
	}
      write_fork_next(i, neg, in, c);
      i = 0;
      x++;
    }
  return (0);
}
