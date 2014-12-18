
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
#include <zone.h>
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
	* \brief Le nombre de joueurs
	*/
	int nombreJoueurs;

	/**
	* \brief le nombre d'IA dans le jeu
	*/
	int nombreIA;

	/**
	* \brief le tableau des joueurs
	* 
	*/
	Joueur tableau_joueur[4];

	/**
	* \brief les zones de victoire
	* 
	*/
	Zone tableau_zone[4];

	/**
	* \brief le numéro du joueur qui joue son tour
	*/
	int joueurJoue;
};

/**
* \brief 	initialise le modèle
* \author 	Tendry
* \param	nombreJoueurs le nombre de joueurs dans le modèle
* \param	nombreIA le nombre de joueurs IA
* \param	charge indique si le modèle se charge
* \version	1.0
*/
Modele modele_init(int nombreJoueurs, int nombreIA, int charge);

/**
* \brief	Commence un tour de jeu
* \author	Tendry
* \param	modele le modèle qui joue
* \param	pion le pion selectionné par le joueur
* \version 	1.0
*/
void commencer_tour(Modele* modele, Pion* pion);

/**
* \brief 	Finit un tour de jeu
* \param	pion le pion modifié
* \author	Tendry
*/
void fin_tour(Pion** pion);

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
void annuler_tour(Modele* modele);

/**
* \brief 	Joue un coup, cad fait un déplacement
* \author 	Tendry
* \param	modele le modele qui sera modifié
* \param	pion le pion qui va se déplacer
* \param	direction la direction de déplacement du pion
* \return	1 coup a pu être joué 0 coup n'a pas pu
*/
int jouer_coup(Modele* modele, Pion* pion, Direction direction);

/**
* \brief 	Sauvegarde le modele
* \author 	Quentin
* \param	modele le modele qui sera sauvegardé
* \param	FILE* 	le fichier où sont sauvegardé les tours, pions etc
* \param	char* 	le fichier où est enregistré le plateau
*/
void sauvegarderModele(Modele* modele, FILE* emplacement_fichier_sauvegarde);

/**
* \brief 	charge le modele
* \author 	Quentin
* \param	FILE* 	le fichier où sont sauvegardé les tours, pions etc
* \param	char* 	le fichier où est enregistré le plateau
* \return 	le modele
*/
Pion* modele_get_reference_pion(Modele* modele, Pion pion);

/**
* \brief 	charge les tours
* \author 	Quentin
* \param	FILE* 	le fichier où sont sauvegardé les tours, pions etc
* \param	Modele* le modele du jeu
*/
void charger_tours(FILE* fp, Modele* modele);

#endif