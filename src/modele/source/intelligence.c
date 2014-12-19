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
#include <pion.h>
#include <coup.h>
#include <time.h>
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
	liste.pion = pion_copie(pion);
	liste.premier = NULL;

	return liste;
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

void liste_possibilites_calcule_poids(ListePossibilites* liste)
{
	NoeudPossibilite* noeud = liste->premier;
	int max = -1;

	// parcours de la liste
	while(noeud != NULL)
	{
		if(noeud -> possibilite.poids > max)
			max = noeud -> possibilite.poids;

		noeud = noeud -> suivant;
	}

	liste->poids = max;
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

int ensemble_poids_plus_fort(EnsemblePossibilites* ensemble)
{
	int poids = -1;

	NoeudListe* noeud = ensemble->premier;

	while(noeud != NULL)
	{
		if(noeud -> liste.poids > poids)
			poids = noeud->liste.poids;
		noeud = noeud -> suivant;
	}

	return poids;
}

// #############################################################

void ia_jouer_coup(Modele* modele, Joueur* joueur)
{
	EnsemblePossibilites possibles = construire_possibilites(modele, joueur);

	PileCoups pile = recuperer_meilleurs_coups(&possibles);

	Coup a_jouer = coup_au_hasard(&pile);

	Pion* move = modele_get_reference_pion(modele, a_jouer.pion);

	// L'IA commence un tour OLOLOL CAY POUR LES TOURS
	commencer_tour(modele, move);

	// Bien sur mise a jour des positions du modèle
	liste_positions_ajout(&modele->plateau.vides, move->position);

	// Ok .. precedente = position mais c'est une erreur de nommage
	move->position = a_jouer.precedente;
	liste_positions_supprimer(&modele->plateau.vides, a_jouer.precedente);
}

EnsemblePossibilites construire_possibilites(Modele* modele, Joueur* joueur)
{
	EnsemblePossibilites ensemble = ensemble_possibilites_init();

	NoeudReferencePion* noeud = joueur->liste_references_pions.premier;
	
	// Pour chaque pion du joueur
	while(noeud != NULL)
	{	
		ListePossibilites possibilite_de_ce_pion = possibilites_du_pion(modele, *noeud->pion, joueur);
		ensemble_possibilites_ajout(&ensemble, possibilite_de_ce_pion);

		// On passe au suivant
		noeud = noeud -> suivant;
	}	

	return ensemble;
}

ListePossibilites possibilites_du_pion(Modele* modele, Pion pion, Joueur* joueur)
{
	// c'est le bon pion

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

	// la liste calcule son poids
	liste_possibilites_calcule_poids(&liste);
	return liste;
}

PileCoups recuperer_meilleurs_coups(EnsemblePossibilites* ensemble)
{
	// le meilleur des poids
	int meilleur_poids = ensemble_poids_plus_fort(ensemble);

	PileCoups pile = pileCoups_init();

	NoeudListe* noeud = ensemble->premier;

	// parcours de liste
	while(noeud != NULL)
	{
		// On crée un coup qu'on stocke si le poids
		// correspondant est un des plus forts
		if(noeud -> liste.poids == meilleur_poids)
		{
			// Pour ça il faut récupérer la meilleur possibilité
			NoeudPossibilite* node = noeud -> liste.premier;
			while(node != NULL)
			{
				if(node->possibilite.poids == meilleur_poids)
				{
					Position position = node->possibilite.position;
					Coup coup = coup_init(&noeud->liste.pion, position);
					pileCoups_ajouterCoup(&pile, coup);
				}
				node = node -> suivant;
			}
		}

		noeud = noeud -> suivant;
	}

	return pile;
}

Coup coup_au_hasard(PileCoups* liste)
{
	srand(time(NULL));
	int taille = pileCoups_taille(liste);
	int indice = rand() % taille-1;
	int i = 0;
	NoeudCoup* noeud = liste->premier;

	// On choisit le coup
	for(i = 0; i < indice; i++)
	{
		noeud = noeud -> suivant;
	}

	return noeud -> coup;
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

	// On regarde ce qui est à portée
	Position* p = plateau_getVide(plateau, position_direction);
	if(p == NULL) //Un pion a été trouvé
	{
		// on regarde s'il est possible de sauter par dessus lui
		p = plateau_getVide(plateau, position_direction_saut);
		if(p != NULL)
		{
			if(ideale == direction)
				poids+=3;
			else if(direction_proche(ideale, direction))
				poids+=2;

			Possibilite possible = possibilite_init(poids, position_direction_saut);
			liste_possibilites_ajout(liste, possible);			
		}
	}
	// S'il y a un espace vide a portée sinon ben on peut aller la quoi 
	else
	{
		if(ideale == direction)
				poids+=2;
		else if(direction_proche(ideale, direction))
				poids++;

		Possibilite possible = possibilite_init(poids, position_direction);
		liste_possibilites_ajout(liste, possible);
	}
}
