#include "header.h"

int 	reachable_pos(t_game* game, t_coord pos)
{
	int my_absx;
	int my_absy;

	my_absx = my_abs(game->player.coord.x - pos.x);
	my_absy = my_abs(game->player.coord.y - pos.y);
	if (my_absx + my_absy <= game->player.pv)
		return (1);
	return (0);
}

int 	solutions_count(t_solutions_list* solutions_list)
{
	t_solutions* tmp;
	int count;

	count = 0;
	tmp = solutions_list->first;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (--count);
}

void 	result(t_solutions_list* solutions_list)
{
	if (solutions_count(solutions_list))
	{
		my_putstr("Il y'a ");
		my_put_nbr(solutions_count(solutions_list));
		my_putstr(" solutions.\nOK\n");
	}
	else
		my_putstr("KO");
}

int 	recur_testing_path(t_game* game, t_solutions_list* solutions_list,
													t_solution* explorer)
{
	int 		i;
	t_game 		game_copy;
	static int	c;

	if (reachable_pos(game, game->finish) && c++ <= 100)
		copy_solution(explorer, solutions_list);
	else
	{
		for (i = 0; i < game->tab_rsr.count; ++i)
		{
			if (!game->tab_rsr.rsr[i].visited &&
				reachable_pos(game, game->tab_rsr.rsr[i].coord))
			{
				game->tab_rsr.rsr[i].visited = 1;
				stack_solution(explorer, get_new_pv(game, i),
									 game->tab_rsr.rsr[i].coord);
				update_copy_game(&game_copy, game, i);
				copy_game(game, &game_copy);
				recur_testing_path(&game_copy, solutions_list, explorer);
				game_copy.tab_rsr.rsr[i].visited = 0;
				destack_solution(explorer);
			}
		}
	}
	return (1);
}

int		solve(t_game* game)
{
	t_solutions_list* solutions_list;
	t_solution* 	  explorer;

	solutions_list = init_solutions();
	explorer = init_solution();
	if (reachable_pos(game, game->finish))
	{
		my_putstr("OK\n");
		return (2);
	}
	else
	{
		recur_testing_path(game, solutions_list, explorer);
		if (solutions_count(solutions_list))
			print_all_paths(solutions_list, game);
	}
	result(solutions_list);
	free_solutions(solutions_list);
	free_game(game);
	return (0);
}