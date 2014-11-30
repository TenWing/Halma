
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

typedef struct Modele Modele
struct Modele
{
	/**
	* \brief le plateau du jeu 
	* \see plateau
	*/
	Plateau plateau;

	/**
	* \brief La pile de tours
	* \see tour
	*/
	PileTours PileTours;

	/**
	* \brief le tableau des joueurs
	* 
	*/
	Joueur tableau_joueur[4];

};

 #endif