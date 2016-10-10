/*
** add.c for add in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Fri Aug 26 02:48:54 2016 jordan barbé
** Last update Sat Aug 27 21:25:49 2016 Tahery Alexandre
*/

#include <unistd.h>
#include "asm.h"

int		add(t_data *in, int check)
{
  write(in->fd, "T", sizeof(char));
  write_fork(in, check);
  return (0);
}
