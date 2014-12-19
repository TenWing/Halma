
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
#include <zone.h>
#include <direction.h>
// ############################

Position position_init(int x, int y)
{
	Position position;

	position.x=x;
	position.y=y;
	position.marque = 0;

	return position;
}

int position_egale(Position a, Position b)
{
	if(a.x == b.x && a.y == b.y)
		return 1;

	return 0;
}

int position_dans_intervalle(Position test, Position borne, Direction direction)
{
	int i = 0;

	if(test.x != borne.x)
		return 0;

	if(direction == DROITE)
	{
		for(i = borne.y; i < 16; i++)
		{
			if(test.y == i)
				return 1;
		}
	}
	else
	{
		for(i = borne.y; i >= 0; i--)
		{
			if(test.y == i)
				return 1;
		}
	}

	return 0;
}
