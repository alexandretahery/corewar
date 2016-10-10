/*
** init_struct.c for init in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Tue Aug 23 19:55:14 2016 jordan barbé
** Last update Fri Sep  9 17:06:58 2016 Tahery Alexandre
*/

#include <stdlib.h>
#include "asm.h"

void     init_struct(t_data *data)
{
  data->in.i = 0;
  data->in.name = NULL;
  data->in.str = NULL;
  data->octet = 0;
  while (data->in.i != PROG_NAME_LENGTH + 8)
    {
      data->head.prog_name[data->in.i] = 0;
      data->in.i++;
    }
  data->in.i = 0;
  while (data->in.i != COMMENT_LENGTH + 4)
    {
      data->head.comment[data->in.i] = 0;
      data->in.i++;
    }
  data->in.i = 0;
}
