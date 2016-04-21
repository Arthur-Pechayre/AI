#include "header.h"

void 	print_step(t_solution* explorer, t_game* game)
{
	t_step* tmp;
	
	tmp = explorer->first;

	my_putstr("@ (");
	my_put_nbr(game->player.coord.x);
	my_putchar(';');
	my_put_nbr(game->player.coord.y);
	my_putstr(") -> ");
	while (tmp)
	{	
		my_putstr("Rsr (");
		my_put_nbr(tmp->coord.x);
		my_putchar(';');
		my_put_nbr(tmp->coord.y);
		my_putstr(") -> ");
		tmp = tmp->next;
	}
	my_putstr("# (");
	my_put_nbr(game->finish.x);
	my_putchar(';');
	my_put_nbr(game->finish.y);
	my_putstr(")\n");
}

int     return_the_best(t_solutions_list* solutions_list, 
								int path_min, t_game *game)
{
   t_solutions*        tmp_solutions;
   t_step*             tmp_step;
   int                 count;
   int 				   i;

   i = 0;
   tmp_solutions = solutions_list->first;
   for (i = 0; tmp_solutions; i++)
   {	
	if (i < solutions_count(solutions_list))
	{
		tmp_step = tmp_solutions->solution->first;
		for (count = 0; tmp_step; count++)
		   tmp_step = tmp_step->next;
		if (count == path_min)
		{
		   print_step(tmp_solutions->solution, game);
		   return (1);
		}
	}
	tmp_solutions = tmp_solutions->next;
   }
   return (0);
}

void     find_best_sol(t_solutions_list* solutions_list, t_game *game)
{
   t_solutions*        tmp_solutions;
   t_step*             tmp_step;
   int                 count;
   int                 min;
   int 				   i;

   i = 0;
   tmp_solutions = solutions_list->first;
   for (min = 2147483647; tmp_solutions; i++)
   {
	if (i < solutions_count(solutions_list))
	{
		tmp_step = tmp_solutions->solution->first;
		for (count = 0; tmp_step; count++)
			tmp_step = tmp_step->next;
		if (count < min)
			min = count;
	}
	tmp_solutions = tmp_solutions->next;
   }
   my_putstr("\nUn des chemins le plus court comporte ");
   my_put_nbr(min);
   my_putstr(" '+'\nVoici les coordonnées des points de passage:\n");
   return_the_best(solutions_list, min, game);
}

void 	print_all_paths(t_solutions_list* solutions_list, t_game* game)
{
	t_solutions* tmp;
	
	tmp = solutions_list->first;
	my_putstr("Toutes les solutions possibles:\n\n");
	while (tmp && tmp->solution != NULL)
	{
		print_step(tmp->solution, game);
		tmp = tmp->next;
	}
	if (solutions_count(solutions_list) > 1)
		find_best_sol(solutions_list, game);
	my_putchar(10);
}
