
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

// ############################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <pion.h>
// ############################

Pion pion_init(Couleur couleur, Position position, int identifiant)
{
	//Le pion qui sera initialisé
	Pion pion;
	
	// Couleur
	pion.couleur = couleur;

	//Copie de la position
	pion.position = position;
	
	// Copie de l'identifiant
	pion.identifiant=identifiant;

	// Il saute pas !!!!
	pion.saut = 0;

	// Son symbole sur le plateau
	pion.symbole='*';

	return pion;
}

Liste *liste_pion_init()
{
	//On alloue dynamiquement la structure de contrôle avec un malloc
	Liste *liste = malloc(sizeof(*liste));

	//On alloue dynamiquement la mémoire pour le stockage du premier element
	Element *element = malloc(sizeof(*element));

	// Vérification des allocations dynamiques
	if (liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	//L'élément pion est défini par défaut
	element->pion = pion_init(ROUGE, position_init(0,0), 1);
	
	//Le pointeur suivant pointe vers NULL
	element->suivant = NULL;

	//La liste pointe vers le premier élément qui est le pion
	liste -> premier = element;

	//On retourne la liste
	return liste;

}

void insertion_pion(Liste *liste_pions, Pion pion_nouveau)
{
	//Création d'un nouvel élément
	Element *nouveau = malloc(sizeof(*nouveau));

	if (liste_pions == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	nouveau -> pion = pion_nouveau;

	//Insertion de l'élément au début de la liste
	nouveau -> suivant = liste_pions -> premier;
	liste_pions -> premier = nouveau;
}

Pion plateau_getpion(Position position, Plateau plateau, Liste *liste_pions)
{
	//Création d'un pointeur sur element qui se balladera dans la liste
	Element *actuel = liste_pions -> premier;

	//Création d'un pion fictif qui sera retourner si à la postion demandée il n'y a pas le symbole d'un pion
	Pion pion_fictif;
	Position position_fictive=position_init(100,100);
	pion_fictif=pion_init(ORANGE, position_fictive, -1);

	//Condition pour savoir si à la position choisie, il y a un pion ou non
	if(plateau.matrice.donnees[position.x][position.y] != '*')
	{
		// le symbole n'est pas celui d'un pion, retourner le pion fictif
		return pion_fictif;
	}

	else
	{
		//le symbole est celui d'un pion

		//tant que actuel n'a pas atteint le dernier element de la liste
		while(actuel != NULL)
		{
			//On fait pointer actuel sur la position du pion de la liste et on teste l'égalité des positions

			if((actuel->pion.position.x == position.x) && (actuel -> pion.position.y == position.y) )
			{
				//les positions sont correctes

				//On retourne le pion qui est pointé par actuel
				return (actuel -> pion);
			}

			else
			{
				//les positions ne sont pas correctes

				//On fait pointer actuel sur le prochain élément
				actuel = actuel -> suivant;
			}
		}
	}
}