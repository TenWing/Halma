/**
* \file		controleur.h
* \brief	Contient les prototypes des fonctions de contrôle
* \version 	1.0
* \date		01 Décembre 2014
*/

// #################################
// INCLUSIONS
#include <vue.h>
#include <modele.h>
// #################################

/**
* \brief 	vide le buffer
* \author 	internet
*/
void viderBuffer();

// TOUTES LES FONCTIONS CONCERNENT LE JEU DE L'HALMA

/**
* \brief	Demande à l'utilisateur d'entrer un caractère
* \author	Tendry
* \version 	1.0
* \return	Le caractère saisit
*/
char recuperer_caractere();

/**
* \brief	Demande à l'utilisateur d'entrer un entier
* \author	Tendry
* \version 	1.0
* \return	L'entier saisit
*/
int recuperer_entier();

/**
* \brief 	permet de jouer un tour de jeu complet
* \author 	Tendry
* \param	joueur le joueur qui joue le tour
*/
void jouer_tour(Joueur* joueur);