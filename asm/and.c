/*
** and.c for and in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Fri Aug 26 03:31:50 2016 jordan barbé
** Last update Mon Sep  5 18:47:24 2016 jordan barbé
*/

#include <unistd.h>
#include "asm.h"

static void	write_and(t_data *data, int i)
{
  int		count;
  unsigned char	c[4];

  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][1]);
  count--;
  while (count-- >= 0)
    if (c[count])
      write(data->fd, &c[count], sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][2]);
  count--;
  while (count >= 0)
    write(data->fd, &c[count--], sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][3]);
  count--;
  while (count-- >= 0)
    if (c[count])
      write(data->fd, &c[count], sizeof(char));
}

int		and(t_data *data, int i)
{
  int		r;

  r = 0x94;
  if (data->array_cor[i][1] < 0 && data->array_cor[i][2] >= 0)
    {
      write(data->fd, "d", sizeof(char));
      write_and(data, i);
      return (0);
    }
  else if (i != data->lines - 2)
    write(data->fd, &r, 1);
  ld_live(data, i);
  return (0);
}
