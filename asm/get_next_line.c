/*
** get_next_line.c for get_next_line in /home/barbe_j/rendu/CPE_2015_Allum1
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Tue Jul 19 16:46:21 2016 jordan barbé
** Last update Sat Aug 27 23:27:54 2016 Tahery Alexandre
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*my_realloc(char *ptr, size_t size)
{
  char	*temp;
  int	i;

  temp = ptr;
  if (!(ptr = malloc(size)))
    return (NULL);
  i = -1;
  while (temp[++i])
    ptr[i] = temp[i];
  free(temp);
  return (ptr);
}

char		get_char(const int fd)
{
  static int	i = 0;
  static char	buff[BUFFER_SIZE];
  static char	*ptr_buff;
  char		c;

  if (i == 0)
    {
      if (!(i = read(fd, buff, BUFFER_SIZE)))
	return (0);
      ptr_buff = (char*)&buff;
    }
  c = *ptr_buff;
  i--;
  ptr_buff++;
  return (c);
}

char	*get_next_line(const int fd)
{
  char	c;
  char	*str;
  int	len;

  len = 0;
  if (!(str = malloc(BUFFER_SIZE + 1)))
    return (0);
  c = get_char(fd);
  while (c != ENTER && c != '\0')
    {
      str[len] = c;
      c = get_char(fd);
      len++;
      if (len % (BUFFER_SIZE + 1) == 0)
	str = my_realloc(str, len + BUFFER_SIZE + 1);
    }
  str[len] = 0;
  if (c == 0 && str[0] == 0)
    return (0);
  return (str);
}
