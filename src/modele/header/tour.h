
/**
* \file		tour.h
* \author	Tendry
* \date		21 Novembre 2014
* \version	1.0
* \brief	Définition de la structure d'un tour de jeu
* \details	Un tour de jeu consiste en une pile de coups, un pion originel que le joueur déplace, ainsi que sa position de départ
			absolue avant TOUT coup.
*/

#ifndef TOUR_H
#define TOUR_H

//######################################
//Inclusions
#include <pion.h>
#include <position.h>
//######################################

/**
* \brief Un tour de jeu dans la partie
* \author Tendry
* \version 1.0
*/
typedef struct Tour Tour;
struct Tour
{
	/**
	* \brief Le pion concerné par le tour 
	* \see Pion
	*/
	Pion pion;

	/**
	* \brief la pile de coups jouée dans ce tour
	* \see Coups
	*/
	Coups coups;

	/**
	* \brief la position de départ du pion concerné au début du tour
	* \see position
	*/
	Position depart;
};

#endif