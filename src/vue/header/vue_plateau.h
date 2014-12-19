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
#include <modele.h>
#include <mode.h>	
// ######################

/**
* \brief	Affiche le plateau de jeu complet
* \param 	modele le modele observé
* \param	mode indique si le joueur sélectionne ou contemple le plateau
* \author	Tendry
* \version	1.0
*/
void affiche_plateau(Modele* modele, Mode mode);

/**
* \brief 	Affiche une case 
* \param 	modele le modele observé
* \param	position la position de la case traitée
* \param	mode indique si le joueur sélectionne ou contemple le plateau
* \author 	Tendry
* \version	1.0
*/
void affiche_case(Modele* modele, Position* position, Mode mode);

#endif