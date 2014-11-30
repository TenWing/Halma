
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
#include <couleur.h>
#include <joueur.h>
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
	* \details la couleur des pions doit correspondre à la couleur de la zone, car la couleur correspond 
			   à la couleur de victoire du joueur qui arrive dans cette zone (le joueur jaune doit aller dans la zone jaune)
	* \see Couleur
	*/
	Couleur couleur_zone;

	/**
	* \brief la direction pour la vérification de la zone
	* \details La direction permet de savoir dans quel sens la fonction verification_zone doit calculer pour
				compter le nombre de pion que la zone possède
	* \see Direction
	*/
	Direction zone_direction;
};

/**
* \brief initialise la liste des positions pour la zone
* \auhtor Quentin
* \version 1.0
*/
ListePositions liste_positions_init();

/**
* \brief Ajout d'une position dans la liste des positions
* \auhtor Quentin
* \version 1.0
* \param liste 		la liste des positions
* \param position 	la position à ajouter	
*/
void liste_positions_ajout(ListePositions* liste, Position position);

/**
* \brief Initialise la zone par rapport à la couleur
* \auhtor Quentin
* \version 1.0
* \param couleur 	la couleur de la zone
* \details La couleur correspond aux pions qui doivent se situer dans la zone pour gagner
*/
Zone zone_init(Couleur couleur, int nombre_joueur);

/**
* \brief verifie que la zone contient tous les pions du joueur
* \auhtor Quentin
* \version 1.0
* \param zone 		la zone où doivent être les pions
* \param joueur 	le joueur qui doit amener ses pions à la zone de sa victoire
* \return le nombre de pion dans la zone
*/
int verification_zone(Zone* zone, Joueur* joueur);

#endif