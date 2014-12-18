



/**
* \file		tour.h
* \author	Tendry
* \date		21 Novembre 2014
* \version	1.0
* \brief	Définition de la structure d'un tour de jeu
* \details	Un tour de jeu consiste en une pile de tours, un pion originel que le joueur déplace, ainsi que sa position de départ
			absolue avant TOUT coup.
*/

#ifndef TOUR_H
#define TOUR_H

//######################################
//Inclusions
#include <pion.h>
#include <position.h>
#include <coup.h>
//######################################

typedef struct Modele Modele;
struct Modele;

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
	Pion* pion;

	/**
	* \brief la position de départ du pion concerné au début du tour
	* \see position
	*/
	Position depart;

	/**
	* \brief la pile de coups faite pendant le tour
	* \see tour
	*/
	PileCoups pile_coups;
};

/**
* \brief un noeud d'une pile de tours
* \author Tendry
* \version 1.0
*/
typedef struct NoeudTour NoeudTour;
struct NoeudTour
{
	/**
	* \brief le tour, valeur du noeud
	* \see Tour
	*/
	Tour tour;

	/**
	* \brief un pointeur vers le noeud suivant
	*/
	NoeudTour* suivant;
};

/**
* \brief Une pile de tours
* \author Tendry
* \version 1.0
* \details la pile de tours contient plusieurs noeud contenant les tours
*/
typedef struct PileTours PileTours;
struct PileTours
{
	/**
	* \brief le premier noeud de la pile
	* \details structure de données de type pile
	* \see NoeudTour
	*/
	NoeudTour* premier;
};

//######################################
//FONCTIONS TOUR
//######################################

/**
* \brief initialise un tour
* \author Tendry
* \version 1.0
* \param p le pion qui concerne le tour
* \return renvoie un Tour bien initialisé
*/
Tour tour_init(Pion* p);

/**
* \brief renvoie une copie du tour
* \author	Tendry
* \param	tour le tout copié
* \return	le tour copie
*/
Tour tour_copier(Tour tour);

//######################################
//FONCTIONS PILE TOURS
//######################################

/**
* \brief initialise une pile de tours
* \author Tendry
* \version 1.0
* \return Une pile de tourss initialisée
*/
PileTours pileTours_init();

/**
* \brief dépile le dernier élément des tours
* \author Tendry
* \version 1.0
* \param pile la pile de tours
* \return Le tour en haut de la pile
*/
Tour pileTours_depiler(PileTours* pile);

/**
* \brief ajoute un coup en haut de la pile
* \author Tendry
* \version 1.0
* \param pile la pile de tours
* \param coup le tour à ajouter
*/
void pileTours_ajouterTour(PileTours* pile, Tour tour);

/**
* \brief	Copie une pile de tours
* \author	Tendry
* \version	1.0
* \return	PileTours la copie de la pile de tours
*/
PileTours pileTours_copier(PileTours* pile);

/**
* \brief 	sauvegarde un tour
* \author 	Quentin
* \version 1.0
* \param 	tour 	le tour a sauvegarder
* \param 	emplacement_fichier_sauvegarde
*/
void sauvegardeTour(Tour tour, FILE* emplacement_fichier_sauvegarde);

/**
* \brief 	charge un tour
* \author 	Quentin
* \version 1.0
* \param 	emplacement_fichier_sauvegarde
* \return	le tour chargé
*/
Tour chargerTour(FILE* emplacement_fichier, Modele* modele);

/**
* \brief 	inverse une pile
* \author 	Quentin
* \version 1.0
* \param 	pile_tours 	la pile à inverser
* \return	la pile inversée
*/
PileTours inversePile(PileTours pile_tours);
#endif