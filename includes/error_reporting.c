#include "header.h"

int		error_reporting(void (*f)())
{
	f();
	return (1);
}

void 	error_reporting_argc()
{
	my_putstr("Arguments mauvais, voir l'usage ci-dessous\n");
	my_putstr("Usage: ./solve [PV] [PV_RSR] [map]\n");
	my_putstr("[PV] : Les PVs initiaux\n");
	my_putstr("[PV_RSR] : Les PVs des ressources\n");
	my_putstr("[map] : La map à charger (doit être correct)\n");
}

void 	error_reporting_pv_rsr()
{
	my_putstr("[PV] et [PV_RSR] mauvaises\n");
	my_putstr("Les PV doivent être strictement supérieur à 0\n");
	my_putstr("Les PV_RSR doivent être supérieur ou égal à 0\n");
}

void 	error_reporting_not_int()
{
	my_putstr("Merci de bien vouloir entrer ");
	my_putstr("des entiers pour les PV et PV_RSR\n");
}

void 	error_reporting_map_null()
{
	my_putstr("La map entrée en paramètre est incorrect\n");
	my_putstr("Seul des '+', '@', '#' et ' ' doivent être présents.\n");
	my_putstr("Le joueur est symbolisé par '@', il peut ");
	my_putstr("donc y avoir qu'un seul '@'\n");
	my_putstr("L'arrivée est symbolisée par '#', il peut ");
	my_putstr("donc y avoir qu'une seule '#'\n");
}