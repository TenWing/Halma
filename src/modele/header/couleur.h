
/**
 * \file      couleurs.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit les couleurs du jeu
 *
 * \details   Définit l'énumération des couleurs pour les pions, le plateau et les différents coups réalisables pour un pion donné
 */

#ifndef COULEURS_H
#define COULEURS_H

/**
* \brief Une Couleur pour distinghuer des éléments
* \author Quentin
* \version 1.0
* \details Les seuls éléments ayant une couleur seront les pions
*/
typedef enum Couleur Couleur;
enum Couleur
{
	ROUGE, BLEU, VERT, JAUNE, BLANC, ORANGE 
};

#endif