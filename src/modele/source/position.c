/**
 * \file      position.c
 * \author    Geliot
 * \version   1.0
 * \date      25 Novembre 2014
 * \brief     Définit les fonctions pour les positions des pions
 *            
 */

// ############################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <position.h>
// ############################

Position position_init(int x, int y)
{
	Position position;

	position.x=x;
	position.y=y;
	position.marque = 0;

	return position;
}

