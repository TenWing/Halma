

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
#define Taille_plateau 16;

//Inclusion des éléments nécessaires à notre structure
#include <matrice.h>

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

/**
 * \brief    Génère le plateau de jeu
 * \details  Permet de créer le plateau de jeu à partir des fonctions de la librairie matrice
 *             
 * \param    Plateau plateau
 * \return   Le plateau de jeu
 */
Plateau plateau_init(Plateau plateau);

 #endif