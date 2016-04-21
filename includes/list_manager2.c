#include "header.h"

void 	copy_solution(t_solution* solution, t_solutions_list* solutions_list)
{
	t_solution*	cpy_solution;
	t_step* tmp;

	tmp = solution->first;
	cpy_solution = init_solution();
	while (tmp != NULL)
	{
		stack_solution(cpy_solution, tmp->curr_pv, tmp->coord);
		tmp = tmp->next;
	}
	stack_solutions(solutions_list, cpy_solution);
}

void	free_solutions(t_solutions_list* solutions_list)
{
    t_solutions*        tmp_solutions;
    t_step*             tmp_step;

    while (solutions_list->first)
    {
    	if (solutions_list->first->solution != NULL)
    	{
	        while (solutions_list->first->solution->first)
	        {
	        	tmp_step = solutions_list->first->solution->first->next;
	            free(solutions_list->first->solution->first);
	            solutions_list->first->solution->first = tmp_step;
	        }
    	}
        tmp_solutions = solutions_list->first->next;
        free(solutions_list->first);
        solutions_list->first = tmp_solutions;
    }
}

void 	free_game(t_game* game)
{
	int  	i;

	for (i = 0; i < game->map.l; ++i)
		free(game->map.map[i]);
	free(game->map.map);
	free(game->tab_rsr.rsr);

}
