/*
** compt_octet.c for compt in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Aug 25 15:04:56 2016 jordan barbé
** Last update Mon Sep  5 18:55:09 2016 jordan barbé
*/

#include "asm.h"

void		count_octet(int **tab, t_data *data)
{
  static int   	save = 0;
  static int	c = 0;

  if (tab[c][0] == 1 ||
      tab[c][0] == 3 ||
      tab[c][0] == 4 ||
      tab[c][0] == 5 ||
      tab[c][0] == 7 ||
      tab[c][0] == 13)
    save = 5 + save;
  else if (tab[c][0] == 2 ||
	   tab[c][0] == 10 ||
	   tab[c][0] == 11)
    save = 7 + save;
  else if (tab[c][0] == 9 ||
	   tab[c][0] == 12 ||
	   tab[c][0] == 16)
    save = 3 + save;
  else
    save = 8 + save;
  c++;
  data->octet = save;
}
