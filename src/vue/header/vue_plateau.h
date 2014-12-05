/**
* \file		vue_plateau.h
* \brief	Définit les fonctions et structures possibles
*			concernant l'affichage du plateau de jeu
* \author	Tendry
* \date 	29 Novembre 2014
*/

#ifndef VUE_PLATEAU_H
#define VUE_PLATEAU_H

// ######################
// INCLUSIONS
#include <plateau.h>
#include <mode.h>	
// ######################

/**
* \brief	Affiche le plateau de jeu complet
* \param 	plateau le plateau à afficher
* \param	mode indique si le joueur sélectionne ou contemple le plateau
* \author	Tendry
* \version	1.0
*/
void affiche_plateau(Plateau* plateau, Mode mode);

/**
* \brief 	Affiche une case 
* \param 	plateau le plateau qui fait le lien vers le modèle
* \param	position la position de la case traitée
* \param	mode indique si le joueur sélectionne ou contemple le plateau
* \author 	Tendry
* \version	1.0
*/
void affiche_case(Plateau* plateau, Position* position, Mode mode);

#endif