#include "header.h"

void 	get_pos(t_game* game)
{
	int 	i;
	int 	j;

	for (i = 0; i < game->map.l; ++i)
	{
		for (j = 0; j < game->map.c; ++j)
		{
			if (game->map.map[i][j] == '@')
			{
				game->player.coord.x = i;
				game->player.coord.y = j;
			}
			else if (game->map.map[i][j] == '#')
			{
				game->finish.x = i;
				game->finish.y = j;
			}
		}
	}
}

void 		fill_tab_rsr(t_game* game)
{
	int 	i;
	int 	j;
	int 	k;

	k = 0;
	for (i = 0; i < game->map.l; ++i)
	{
		for (j = 0; j < game->map.c; ++j)
		{
			if (game->map.map[i][j] == '+')
			{
				game->tab_rsr.rsr[k].coord.x = i;
				game->tab_rsr.rsr[k].coord.y = j;
				game->tab_rsr.rsr[k++].visited = 0;
			}
		}
	}
}

int 		find_rsr(t_game* game)
{
	int 	i;
	int 	j;
	int 	count;

	count = 0;
	for (i = 0; i < game->map.l; ++i)
	{
		for (j = 0; j < game->map.c; ++j)
		{
			if (game->map.map[i][j] == '+')
				count++;
		}
	}
	game->tab_rsr.count = count;
	if ((game->tab_rsr.rsr = malloc(sizeof(t_rsr) * count)) == 0)
			return (0);
	fill_tab_rsr(game);
	return (0);
}

void		init_game(t_game* game, char** argv)
{
	game->pv_rsr = my_getnbr(argv[2]);
	game->player.pv = my_getnbr(argv[1]);
	get_pos(game);
	find_rsr(game);
}