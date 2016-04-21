#include "header.h"

t_solution*     init_solution()
{
    t_solution*         pile;
    t_step*         neo_elem;

    pile = malloc(sizeof(*pile));
    if ((neo_elem = malloc(sizeof(*neo_elem))) == NULL)
      return (0);
    neo_elem = NULL;
    pile->first = neo_elem;
    return (pile);
}

int    stack_solution(t_solution* pile, int curr_pv, t_coord coord)
{
    t_step*    neo_elem;

    if ((neo_elem = malloc(sizeof(*neo_elem))) == NULL)
      return (0);
    neo_elem->coord.x = coord.x;
    neo_elem->coord.y = coord.y;
    neo_elem->curr_pv = curr_pv;
    neo_elem->next = pile->first;
    pile->first = neo_elem;
    return (1);
}

t_solutions_list*     init_solutions()
{
    t_solutions_list*         pile;
    t_solutions*         first_elem;

    if ((pile = malloc(sizeof(*pile))) == NULL)
      return (0);
    if ((first_elem = malloc(sizeof(*first_elem))) == NULL)
      return (0);
    first_elem->solution = NULL;
    first_elem->next = NULL;
    pile->first = first_elem;
    return (pile);
}

int    stack_solutions(t_solutions_list* pile, t_solution* solution)
{
    t_solutions*    neo_elem;

    if ((neo_elem = malloc(sizeof(*neo_elem))) == NULL)
        return (0);
    neo_elem->solution = solution;
    neo_elem->next = pile->first;
    pile->first = neo_elem;
    return (1);
}

void    destack_solution(t_solution* solution)
{
    t_step* elem_destack;

    elem_destack = solution->first;
    if (solution != NULL && solution->first != NULL)
    {
        solution->first = elem_destack->next;
        free(elem_destack);
    }
}

