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
	* \brief Un ensemble de pions
	* \detail 	Un pointeur qui sera un tableau où le numéro de la case du tableau sera l'identifiant du pion
	* /see Pion
	*/
 	Pion *ensemble_pion;

// petit commentaire pour Tendry :)
 	// on peut pas juste définir un joueur par Pion.. le joueur ne peut pas se résumer a 1 pion.
 	//j'ai pensé à un pointeur ou tableau.. je sais pas lequel est le mieux pour faire une liste. Ensuite ce que je ne sais pas, c'est
 	//si on fait un pointeur sur Pion, comment est gérer l'adresse et la valeur ? Les 3 définitions de Pion où sont-elles ?...
 	//Ce que j'aimerai faire c'est que quand on choisit un case du tableau, genre *(ensemble_pion+2), le 2 devienne l'identifiant du pion, et 
 	//qu'on puisse définir dans cette case la couleur du pion et ca position en meme temps...
 };

  #endif

