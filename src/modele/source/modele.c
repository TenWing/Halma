
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
	int i;
	// On Crée le modèle
	Modele modele;

	modele.nombreJoueurs = nombreJoueurs;
	modele.plateau = plateau_init(nombreJoueurs);
	modele.pile_tours = pileTours_init();

	// On attribue le bon nombre de joueurs
	if(nombreJoueurs > 2)
	{
		for(i=0; i<3; i++)
		{
			modele.tableau_joueur[i] = joueur_init(&modele.plateau, i);		
			modele.tableau_zone[i] = zone_init(i, nombreJoueurs);
		}

	}
	else
	{
		for(i=0; i<2; i++)
		{
			modele.tableau_joueur[i] = joueur_init(&modele.plateau, i);		
			modele.tableau_zone[i] = zone_init(i, nombreJoueurs);
		}
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

void fin_tour(Pion* pion)
{
	// Le pion ne peut plus sauter
	pion->saut = 0;

	// Le pion n'est plus selectionné
	pion->selectionne = 0;
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
	if(dernier.pion.identifiant == -1)
		return; 

	// On change la position du pion concerné par le coup
	pion->position = position_init(dernier.precedente.x, dernier.precedente.y);

	// On change aussi son état (saut ou pas)
	pion->saut = dernier.pion.saut;
}

void annuler_tour(Modele* modele, Pion* pion)
{
	// On accède au tour courant
	NoeudTour* noeud = modele->pile_tours.premier;

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

		// noeud est le tour courant 
		// On ajoute le coup à la pile de coups du tour courant
		pileCoups_ajouterCoup(&noeud->tour.pile_coups, coup);
	}

	// On indique si il y a eu succes du coup
	return succes;
}

void supprimer_tour(Modele* modele)
{
	//On cherche le tour voulu
	Tour tour;

	//On dépile le tour choisi
	tour=pileTours_depiler(&modele->pile_tours);
}