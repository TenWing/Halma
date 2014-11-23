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
#include <pion.h>
//######################################

  /**
* \brief Une liste de pions
* \auhtor Quentin
* \version 1.0
*/

typedef struct EnsemblePion EnsemblePion;
struct EnsemblePion
{
	int val;
	struct EnsemblePion *next;
};

typedef EnsemblePion* llists;

 /**
* \brief Un joueur est un ensemble de pions
* \auhtor Quentin
* \version 1.0
*/

typedef struct Joueur Joueur;

 struct Joueur{
 	/**
	* \brief Un ensemble de pions
	* \detail 	Un pointeur qui sera un tableau où le numéro de la case du tableau sera l'identifiant du pion
	* /see Pion
	*/
 	EnsemblePion;
};

  #endif

