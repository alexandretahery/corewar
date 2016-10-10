/*
** st.c for st.c in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Fri Aug 26 01:06:03 2016 jordan barbé
** Last update Sat Aug 27 22:15:49 2016 Tahery Alexandre
*/

#include <unistd.h>
#include "asm.h"

int		st(t_data *data, int i)
{
  write(data->fd, "p", sizeof(char));
  write_fork(data, i);
  return (0);
}
