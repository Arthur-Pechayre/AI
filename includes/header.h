#ifndef		__HEADER_H__
# define 	__HEADER_H__

/*** INCLUDE ***/

#include	<unistd.h>
#include	<stdlib.h>
#include 	<stdio.h>
#include 	<fcntl.h>
#include 	"../libmy/libmy.h"

/*** Structures ***/

typedef struct 	s_coord
{
	int			x;
	int			y;
}			   	t_coord;

typedef struct 	s_rsr
{
	t_coord		coord;
	int			visited;
}			   	t_rsr;

typedef struct 	s_tab_rsr
{
	t_rsr		*rsr;
	int 		count;
}				t_tab_rsr;

typedef struct 	s_player
{
	t_coord		coord;
	int			pv;
}			   	t_player;

typedef struct 	s_step
{
	int				curr_pv;
	t_coord			coord;
	struct s_step	*next;
}				t_step;

typedef struct 	s_solution
{
	t_step  	*first;
}				t_solution;

typedef struct 	s_solutions
{
	t_solution 				*solution;
	struct s_solutions 		*next;
}							t_solutions;

typedef struct s_solutions_list
{
	t_solutions 		*first;
} 			t_solutions_list;

typedef struct 	s_map
{
	char 		**map;
	int			c;
	int 		l;
}				t_map;


typedef struct 	s_game
{
	t_player	player;
	t_coord		finish;
	t_tab_rsr	tab_rsr;
	int 		pv_rsr;
	t_map		map;
}			   	t_game;

/*** Prototypes ***/

/*** Error Reporting ***/
int		error_reporting(void (*f)());
void 	error_reporting_argc();
void 	error_reporting_pv_rsr();
void 	error_reporting_not_int();
void 	error_reporting_map_null();
void 	multi_start_or_finish();

/*** Verification ***/
int 	check_argv(int argc, char** argv);
int 	check_map(char **argv, t_game *game);

/*** Main Solveur ***/
int		solve(t_game *game);

/*** Copy game ***/
void 	copy_game(t_game *game, t_game *copy_game);
void 	update_copy_game(t_game *copy_game, t_game *game, int i);
int 	get_new_pv(t_game *game, int i);

/*** Initialisation ***/
void 					init_game(t_game *game, char **argv);
t_solutions_list 		*init_solutions();
t_solution   			*init_solution();

/*** Push List ***/
int 	stack_solution(t_solution *pile, int curr_pv, t_coord coord);
int   	stack_solutions(t_solutions_list *pile, t_solution *solution);
void    destack_solution(t_solution *solution);
void 	copy_solution(t_solution *solution, t_solutions_list *solutions_list);

/*** Print ***/
void 	print_step(t_solution *explorer, t_game *game);
void 	print_all_paths(t_solutions_list *solutions_list, t_game *game);
int 	solutions_count(t_solutions_list* solutions_list);

/*** Free ***/
void     free_solutions(t_solutions_list *solutions_list);
void 	free_game(t_game *game);


#endif