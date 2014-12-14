/**
 * \file      coup.h
 * \author    Tendry
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit la structure d'un coup, mais aussi d'une liste de coups
 *
 * \details   Un coup est considéré comme étant un déplacement de pion, dans le jeu de l'Halma, un pion peut se déplacer
 			  plusieurs fois dans un tour en sautant d'autre pions et en enchaînant les sauts, chaque étape intermédiaire
 			  est un coup.
 			  Une liste de coups est considérée comme une pile de coups, puisque lorsqu'on dépile le dernier l'élément
 			  le plus haut de la pile est sensé être l'avant dernier coup.
*/

#ifndef COUP_H
#define COUP_H

//######################################
//Inclusions
#include <pion.h>
#include <position.h>
//######################################

//######################################
//STRUCTURES
//######################################

/**
* \brief Un coup peut se résumer en un déplacement d'un pion
* \author Tendry
* \version 1.0
*/
typedef struct Coup Coup;
struct Coup
{
	/**
	* \brief le pion qui se déplace
	* \details Un pointeur car il s'agit d'une information ne nécessitant pas d'exister en tant que tel
	* \see Pion
	*/
	Pion pion;

	/**
	* \brief la position que le pion occupait juste avant la fin de ce coup
	* \see Position
	*/
	Position precedente;
};

/**
* \brief un noeud d'une pile de coups
* \author Tendry
* \version 1.0
*/
typedef struct NoeudCoup NoeudCoup;
struct NoeudCoup
{
	/**
	* \brief le coup, valeur du noeud
	* \see Coup
	*/
	Coup coup;

	/**
	* \brief un pointeur vers le noeud suivant
	*/
	NoeudCoup* suivant;
};

/**
* \brief Une pile de coups
* \author Tendry
* \version 1.0
* \details la pile de coups contient plusieurs noeud contenant les coups
*/
typedef struct PileCoups PileCoups;
struct PileCoups
{
	/**
	* \brief le premier noeud de la pile
	* \details structure de données de type pile
	* \see NoeudCoup
	*/
	NoeudCoup* premier;
};


//######################################
//FONCTIONS COUP
//######################################

/**
* \brief initialise un coup
* \author Tendry
* \version 1.0
* \param p le pointeur du pion qui concerne le coup
* \param pos la position qu'occupe le pion au début du coup
* \return renvoie un Coup bien initialisé
*/
Coup coup_init(Pion* p, Position pos);

//######################################
//FONCTIONS PILE COUPS
//######################################

/**
* \brief initialise une pile de coups
* \author Tendry
* \version 1.0
* \return Une pile de coups initialisée
*/
PileCoups pileCoups_init();

/**
* \brief dépile le dernier élément des coups
* \author Tendry
* \version 1.0
* \param pile la pile de coups
* \return Le coup en haut de la pile
*/
Coup pileCoups_depiler(PileCoups* pile);

/**
* \brief ajoute un coup en haut de la pile
* \author Tendry
* \version 1.0
* \param pile la pile de coups
* \param coup le coup à ajouter
*/
void pileCoups_ajouterCoup(PileCoups* pile, Coup coup);

/**
* \brief 	sauvegarde un coup
* \author 	Quentin
* \version 1.0
* \param 	Coup 	le coup à sauvegarder
* \param 	emplacement_fichier_sauvegarde
*/
void sauvegardeCoup(Coup coup, char* emplacement_fichier_sauvegarde);

#endif
