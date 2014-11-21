/**
 * \file      joueur.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit d'un joueur
 *
 * \details   Définit la structure d'un joueur par un ensemble de pions
 */
 
#ifndef JOUEUR_H
#define JOUEUR_H

 //######################################
//Inclusions
#include "pion.h"
//######################################

 /**
* \brief Un joueur est un ensemble de pions
* \auhtor Quentin
* \version 1.0
*/

typedef struct Joueur Joueur;

 struct Joueur{
 	/**
	* \brief Un pion
	* /see Pion
	*/
 	Pion pion;
 };

  #endif

