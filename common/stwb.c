/*
** stwb.c for ftp in /home/rutiyu/Epitech_second_year/unix_system/PSU_2016_myftp/srcs
**
** Made by Pierre Hay
** Login   <rutiyu@epitech.net>
**
** Started on  Mon May 15 10:29:53 2017 Pierre Hay
** Last update Wed Jun  7 14:36:35 2017 Salim Habchi
*/

#include <stdbool.h>
#include <stdlib.h>

bool	separator(char to_check)
{
  return (to_check == ' ' || to_check == '\t' ? true : false);
}

int	count_words(char *str, bool (*separator)(char))
{
  int	words;

  words = 0;
  while (*str)
    {
      if (!(*separator)(*str))
	{
	  while (*str && !(*separator)(*str))
	    ++str;
	  words += 1;
	}
      else
	++str;
    }
  return (words);
}

char	**my_str_to_wordtab(char *str, bool (*separator)(char))
{
  char	**tab;
  int	y;
  int	size;

  size = count_words(str, separator);
  if (!(tab = malloc(sizeof(char *) * (size + 1))))
    return (NULL);
  y = 0;
  while (y < size)
    {
      if (!(*separator)(*str))
	{
	  tab[y++] = str;
	  while (*str && !(*separator)(*str))
	    ++str;
	  *str = 0;
	  ++str;
	}
      else
	++str;
    }
  tab[y] = NULL;
  return (tab);
}
