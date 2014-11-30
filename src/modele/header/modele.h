
/**
 * \file      modele.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit les fonctions pour modeliser le jeu de l'halma
 */

#ifndef MODELE_H
#define MODELE_H

//######################################
//Inclusions
#include <plateau.h>
#include <joueur.h>
#include <tour.h>
//######################################

typedef struct Modele Modele;
struct Modele
{
	/**
	* \brief le plateau du jeu 
	* \see plateau
	*/
	Plateau plateau;

	/**
	* \brief La pile de tours
	* \see tour
	*/
	PileTours pile_tours;

	/**
	* \brief le tableau des joueurs
	* 
	*/
	Joueur tableau_joueur[4];

};

/**
* \brief	Commence un tour de jeu
* \author	Tendry
* \param	modele le modèle qui joue
* \param	pion le pion selectionné par le joueur
* \version 	1.0
*/
void commencer_tour(Modele* modele, Pion* pion);

/**
* \brief	Fini le tour de jeu
* \author	Tendry
* \param	modele le modèle qui joue
* \version 	1.0
*/
void fin_tour(Modele* modele);

#endif