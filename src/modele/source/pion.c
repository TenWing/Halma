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

#include <pion.h>

/**
 * \brief    Génère un pion
 * \details  Permet de créer un pion (son identifiant, sa position et sa couleur)
 *             
 * \param    Pion pion, int choixCouleur, int x, int y, int identifiant
 * \return   Le pion
 */
Pion init_pion(int choixCouleur, int x, int y, int identifiant) 
{
	Pion pion;
	
		pion.position.x=x;
		pion.position.y=y;
		pion.identifiant=identifiant;
		printf("x=%d\n", pion.position.x);
printf("y=%d\n", pion.position.y);

	switch(choixCouleur)
	{
		case 1 : 
		pion.couleur=ROUGE;
		break;

		case 2 : 
		pion.couleur=BLEU;
		break;

		case 3 : 
		pion.couleur=VERT;
		break;

		case 4 : 
		pion.couleur=JAUNE;
		break;

	}

	return pion;
}