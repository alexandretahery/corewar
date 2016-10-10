/*
** arg.c for arg in /home/barbe_j/rendu/CPE_2015_corewar/v2
**
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
**
** Started on  Wed Aug 24 01:54:02 2016 jordan barbé
** Last update Mon Sep  5 18:50:57 2016 jordan barbé
*/

#include "asm.h"

static int	check_label_char(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        return (0);
      i++;
    }
  return (1);
}

static int	arg_solo(char *str)
{
  int		i;
  int		mod;

  i = 0;
  mod = 0;
  while (str[i])
    {
      if (check_label_char(LABEL_CHARS,
			   str[i]) == 0)
	i++;
      else if (str[i] == ' ' || str[i] == '\t'
	       || str[i] == ',')
	i++;
      else if (str[i] == '%')
	{
	  i++;
	  mod++;
	}
      else
	return (-1);
    }
  if (mod >= 2)
    return (-1);
  return (1);
}

static int		check_arg_next(char *str, int count,
				       int count_save, int check)
{
  int		count_comma;

  count_comma = 0;
  while (str[count] != '\0')
    {
      if (str[count] == ',')
        {
	  check = 1;
          count_comma++;
          count_save = count;
          while (str[count_save] != '\0')
            {
              if (check_label_char(LABEL_CHARS,
				   str[count_save]) == 0)
                break ;
	      count_save++;
            }
          if (str[count_save] == '\0')
	    return (-1);
        }
      count++;
    }
  if (check != 1)
    return (arg_solo(str));
  return (count_comma + 1);
}

int		check_arg(char *str, t_data *data)
{
  int		save;

  if ((save = check_arg_next(str, 0, 0, 0)) == -1)
    return (-1);
  if (save != op_tab[data->in.hexa - 1].nbr_args)
    return (-1);
  return (0);
}
