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

Possibilite possibilite_init(int poids, Position position)
{
	Possibilite possibilite;

	possibilite.poids = poids;
	possibilite.position = position;

	return possibilite;
}

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

// #########################################################

EnsemblePossibilites ensemble_possibilites_init()
{
	EnsemblePossibilites ensemble;

	ensemble.premier = NULL;

	return ensemble;
}

void ensemble_possibilites_ajout(EnsemblePossibilites* liste, ListePossibilites ajout)
{
	// On crée le nouveau noeud qui sera ajouté
	NoeudListe* noeud = malloc(sizeof(NoeudListe));

	// On façonne le noeud
	noeud->liste = ajout;
	noeud->suivant = NULL;

	// cas premier ajout
	if(liste->premier == NULL)
	{
		liste->premier = noeud;
	}	
	// Sinon ajout à la fin
	else
	{
		NoeudListe* parcours = liste->premier;

		// Parcours de la liste jusqu'à sa fin
		while(parcours->suivant != NULL)
		{
			parcours = parcours->suivant;
		}

		// Ajout de notre élément à la fin
		parcours->suivant = noeud;
	}
}

void ensemble_possibilites_detruire(EnsemblePossibilites* liste)
{
	// Une variable sert à délivrer la mémoire
	// l'autre à parcourir ce qu'il est encore faisable
	NoeudListe* noeud = liste->premier;
	NoeudListe* reine_des_neiges;

	while(noeud != NULL)
	{
		reine_des_neiges = noeud;
		noeud = noeud -> suivant;
		free(reine_des_neiges);
	}

	free(liste);
}

// #############################################################

EnsemblePossibilites construire_possibilites(Modele* modele, Joueur* joueur)
{
	EnsemblePossibilites ensemble;

	NoeudReferencePion* noeud = joueur->liste_references_pions.premier;
	
	// Pour chaque pion du joueur
	while(noeud != NULL)
	{	
		ListePossibilites possibilite_de_ce_pion = possibilites_du_pion(modele, *noeud->pion, joueur);
		ensemble_possibilites_ajout(&ensemble, possibilite_de_ce_pion);
	}

	return ensemble;
}

ListePossibilites possibilites_du_pion(Modele* modele, Pion pion, Joueur* joueur)
{
	// création de l'ensemble des possibilités du pion
	ListePossibilites liste = liste_possibilites_init(pion);

	// La direction idéale
	Direction ideale = joueur->direction;

	// On va chercher chaque possibilité
	possibilite_direction(&liste, &modele->plateau, &pion, HAUT, ideale);	
	possibilite_direction(&liste, &modele->plateau, &pion, HAUT_DROITE, ideale);	
	possibilite_direction(&liste, &modele->plateau, &pion, DROITE, ideale);	
	possibilite_direction(&liste, &modele->plateau, &pion, BAS_DROITE, ideale);	
	possibilite_direction(&liste, &modele->plateau, &pion, BAS, ideale);	
	possibilite_direction(&liste, &modele->plateau, &pion, BAS_GAUCHE, ideale);	
	possibilite_direction(&liste, &modele->plateau, &pion, GAUCHE, ideale);	
	possibilite_direction(&liste, &modele->plateau, &pion, HAUT_GAUCHE, ideale);	

	return liste;
}

PileCoups recuperer_meilleurs_coups(EnsemblePossibilites* ensemble)
{
	PileCoups pile;

	return pile;
}

// #############################################################

void possibilite_direction(ListePossibilites* liste, Plateau* plateau, Pion* pion,
							Direction direction, Direction ideale)
{
	// Calcul du poids
	int poids = 0;
	// SI on va dans le bon sens
	if(ideale == direction)
		poids++;
	else
		poids--;

	// La position analysée
	Position position_direction = position_init(pion->position.x, pion->position.y);
	Position position_direction_saut = position_init(pion->position.x, pion->position.y);

	// On regarde la direction analysée
	switch(direction)
	{
		case HAUT:
			position_direction.x -= 1;
			position_direction_saut.x -= 2;
			break;

		case HAUT_DROITE:
			position_direction.x -= 1;
			position_direction.y += 1;
			position_direction_saut.x -= 2;
			position_direction_saut.y += 2;
			break;

		case DROITE:
			position_direction.y += 1;
			position_direction_saut.y += 2;
			break;

		case BAS_DROITE:
			position_direction_saut.y += 2;
			position_direction_saut.x += 2;
			position_direction.y += 1;
			position_direction.x += 1;
			break;

		case BAS:
			position_direction_saut.x += 2;
			position_direction.x += 1;
			break;

		case BAS_GAUCHE:
			position_direction_saut.x += 2;
			position_direction_saut.y -= 2;
			position_direction.x += 1;
			position_direction.y -= 1;
			break;

		case GAUCHE:
			position_direction_saut.y -= 2;
			position_direction.y -= 1;
			break;

		case HAUT_GAUCHE:
			position_direction.x -= 1;
			position_direction.y -= 1;
			position_direction_saut.x -= 2;
			position_direction_saut.y -= 2;
			break;

		default:
			break;
	}

	// Si on saute
	if(pion->saut)
	{
		// On ne regarde la portée de ce qui est a portée dez saut
		// SI ET SEULEMENT SI un pion est a portée directe
		if(plateau_getVide(plateau, position_direction) == NULL)
		{
			Position* p = plateau_getVide(plateau, position_direction_saut);
			if(p != NULL)
			{
				// Un déplacement de saut possible dans la bonne direction, le poids est plus important
				if(ideale == direction)
					poids++;

				Possibilite possible = possibilite_init(poids, position_direction_saut);
				liste_possibilites_ajout(liste, possible);
			}
		}
	}
	// Si on saute pas
	else
	{
		// On regarde ce qui est à portée
		Position* p = plateau_getVide(plateau, position_direction);
		if(p != NULL)
		{
			// Un déplacement de saut possible dans la bonne direction, le poids est plus important
			if(ideale == direction)
				poids++;

			Possibilite possible = possibilite_init(poids, position_direction_saut);
			liste_possibilites_ajout(liste, possible);
		}
		// S'il y a un pion a portée on regarde s'il on peut sauter
		else
		{
			p = plateau_getVide(plateau, position_direction_saut);
			if(p != NULL)
			{
				// Un déplacement de saut possible dans la bonne direction, le poids est plus important
				if(ideale == direction)
					poids++;

				Possibilite possible = possibilite_init(poids, position_direction_saut);
				liste_possibilites_ajout(liste, possible);
			}
		}
	}
}
