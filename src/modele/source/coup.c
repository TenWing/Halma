



/**
* \file		coup.c
* \author 	Tendry
* \date		22 Novembre 2014
* \brief	Gère l'implémentation des coups et du coup
* \version	1.0
* \details	Implémente les fonctions relatives aux coups et à un coup unique dans le cadre
			d'un tour de jeu
*/

//#########################
//Inclusions
//#########################
#include <stdio.h>
#include <stdlib.h>
#include <coup.h>

//#########################
//FONCTIONS COUP
//#########################

Coup coup_init(Pion* p, Position pos)
{
	//Création d'un coup
	Coup coup;

	//Attribution du coup
	coup.pion = pion_copie(*p);
	coup.precedente = pos;

	//On renvoie la structure initialisée
	return coup;
}

//#########################
//FONCTIONS COUPS
//#########################

PileCoups pileCoups_init()
{
	//Création de la pile
	PileCoups pile;

	//Attribution des valeurs
	pile.premier = NULL;

	//On renvoie la pile initialisée
	return pile;
}

Coup pileCoups_depiler(PileCoups* pile)
{
	//Pointeur pour manipuler le haut de la pile
	NoeudCoup* tete = malloc(sizeof(NoeudCoup));

	//Le coup qu'on cherche
	Coup coup;
	coup.pion.identifiant = -1;

	//Si la pile n'est pas vide
	if(pile->premier != NULL)
	{
		//On pointe sur l'élément en haut de la pile
		tete = pile->premier;

		//On récupère le coup
		coup = tete->coup;

		//Le haut de la pile est l'élément suivant
		pile->premier = tete->suivant;

		//On détruit le précédent haut de pile
		free(tete);
	}

	return coup;
}

void pileCoups_ajouterCoup(PileCoups* pile, Coup coup)
{
	//L'élément ajouté à la pile
	NoeudCoup* ajout = malloc(sizeof(NoeudCoup));

	//On créé le noeud qui sera ajouté à la pile
	ajout->coup = coup;

	//On place l'élément précédent en dessous de celui ajouté
	ajout->suivant = pile->premier;

	//On indique bien que l'élément ajouté est la tête de la pile
	pile->premier = ajout;
}

int pileCoups_taille(PileCoups* pile)
{
	//Déclaration d'un compteur et d'un pointeur qui parcoura la pile
	int taille = 0;

	NoeudCoup* noeud = pile->premier;

	//Tant qu'il y a un élément, on incremente le compteur
	while(noeud != NULL)
	{
		noeud = noeud -> suivant;
		taille++;
	}

	//On retourne le compteur qui est la taille de la pile
	return taille;
}

void sauvegardeCoup(Coup coup, FILE* emplacement_fichier_sauvegarde)
{
	//On écrit dans le fichier texte les données du pion dans le coup
	sauvegardePion(coup.pion, emplacement_fichier_sauvegarde);

	//On écrit les données de la position precedent le coup joué dans le fichier
	fwrite(&coup.precedente.x, sizeof(int) , 1, emplacement_fichier_sauvegarde);
	fwrite(&coup.precedente.y, sizeof(int) , 1, emplacement_fichier_sauvegarde);	
}

Coup chargerCoup(FILE* emplacement_fichier)
{
	Coup coup;
	
	//On charge les données du pion dans le pion du coup
	coup.pion = chargerPion(emplacement_fichier);

	//De même avec la position precedente
	fread(&coup.precedente.x, sizeof(int) , 1, emplacement_fichier);
	fread(&coup.precedente.y, sizeof(int) , 1, emplacement_fichier);	
	
	//On retourne le coup
	return coup;
}