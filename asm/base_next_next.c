/*
** base_next_next.c for next in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Tue Aug 23 20:29:48 2016 jordan barbé
** Last update Sat Aug 27 15:42:42 2016 jordan barbé
*/

#include <stdlib.h>
#include "asm.h"

int		my_power(int nb, int power)
{
  int		save;
  int		i;
  int		c;

  c = 1;
  i = 0;
  if ((nb == 0 && power == 1) || power < 0)
    return (0);
  else if (power == 0)
    return (1);
  while (i != power)
    {
      save = nb * c;
      c = c * nb;
      i = i + 1;
    }
  return (save);
}

static int	the_strlen(char *str, int c)
{
  int		i;

  i = 0;
  if (!str)
    return (i);
  while (str[i] != c && str[i])
    i++;
  return (i);
}

char	*the_strdup(char *str, char c)
{
  int	i;
  char	*new;

  i = 0;
  if (!(new = malloc(sizeof(char) * the_strlen(str, c) + 2)))
    return (NULL);
  while (str[i] != '\0' && str[i] != c)
    {
      new[i] = str[i];
      i++;
    }
  new[i] = str[i];
  i++;
  new[i] = 0;
  return (new);
}

static int	my_display_maxint()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
  return (1);
}

int		my_putnbr(int nb)
{
  if (nb > 2147483647)
    return (0);
  if (nb == -2147483648 && nb < 0)
    if (my_display_maxint() == 1)
      return (1);
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
      if (nb <= 9)
        my_putchar(nb + 48);
      else
        my_putnbr(nb);
    }
  else if (nb >= 10)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (0);
}
