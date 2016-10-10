/*
** or.c for or in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Fri Aug 26 04:12:08 2016 jordan barbé
** Last update Mon Sep  5 19:10:20 2016 jordan barbé
*/

#include <unistd.h>
#include "asm.h"

static void	mod_1(t_data *data, int i)
{
  unsigned char	c[4];
  unsigned char	c1;
  int		count;

  c1 = 0x94;
  write(data->fd, &c1, sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][1]);
  while (count-- > 0)
    write(data->fd, &c[count], sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][2]);
  count--;
  while (count-- > 0)
    if (c[count])
      write(data->fd, &c[count], sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][3]);
  count--;
  while (count-- > 0)
    if (c[count])
      write(data->fd, &c[count], sizeof(char));
}

static void	mod_2(t_data *data, int i)
{
  int		count;
  unsigned char	c[4];

  write(data->fd, "d", sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][1]);
  count--;
  while (count-- > 0)
    if (c[count])
      write(data->fd, &c[count], sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][2]);
  while (count-- > 0)
    write(data->fd, &c[count], sizeof(char));
  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][3]);
  count--;
  while (count-- > 0)
    if (c[count])
      write(data->fd, &c[count], sizeof(char));
}

static void	write_mod3(int count, t_data *data,
			   int i, int cpt)
{
  unsigned char	c[4];

  count = 0;
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][cpt]);
  while (count-- > 0)
    write(data->fd, &c[count], sizeof(char));
}

static void	mod_3(t_data *data, int i)
{
  int		count;
  unsigned char	c[4];
  unsigned char	c1;

  c1 = 0xa4;
  write(data->fd, &c1, sizeof(char));
  count = 0;
  write_mod3(count, data, i, 1);
  write_mod3(count, data, i, 2);
  while (count != 4)
    c[count++] = calc_hexa(&data->array_cor[i][3]);
  count--;
  while (count-- > 0)
    if (c[count])
      write(data->fd, &c[count], sizeof(char));
}

int	or(t_data *data, int i)
{
  if (check_case(data, i) == 1)
    mod_1(data, i);
  else if (check_case(data, i) == 2)
    mod_2(data, i);
  else if (check_case(data, i) == 3)
    mod_3(data, i);
  else
    add(data, i);
  return (0);
}
