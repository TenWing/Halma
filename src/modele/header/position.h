
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

/**
* \brief Une position est l'association d'une abscisse et d'une ordonnée
* \auhtor Quentin
* \version 1.0
*/
typedef struct Position Position;
struct Position 
{
	/**
	* \brief La position x correspondant à l'abscisse
	*/
 	int x;

 	/**
 	* \brief La position y correspondant à l'ordonnée
 	*/
 	int y;
};

/**
 * \brief    Génère la position d'un pion
 * \author	 Quentin        
 * \param    int x	l'abscisse du pion
 * \param	 int y 	l'ordonnée du pion
 * \return   La position du pion
 */
Position position_init(int x, int y);

 #endif