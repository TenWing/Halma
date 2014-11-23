

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
 * \param    Pion pion, int choixCouleur, int x, int y, int identifiant
 * \return   Le pion
 */
Pion init_pion(int choixCouleur, int x, int y, int identifiant);

//TODO On reverra à la modélisation si on va faire comme ça mais il y a des fautes la dedans en plus ;)
/*
typedef(struct Pions, Pions);
struct Pions {
	int totalPions; //total des pions de l'ensemble ( 9 ou 8 selon la partie jouée)
	Pion pion;
};*/

 #endif