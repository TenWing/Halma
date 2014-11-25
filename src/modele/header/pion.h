/**
 * \file      pion.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit un pion et un ensemble de pion
 *
 * \details   Définit la structure d'un pion et d'une structure pour un ensemble de pions
 */
 
#ifndef PION_H
#define PION_H

 //######################################
//Inclusions
#include <position.h>
#include <couleur.h>
 //######################################

/**
* \brief Un pion, un élément de jeu du plateau
* \author Quentin
* \version 1.0
*/
typedef struct Pion Pion;
struct Pion
{
	/**
	* \brief chaque pion est identifié par un ID unique
	*/
 	int identifiant;

 	/**
 	* \brief La position du pion sur le plateau
 	* \see Position
 	*/
 	Position position;

 	/**
 	* \brief La couleur du pion
 	* \see Couleur
 	*/
 	Couleur couleur;
};

/**
 * \brief    Génère un pion
 * \details  Permet de créer un pion (son identifiant, sa position et sa couleur)
 *             
 * \param    couleur la couleur du pion
 * \param	 position la position par défaut du pion
 * \version  2.0
 * \return   Le pion initialisé
 */
Pion pion_init(Couleur couleur, Position position, int identifiant);

 #endif