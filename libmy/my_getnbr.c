/*
** my_getnbr.c for my_getnbr in /home/elbouc_w/elbouc_w/my_getnbr
** 
** Made by EL BOUCHIKHI Walid
** Login   <elbouc_w@etna-alternance.net>
** 
** Started on  Fri Oct  2 17:15:25 2015 EL BOUCHIKHI Walid
** Last update Wed Oct  7 13:52:28 2015 EL BOUCHIKHI Walid
*/

#include <unistd.h>
void	my_putchar(char c);
void	my_put_nbr(int nb);
void	initvar(int *i, int *l, int *entier, int *c)
{
  *i = 0;
  *c = 0;
  *l = 1;
  *entier = 0;
}
int	my_getnbr(char *str)
{
  int	i;
  int	l;
  int	entier;
  int	c;
  
  initvar(&i, &l, &entier, &c);
  while ((*(str + i) == 45) || (*(str + i) == 43))
    {
      if (*(str + i) == 45)
	c++;
      i++;
    }
  if ((*(str + i) >= 48) && (*(str + i) <= 57))
    {
      while ((*(str + i) >= 48) && (*(str + i) <= 57))
	{
	  entier = (entier * l) + (str[i] - 48);
	  l = 10;
	  i++;
	}
      if ((c % 2) != 0)
	return (entier * (-1));
      return (entier);
    }
  else
    return (0);
}
