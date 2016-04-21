#include "header.h"

void 	copy_game(t_game *game, t_game *copy_game)
{
	copy_game->finish = game->finish;
	copy_game->tab_rsr = game->tab_rsr;
	copy_game->pv_rsr = game->pv_rsr;
	copy_game->map = game->map;
}


int 	get_new_pv(t_game *game, int i)
{
	int 	myabsx;
	int 	myabsy;

	myabsx = my_abs(game->tab_rsr.rsr[i].coord.x - game->player.coord.x);
	myabsy = my_abs(game->tab_rsr.rsr[i].coord.y - game->player.coord.y);
	return (game->player.pv - (myabsx + myabsy) + game->pv_rsr);
}

void 	update_copy_game(t_game *copy_game, t_game *game, int i)
{
	copy_game->player.coord = game->tab_rsr.rsr[i].coord;
	copy_game->player.pv = get_new_pv(game, i);
}