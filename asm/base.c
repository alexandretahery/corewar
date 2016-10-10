/*
** base.c for corwar in /home/tahery_b/rendu/CPE/CPE_2015_corewar
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Mon Aug  1 18:19:15 2016 Tahery Alexandre
** Last update Sun Aug 28 20:19:10 2016 jordan barbé
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	c;

  i = my_strlen(s1);
  c = my_strlen(s2);
  if (i != c)
    return (1);
  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] == s2[i])
	i++;
      else
	return (1);
    }
  return (0);
}

char		*my_strcat(char *str1, char *str2)
{
  int		i;
  int		y;
  char		*str;

  i = my_strlen(str1) + my_strlen(str2);
  if ((str = malloc(sizeof(char) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  y = 0;
  while (str1[i] != '\0')
    {
      str[i] = str1[i];
      i++;
    }
  while (str2[y] != '\0')
    {
      str[i] = str2[y];
      i++;
      y++;
    }
  str[i] = '\0';
  free(str1);
  return (str);
}
