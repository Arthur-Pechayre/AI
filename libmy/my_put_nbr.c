/*
** my_put_nbr.c for my_put_nbr in /home/elbouc_w/elbouc_w/my_put_nbr
** 
** Made by EL BOUCHIKHI Walid
** Login   <elbouc_w@etna-alternance.net>
** 
** Started on  Fri Oct  2 13:42:51 2015 EL BOUCHIKHI Walid
** Last update Fri Oct  2 21:52:50 2015 EL BOUCHIKHI Walid
*/

#include <unistd.h>
void	my_putchar(char c);
void	bornenegatif(int nb)
{
  if (nb == -2147483648)
    {
      write(1, "2147483648", 10);
    }
}
void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      if ((nb >= 0) && (nb < 10))
	{
	  my_putchar(nb + 48);
	}
      else if (nb >= 10)
	{
	  my_put_nbr(nb / 10);
	  my_put_nbr(nb % 10);
	}
      bornenegatif(nb);
    }
  else if ((nb >= 0) && (nb < 10))
    {
      my_putchar(nb + 48);
    }
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
}
