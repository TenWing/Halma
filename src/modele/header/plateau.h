
/**
 * \file      plateau.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit le plateau
 * \details   Définit une matrice pour le plateau
 */

#ifndef PLATEAU_H
#define PLATEAU_H

//Inclusion des éléments nécessaires à notre structure
#include "../../../include/libMatrice/matrice.h"

/**
* \brief Le plateau où se déroule une partie
* \author Quentin
* \version 1.0
*/
typedef struct Plateau Plateau;
struct Plateau
{
	/**
	* \brief La matrice, tableau à 2 dimensions représentant le plateau physique
	* \see Matrice
	*/
 	Matrice matrice;
};

 #endif