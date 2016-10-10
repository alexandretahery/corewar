/*
** main.c for corwar in /home/tahery_b/rendu/CPE/CPE_2015_corewar
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Mon Aug 22 22:24:07 2016 Tahery Alexandre
** Last update Mon Sep  5 18:46:01 2016 jordan barbé
*/

#include <stdlib.h>
#include "asm.h"
#include "get_next_line.h"

static void	check_char(t_data *data)
{
  int		i;

  i = 0;
  while (data->array[0][i])
    i++;
  if (i >= 137)
    exit(1);
  i = 0;
  while (data->array[1][i])
    i++;
  if (i >= 2060)
    exit(1);
}

int		main(int argc, char **argv)
{
  t_data	data;

  if (argc < 2)
    return (my_puterror(USAGE));
  init_struct(&data);
  if ((reader(&data, argv[1])) == 1)
    return (1);
  if (data.lines != 1)
    {
      check_char(&data);
      if (process(&data, argv[1]) == -1)
	return (1);
      if ((corewrite(&data)))
	return (1);
    }
  return (0);
}
