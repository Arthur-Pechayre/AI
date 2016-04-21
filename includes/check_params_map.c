#include "header.h"

int		check_argv(int argc, char **argv)
{
	if (argc != 4)
	{
		error_reporting(&error_reporting_argc);
		return (0);
	}
	else if (isint(argv[1]) && isint(argv[2]))
	{
		if ((my_getnbr(argv[1]) <= 0) ||
		(my_getnbr(argv[2]) < 0))
		{
			error_reporting(&error_reporting_pv_rsr);
			return (0);
		}
	}
	else
	{
		error_reporting(&error_reporting_not_int);
		return (0);
	}
	return (1);
}