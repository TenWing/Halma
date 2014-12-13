/**
 * \file      direction.c
 * \author    Geliot
 * \version   1.0
 * \date      3 décembre 2014
 * \brief     Définit les fonctions pour les directions
 */

// ############################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <direction.h>
// ############################

Direction direction_souhaitee(int pave_numerique)
{
	Direction direction = ERREUR;

	switch(pave_numerique)
	{
		case 1:
			direction = BAS_GAUCHE;
			return direction;
			break;
		case 2:
			direction = BAS;
			return direction;
			break;
		case 3:
			direction = BAS_DROITE;
			return direction;
			break;
		case 4:
			direction = GAUCHE;
			return direction;
			break;
		case 6:
			direction = DROITE;
			return direction;
			break;
		case 7:
			direction = HAUT_GAUCHE;
			return direction;
			break;
		case 8:
			direction = HAUT;
			return direction;
			break;
		case 9:
			direction = HAUT_DROITE;
			return direction;
			break;
		default:
			break;
	}

	return direction;
}