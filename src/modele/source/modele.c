/**
* \file		modele.c
* \author	Tendry
* \version	1.0
* \date		30 Novembre 2014
* \brief	Contient le code source des fonctions du modèle		
*/

// ###################################
// Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <modele.h>
// ###################################

Modele modele_init(int nombreJoueurs)
{
	// On Crée le modèle
	Modele modele;

	modele.plateau = plateau_init(nombreJoueurs);
	modele.pile_tours = pileTours_init();

	// On attribue le bon nombre de joueurs
	if(nombreJoueurs > 2)
	{
		modele.tableau_joueur[0] = joueur_init(&modele.plateau, BLEU);
		modele.tableau_joueur[1] = joueur_init(&modele.plateau, JAUNE);
	}

	return modele;
}

void commencer_tour(Modele* modele, Pion* pion)
{
	// On crée un tour
	Tour tour = tour_init(*pion);
	
	// On dit au modèle qu'il y a un nouveau tour joué
	pileTours_ajouterTour(&modele->pile_tours, tour);
}

void annuler_coup(Modele* modele, Pion* pion)
{	
	// On accède au tour courant
	NoeudTour* noeud = modele->pile_tours.premier;

	// S'il n'y a pas de tour WTF on arrête
	if(noeud == NULL)
		return;

	// on dépile le dernier coup
	Coup dernier = pileCoups_depiler(&noeud->tour.pile_coups);

	// S'il n'y a pas de coup avant
	if(dernier.pion == NULL)
		return; 

	// On change la position du pion concerné par le coup
	pion->position = position_init(dernier.pion->position.x, dernier.pion->position.y);
}

void annuler_tour(Modele* modele, Pion* pion)
{
	// On accède au tour courant
	NoeudTour* noeud = modele->pile_tours.premier;
	while(noeud -> suivant != NULL)
	{
		noeud = noeud->suivant;	
	}

	// On change la position du pion
	pion->position = position_init(noeud->tour.pion.position.x, noeud->tour.pion.position.y);
}

int jouer_coup(Modele* modele, Pion* pion, Direction direction)
{
	// Indique si le déplacement est un succès
	int succes = 0;

	// On crée un coup
	Coup coup = coup_init(pion, pion->position);

	// On joue le coup
	succes = pion_deplacer(pion, &modele->plateau, direction);

	// Si le coup réussit
	if(succes)
	{
		// On l'ajoute à la pile des coups du tour
		NoeudTour* noeud = modele->pile_tours.premier;
		while(noeud->suivant != NULL)
		{
			noeud = noeud->suivant;
		}

		// noeud est le tour courant 
		// On ajoute le coup à la pile de coups du tour courant
		pileCoups_ajouterCoup(&noeud->tour.pile_coups, coup);
	}

	// On indique si il y a eu succes du coup
	return succes;
}