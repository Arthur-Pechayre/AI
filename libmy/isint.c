#include "libmy.h"

int		isint(char *str)
{
	int 	i;

	i = 0;
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}