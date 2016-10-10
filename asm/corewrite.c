/*
** corewrite.c for corewrite in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Tue Aug 23 23:08:19 2016 jordan barbé
** Last update Mon Sep  5 18:58:40 2016 jordan barbé
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "op.h"
#include "asm.h"

static int	(*ptr_fnc[17])(t_data *, int) =
{
  ld_live,
  ld,
  st,
  add,
  add,
  and,
  or,
  or,
  zjmp,
  ldi,
  sti,
  write_fork,
  lld,
  lldi,
  lldi,
  aff,
  NULL
};

static void	write_nbr_magic(t_data *in)
{
  int		i;
  unsigned char	c[4];

  i = 0;
  while (i != 4)
    {
      c[i] = calc_nbr_magic(in);
      i++;
    }
  i--;
  while (i >= 0)
    {
      write(in->fd, &c[i], sizeof(char));
      i--;
    }
}

char			calc_hexa(int *nbr)
{
  int			count;
  int			result;

  result = 0;
  count = 0;
  if (*nbr < 0)
    *nbr = *nbr * - 1;
  while (count != 8 && *nbr != 0)
    {
      if (*nbr % 2 == 1)
        result = result + my_power(2, count);
      *nbr = *nbr / 2;
      count++;
    }
  return (result);
}

void			write_hexa_head(t_data *in, int check)
{
  unsigned char		c[4];
  int			i;
  int			nbr;

  nbr = in->array_cor[check][0];
  i = 0;
  while (i != 4)
    {
      c[i] = calc_hexa(&nbr);
      i++;
    }
  i = 0;
  while (i < 4)
    {
      if (c[i] != 0)
	write(in->fd, &c[i], sizeof(char));
      i++;
    }
}

int		corewrite(t_data *in)
{
  int		i;

  i = 0;
  gest_err(in);
  if (!(in->fd = open(in->file, O_CREAT | O_RDWR, S_IRUSR + S_IWUSR)))
    return (-1);
  write_nbr_magic(in);
  write(in->fd, in->head.prog_name, PROG_NAME_LENGTH + 7);
  write(in->fd, &in->octet, sizeof(char));
  write(in->fd, in->head.comment, COMMENT_LENGTH + 4);
  while (i != in->lines - 2)
    {
      write_hexa_head(in, i);
      ptr_fnc[in->array_cor[i][0] - 1](in, i);
      i++;
    }
  close(in->fd);
  return (0);
}
