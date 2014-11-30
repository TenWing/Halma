
/**
 * \file      modele.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit les fonctions pour modeliser le jeu de l'halma
 */

#ifndef MODELE_H
#define MODELE_H

//######################################
//Inclusions
//######################################

/**
* \brief	Commence un tour de jeu
* \author	Tendry
* \param	modele le modèle qui joue
* \version 	1.0
*/
void commencer_tour(Modele* modele);

/**
* \brief	Fini le tour de jeu
* \author	Tendry
* \param	modele le modèle qui joue
* \version 	1.0
*/
void fin_tour(Modele* modele);

#endif