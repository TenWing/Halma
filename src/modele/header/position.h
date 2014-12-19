

/**
 * \file      position.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit  la position d'un pion
 *
 * \details   Définit la structure d'une position
 */

#ifndef POSITION_H
#define POSITION_H

#include <direction.h>

/**
* \brief Une position est l'association d'une abscisse et d'une ordonnée
* \auhtor Quentin
* \version 2.0
*/
typedef struct Position Position;
struct Position 
{
	/**
	* \brief La position x correspondant à l'abscisse (la ligne de la matrice)
	*/
 	int x;

 	/**
 	* \brief La position y correspondant à l'ordonnée (la colonne de la matrice)
 	*/
 	int y;

 	/**
 	* \brief indique si la position est marquée
 	*/
 	int marque;
};

/**
 * \brief    Génère la position d'un pion
 * \author	 Quentin        
 * \param    int x	l'abscisse du pion
 * \param	 int y 	l'ordonnée du pion
 * \return   La position du pion
 */
Position position_init(int x, int y);

/**
* \brief	Indique si deux positions sont égales
* \author	Tendry
* \version	1.0
* \param 	a la première position testée
* \param	b la deuxième position testée
* \return	1 si les positions sont égales, 0 sinon
*/
int position_egale(Position a, Position b);

/**
* \brief	regarde si une position est comprise dans un intervalle
			définie par une position autre
* \author	Tendry
* \version	1.0
* \param	test la position testée
* \param	borne la borne pour l'intervalle
* \param	direction la direction de l'analyse
* \return	1 si oui 0 si non
*/
int position_dans_intervalle(Position test, Position borne, Direction direction);

 #endif