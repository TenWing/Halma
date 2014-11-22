
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
	Pion* pion;

	/**
	* \brief la position que le pion occupait juste avant la fin de ce coup
	* \see Position
	*/
	Position precedente;
};

/**
* \brief Une liste de coups contient plusieurs coups sous forme de file
* \author Tendry
* \version 1.0
*/
typedef struct Coups Coups;
struct Coups
{
	/**
	* \brief le pion qui se déplace
	* \details Un pointeur car il s'agit d'une information ne nécessitant pas d'exister en tant que tel
	* \see Pion
	*/
};

#endif