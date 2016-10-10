/*
** or_next.c for or_next in /home/barbe_j/rendu/CPE_2015_corewar/asm
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Mon Sep  5 19:07:43 2016 jordan barbé
** Last update Mon Sep  5 19:09:00 2016 jordan barbé
*/

#include "asm.h"

int	check_case(t_data *data, int i)
{
  if (data->array_cor[i][1] > 0 &&
      data->array_cor[i][2] > 0)
    return (3);
  else if (data->array_cor[i][1] > 0)
    return (1);
  else if (data->array_cor[i][2] > 0)
    return (2);
  return (0);
}
