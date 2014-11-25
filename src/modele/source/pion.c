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

/*Pion plateau_getpion(Position position, Plateau plateau)
{

	if(plateau.matrice.donnees[position.x][position.y] != '*')
	{
		return NULL;
	}

	else
	{
		// Un petit Commentaire que je dois disctuer avec toi mon grand !
		// Il faudrait qu'on créer un tableau ( ou un liste ...) qui répertorie TOUS LES PIONS ! (Pour moi ce serait une liste)
		// En effet, quand on initialisera 1 pion, on le mettra dans la liste. Ainsi on pourra savoir par cette liste la position, couleur, identifiant
		// d'un pion choisi.
		// Je comptais utiliser la fonction plateau_choisi comme ca : (reprise à partir du else)

		// On fait une boucle for qui parcourt notre liste avec la condition que si un pion a la position choisi dans le paramètre
		//on retourne direct le pion

		//En gros, 
	}
}*/