/**
 * \file      modele.c
 * \author    Geliot
 * \version   1.0
 * \date      19 Novembre 2014
 * \brief     Définit les fonctions pour jouer au jeu de l'Halma
 *
 * \details   Ces fonctions permettent de créer le jeu, pouvoir y jouer ...
 *            
 */

#include <stdio.h>
#include <stdlib.h>

#include <matrice.h>
#include <modele.h>

/**
 * \brief    Génère le plateau de jeu
 * \details  Permet de créer le plateau de jeu à partir des fonctions de la librairie matrice
 *             
 * \param    Plateau plateau
 * \return   Le plateau de jeu
 */
Plateau plateau_init(Plateau plateau) 
{
	plateau.matrice.nbLignes = Taille_plateau;
	plateau.matrice.nbColonnes = Taille_plateau;
	plateau.matrice = alloue(plateau.matrice.nbLignes,plateau.matrice.nbColonnes);

	return plateau;
}