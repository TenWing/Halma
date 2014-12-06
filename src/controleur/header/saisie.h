/**
* \file		saisie.h
* \brief	Contient les prototypes des fonctions de saisie
* \version 	1.0
* \date		03 Décembre 2014
*/

#ifndef SAISIE_H
#define SAISIE_H

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

#endif