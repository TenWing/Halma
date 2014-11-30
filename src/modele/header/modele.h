
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
* \brief 	initialise le modèle
* \author 	Tendry
* \param	nombreJoueurs le nombre de joueurs dans le modèle
* \version	1.0
*/
Modele modele_init(int nombreJoueurs);

/**
* \brief	Commence un tour de jeu
* \author	Tendry
* \param	modele le modèle qui joue
* \param	pion le pion selectionné par le joueur
* \version 	1.0
*/
void commencer_tour(Modele* modele, Pion* pion);

/**
* \brief	Annule un coup dans le modèle
* \author	Tendry
* \param	modele le modèle qui est modifié
* \param	pion le pion qui sera modifié
* \version	1.0
*/
void annuler_coup(Modele* modele, Pion* pion);

/**
* \brief	Annule un tour dans le modèle
* \author	Tendry
* \param	modele le modèle qui est modifié
* \param	pion le pion qui sera modifié
* \version	1.0
*/
void annuler_tour(Modele* modele, Pion* pion);

/**
* \brief 	Joue un coup, cad fait un déplacement
* \author 	Tendry
* \param	modele le modele qui sera modifié
* \param	pion le pion qui va se déplacer
* \param	direction la direction de déplacement du pion
* \return	1 coup a pu être joué 0 coup n'a pas pu
*/
int jouer_coup(Modele* modele, Pion* pion, Direction direction);

#endif