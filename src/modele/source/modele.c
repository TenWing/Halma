
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
#include <plateau.h>
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
		for(i=0; i<4; i++)
		{
			modele.tableau_joueur[i] = joueur_init(&modele.plateau, i);		
			modele.tableau_zone[i] = zone_init(i, nombreJoueurs);
		}

	}
	else
	{
			modele.tableau_joueur[0] = joueur_init(&modele.plateau, 1);		
			modele.tableau_zone[0] = zone_init(1, nombreJoueurs);
			modele.tableau_joueur[1] = joueur_init(&modele.plateau, 3);		
			modele.tableau_zone[1] = zone_init(3, nombreJoueurs);
		
	}
	return modele;
}

void commencer_tour(Modele* modele, Pion* pion)
{
	// On crée un tour
	Tour tour = tour_init(pion);
	
	// On dit au modèle qu'il y a un nouveau tour joué
	pileTours_ajouterTour(&modele->pile_tours, tour);
}

void fin_tour(Pion** pion)
{
	Pion* direct = *pion;
	// Le pion ne peut plus sauter
	direct->saut = 0;

	// Le pion n'est plus selectionné
	direct->selectionne = 0;
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

void annuler_tour(Modele* modele)
{

	Tour dernier;
	//On dépile le tour du joueur qui joue

	//On prend le tour du joueur précedent
	dernier = pileTours_depiler(&modele->pile_tours);


	// On change la position du pion
	dernier.pion->position.x = dernier.depart.x;
	dernier.pion->position.y = dernier.depart.y;
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



void sauvegarderModele(Modele modele, FILE* emplacement_fichier_sauvegarde, char* emplacement_fichier_sauvegarde_plateau)
{
	NoeudTour* actuel = modele.pile_tours.premier;

	int i, compteur=0;

	Modele factice;

	factice.pile_tours = pileTours_init();

	while(actuel != NULL)
	{
		compteur++;

		actuel = actuel -> suivant;
	}


	for (i = 0; i < compteur; i++)
	{
		pileTours_ajouterTour(&factice.pile_tours, pileTours_depiler(&modele.pile_tours));
	}

	NoeudTour* actuelFactice = factice.pile_tours.premier;

	fwrite(&compteur, sizeof(int), 1, emplacement_fichier_sauvegarde);

	while(actuelFactice != NULL)
	{
		sauvegardeTour(actuelFactice->tour, emplacement_fichier_sauvegarde);

		actuelFactice = actuelFactice -> suivant;
	}

	modele.plateau = updateMatrice(&modele.plateau);

	sauvegardePlateau(modele.plateau, emplacement_fichier_sauvegarde_plateau);

	fwrite(&modele.nombreJoueurs, sizeof(int), 1, emplacement_fichier_sauvegarde);
}

Modele chargerModele(FILE* emplacement_fichier, char* emplacement_fichier_plateau)
{
	Modele modele;
	int compteur,i;

	modele.pile_tours = pileTours_init();

	//On charge le nombre de coup du tour
	fread(&compteur, sizeof(int), 1, emplacement_fichier);

	//On empile le nombre de coups qu'il y avait dans le tour sauvegarder
	for (i = 0; i < compteur; i++)
	{
		pileTours_ajouterTour(&modele.pile_tours, chargerTour(emplacement_fichier));
	}

	modele.plateau = chargerPlateau(emplacement_fichier_plateau);
	
	fread(&modele.nombreJoueurs, sizeof(int), 1, emplacement_fichier);

	if(modele.nombreJoueurs > 2)
	{
		for(i=0; i<4; i++)
		{
			modele.tableau_joueur[i] = joueur_init(&modele.plateau, i);		
			modele.tableau_zone[i] = zone_init(i, modele.nombreJoueurs);
		}
	}
	else
	{
			modele.tableau_joueur[0] = joueur_init(&modele.plateau, 1);		
			modele.tableau_zone[0] = zone_init(1, modele.nombreJoueurs);
			modele.tableau_joueur[1] = joueur_init(&modele.plateau, 3);		
			modele.tableau_zone[1] = zone_init(3, modele.nombreJoueurs);		
	}

	return modele;
}