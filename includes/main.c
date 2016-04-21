#include "header.h"

int		main(int argc, char **argv)
{
	t_game		game;

	if (check_argv(argc, argv) && check_map(argv, &game))
	{
		init_game(&game, argv);
		solve(&game);
	}
	return (0);
}