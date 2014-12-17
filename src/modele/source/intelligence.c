/**
* \file		intelligence.c
* \author	Tendry
* \brief	
* \version	1.0
*/

// #####################
// INLCUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <intelligence.h>
#include <direction.h>
// #####################

ListePossibilites liste_possibilites_init(Pion pion)
{
	ListePossibilites liste;

	liste.poids = 0;
	liste.pion = pion;
	liste.premier = NULL;

	return liste;
}

void liste_possibilites_detruire(ListePossibilites* liste)
{
	// Une variable sert à délivrer la mémoire
	// l'autre à parcourir ce qu'il est encore faisable
	NoeudPossibilite* noeud = liste->premier;
	NoeudPossibilite* reine_des_neiges;

	while(noeud != NULL)
	{
		reine_des_neiges = noeud;
		noeud = noeud -> suivant;
		free(reine_des_neiges);
	}

	free(liste);
}

void liste_possibilites_ajout(ListePossibilites* liste, Possibilite ajout)
{
	// On crée le nouveau noeud qui sera ajouté
	NoeudPossibilite* noeud = malloc(sizeof(NoeudPossibilite));

	// On façonne le noeud
	noeud->possibilite = ajout;
	noeud->suivant = NULL;

	// cas premier ajout
	if(liste->premier == NULL)
	{
		liste->premier = noeud;
	}	
	// Sinon ajout à la fin
	else
	{
		NoeudPossibilite* parcours = liste->premier;

		// Parcours de la liste jusqu'à sa fin
		while(parcours->suivant != NULL)
		{
			parcours = parcours->suivant;
		}

		// Ajout de notre élément à la fin
		parcours->suivant = noeud;
	}
}