/*
** process.c for process in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Tue Aug 23 20:10:40 2016 jordan barbé
** Last update Sun Aug 28 20:32:54 2016 jordan barbé
*/

#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "op.h"

static char	*check_name_comment(t_data *data,
				    char *check, int y, char c)
{
  static int	count = 0;

  while ((data->array[y][count] == ' ' ||
  	 data->array[y][count] == '\t') && data->array[y][count])
    count++;
  if (data->array[y][count] == '"')
    {
      count++;
      if (!(data->in.str = the_strdup(&data->array[y][count], c)))
	return (NULL);
      data->in.str[my_strlen(data->in.str) - 1] = '\0';
      count = 0;
    }
  else if (data->array[y][count] == '.')
    {
      if (!(data->in.str = the_strdup(&data->array[y][count], c)))
	return (NULL);
      if (my_strcmp(data->in.str, check) != 0)
	return (NULL);
      count += my_strlen(check);
      return ("ok");
    }
  else
    return (NULL);
  return (data->in.str);
}

static void	enter_head(t_data *in)
{
  int		i;

  i = 0;
  while (in->in.name[i])
    {
      in->head.prog_name[i] = in->in.name[i];
      i++;
    }
  while (i != PROG_NAME_LENGTH + 1)
    {
      in->head.prog_name[i] = 0;
      i++;
    }
  i = 0;
  while (in->in.comment[i])
    {
      in->head.comment[i] = in->in.comment[i];
      i++;
    }
  while (i != COMMENT_LENGTH + 1)
    {
      in->head.comment[i] = 0;
      i++;
    }
}

int		process(t_data *data, char *argv)
{
  if (!(check_name_comment(data, NAME_CMD_STRING, 0, 'e'))
      || !(data->in.name = check_name_comment(data, "ok", 0, '"'))
      || !(check_name_comment(data, COMMENT_CMD_STRING, 1, 't'))
      || !(data->in.comment = check_name_comment(data, "ok", 1, '"')))
    return (-1);
  enter_head(data);
  if (!(data->argv = my_strdup(argv)))
    return (-1);
  if (coreheader(data))
    return (-1);
  if (core_main(data))
    return (-1);
  return (0);
}
