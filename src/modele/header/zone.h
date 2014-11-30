
/**
 * \file      zone.h
 * \author    Quentin
 * \version   1.0
 * \date      30 novembre 2014
 * \brief     Définit la zone de victoire
 *
 * \details   Définit la zone de victoire
 */

#ifndef ZONE_H
#define ZONE_H

//######################################
//Inclusions
#include <position.h>
//######################################

/**
* \brief un noeud d'une liste de positions
* \author Quentin
* \version 1.0
*/
typedef struct NoeudPosition NoeudPosition;
struct NoeudPosition
{
	/**
	* \brief la position, valeur du noeud
	* \see Position
	*/
	Position position;

	/**
	* \brief un pointeur vers le noeud suivant
	*/
	NoeudPosition* suivant;
};

/**
* \brief Une liste de positions
* \author Quentin
* \version 1.0
* \details la liste de positions contient plusieurs noeud contenant les positions
*/
typedef struct ListePositions ListePositions;
struct ListePositions
{
	/**
	* \brief le premier noeud de la liste
	* \details structure de données de type liste
	* \see NoeudPosition
	*/
	NoeudPosition* premier;
};

/**
* \brief La zone de victoire
* \auhtor Quentin
* \version 1.0
*/
typedef struct Zone Zone;
struct Zone
{
	/**
	* \brief la liste des positions
	* \details la liste des positions pour la zone de la victoire
	* \see ListePositions
	*/
	ListePositions liste_positions;

	/**
	* \brief la couleur de la zone
	* \details la couleur des pions doit correspondre à la couleur de la zone
	* \see Couleur
	*/
	Couleur couleur_zone;
}