

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

/*
DEFAULT   = "\033[0m";
HIGHLIGHT = "\033[1m";
UNDERLINE = "\033[4m";
BLINK     = "\033[5m";
BLACK     = "\033[30m";
RED       = "\033[31m";
GREEN     = "\033[32m";
YELLOW    = "\033[33m";
BLUE      = "\033[34m";
PURPLE    = "\033[35m";
CYAN      = "\033[36m";
WHITE     = "\033[37m";
*/

#endif