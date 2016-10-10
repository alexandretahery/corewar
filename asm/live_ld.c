/*
** live_sub.c for corewar in /home/tahery_b/rendu/CPE/CPE_2015_corewar/v2
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Fri Aug 26 00:12:32 2016 Tahery Alexandre
** Last update Sun Aug 28 20:28:13 2016 jordan barbé
*/

#include <unistd.h>
#include "asm.h"

static void	ld_live_next(int i, int neg,
			     t_data *in, unsigned char *c)
{
  i = 3;
  if (neg == 1)
    write(in->fd, &c[0], sizeof(char));
  else
    while (i >= 0)
      {
	write(in->fd, &c[i], sizeof(char));
	i--;
      }
}

int		ld_live(t_data *in, int check)
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
      ld_live_next(i, neg, in, c);
      i = 0;
      x++;
    }
  return (0);
}

int		ld(t_data *in, int check)
{
  unsigned char	r;

  r = 0x90;
  write(in->fd, &r, sizeof(char));
  ld_live(in, check);
  return (0);
}
