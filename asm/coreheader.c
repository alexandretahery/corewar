/*
** coreheader.c for corwar in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Tue Aug 23 22:39:05 2016 jordan barbé
** Last update Mon Sep  5 18:56:09 2016 jordan barbé
*/

#include <stdlib.h>
#include "asm.h"

static char	*convert_cor_next(t_data *in)
{
  int		i;
  char		*name;

  i = my_strlen(in->argv);
  if (!(name = malloc(sizeof(char) * i + 1)))
    return (NULL);
  i = 0;
  while (in->argv[i])
    {
      name[i] = in->argv[i];
      i++;
    }
  name[i] = 0;
  if (!(name = my_strcat(name, ".cor")))
    return (NULL);
  return (name);
}

static void	regulate(t_data *data)
{
  int		i;

  i = my_strlen(data->argv);
  while (i != 0 && data->argv[i] != '/')
      i--;
  if (i != 0)
    data->argv = &data->argv[i + 1];
}

static char	*convert_cor(t_data *in)
{
  int		i;
  int		c;
  char		ext[3];
  char		*name;

  i = my_strlen(in->argv);
  c = -1;
  regulate(in);
  while (i != 0)
    i--;
  if (!(name = malloc(sizeof(char) * i + 1)))
    return (NULL);
  i = -1;
  while (in->argv[++i] != '.')
    name[i] = in->argv[i];
  name[i] = 0;
  while (++c != 2)
    ext[c] = in->argv[i++];
  ext[c] = 0;
  if (!(my_strcmp(ext, ".s")))
    return (my_strcat(name, ".cor"));
  else
    return (convert_cor_next(in));
}

int	coreheader(t_data *in)
{
  in->head.magic = COREWAR_EXEC_MAGIC;
  if (!(in->file = convert_cor(in)))
    return (-1);
  return (0);
}
