/*
** base_next.c for next in /home/barbe_j/rendu/CPE_2015_corewar
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Tue Aug  2 18:49:31 2016 jordan barbé
** Last update Mon Sep  5 18:51:10 2016 jordan barbé
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

static void	my_check(char *str, int *cpt, int *compt)
{
  while (str[*cpt] == '+' || str[*cpt] == '-')
    {
      if (str[*cpt] == '-')
        *compt = *compt + 1;
      *cpt = *cpt + 1;
    }
}

int	my_getnbr(char *str)
{
  long	result;
  int	cpt;
  int	compt;

  compt = 0;
  result = 0;
  cpt = 0;
  my_check(str, &cpt, &compt);
  while (str[cpt] && str[cpt] >= '0' && str[cpt] <= '9')
    {
      result = (result * 10) + (str[cpt] - 48);
      if ((result > 2147483647 && !(compt % 2 == 1)) ||
          (result > 2147483648 && (compt % 2 == 1)))
        return (0);
      cpt = cpt + 1;
    }
  if (compt % 2 == 1)
    result = result * -1;
  return (result);
}

int		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (-1);
}

char		*my_strdup(char *str)
{
  char		*save;

  if ((save = malloc(my_strlen(str) + 1)) == 0)
    return (0);
  save = my_strcpy(save, str);
  return (save);
}

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
