/*
** check_2.c for corewar in /home/tahery_b/rendu/CPE/CPE_2015_corewar/v2
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Sat Aug 27 23:56:26 2016 Tahery Alexandre
** Last update Mon Sep  5 18:54:46 2016 jordan barbé
*/

#include "asm.h"

char			calc_nbr_magic(t_data *in)
{
  int			count;
  int			result;

  result = 0;
  count = 0;
  while (count != 8 && in->head.magic != 0)
    {
      if (in->head.magic % 2 == 1)
        result = result + my_power(2, count);
      in->head.magic = in->head.magic / 2;
      count++;
    }
  return (result);
}

int		check_2(char *str, int i)
{
  if (str[0] != '\0' && str[0] != '\n')
    {
      if (str[0] == ' ' || str[0] == '\t')
	{
	  i = 0;
	  while ((str[i] == ' ' || str[i] == '\t') && str[i])
	    i++;
	}
    }
  return (i);
}
