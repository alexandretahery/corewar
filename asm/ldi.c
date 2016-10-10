/*
** ldi.c for corewar in /home/tahery_b/rendu/CPE/CPE_2015_corewar/v2
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Fri Aug 26 04:42:53 2016 Tahery Alexandre
** Last update Sun Aug 28 20:27:47 2016 jordan barbé
*/

#include <unistd.h>
#include "asm.h"

int			ldi(t_data *in, int check)
{
  unsigned char		r;

  r = 0xa4;
  write(in->fd, &r, sizeof(char));
  write_fork(in, check);
  return (0);
}

int		lldi(t_data *in, int check)
{
  *in = *in;
  check = 0;
  if (check == 0)
    return (0);
  return (0);
}

int		zjmp(t_data *in, int check)
{
  write_fork(in, check);
  return (0);
}
