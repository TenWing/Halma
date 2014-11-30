/**
 * \file      zone.c
 * \author    Geliot
 * \version   1.0
 * \date      30 Novembre 2014
 * \brief     Définit les fonctions pour aider à trouver un joueur gagnant
 *
 * 
 *            
 */

#include <stdio.h>
#include <stdlib.h>
#include <zone.h>
#include <position.h>

ListePositions liste_positions_init()
 {
 	//Création de la liste des positions
 	ListePositions liste_positions;

 	//Attribution des valeurs
 	liste_positions.premier = NULL;

 	//Retourne la liste des positions initialisée
 	return liste_positions;
 }

void liste_positions_ajout(ListePositions* liste, Position position)
{
	//Création d'un nouvel élément
	NoeudPosition* nouveau = malloc(sizeof(NoeudPosition));

	if(nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Le noeud possède la position comme valeur
	nouveau->position = position;
	nouveau->suivant = NULL;

	//Le premier élément de la liste
	if(liste->premier == NULL)
		liste -> premier = nouveau;
	// Après on ajoute à la fin
	else
	{
		// On parcoure la liste
		NoeudPosition* tmp = liste -> premier;
		while(tmp -> suivant != NULL)
		{
			tmp = tmp -> suivant;
		}

		// On dit que le suivant du dernier est le dernier
		tmp->suivant = nouveau;
	}
}

Zone zone_init(Couleur couleur, int nombre_joueur)
{
	//Initialise la zone
	Zone zone;

	//On initialise la liste
	zone.liste_positions = liste_positions_init();

	//La couleur de la zone
	zone.couleur_zone = couleur;

	if(nombre_joueur < 3)
	{
		switch(couleur)
		{
			case JAUNE:
				liste_positions_ajout(&zone.liste_positions, position_init(0,12));
				liste_positions_ajout(&zone.liste_positions, position_init(1,12));
				liste_positions_ajout(&zone.liste_positions, position_init(2,13));
				liste_positions_ajout(&zone.liste_positions, position_init(3,14));
				liste_positions_ajout(&zone.liste_positions, position_init(4,14));
				break;
			case BLEU:
				liste_positions_ajout(&zone.liste_positions, position_init(11,1));
				liste_positions_ajout(&zone.liste_positions, position_init(12,2));
				liste_positions_ajout(&zone.liste_positions, position_init(13,3));
				liste_positions_ajout(&zone.liste_positions, position_init(14,4));
				liste_positions_ajout(&zone.liste_positions, position_init(15,4));
				break;
			default:
				break;
		}
	}

	else
	{
		switch(couleur)
		{
			case ROUGE :
				liste_positions_ajout(&zone.liste_positions, position_init(12,14));
				liste_positions_ajout(&zone.liste_positions, position_init(13,13));
				liste_positions_ajout(&zone.liste_positions, position_init(14,12));
				liste_positions_ajout(&zone.liste_positions, position_init(15,12));
				break;
			case BLEU:
				liste_positions_ajout(&zone.liste_positions, position_init(12,1));
				liste_positions_ajout(&zone.liste_positions, position_init(13,2));
				liste_positions_ajout(&zone.liste_positions, position_init(14,3));
				liste_positions_ajout(&zone.liste_positions, position_init(15,3));
				break;
			case VERT:
				liste_positions_ajout(&zone.liste_positions, position_init(0,3));
				liste_positions_ajout(&zone.liste_positions, position_init(1,3));
				liste_positions_ajout(&zone.liste_positions, position_init(2,2));
				liste_positions_ajout(&zone.liste_positions, position_init(3,1));
				break;
			case JAUNE:
				liste_positions_ajout(&zone.liste_positions, position_init(0,12));
				liste_positions_ajout(&zone.liste_positions, position_init(1,12));
				liste_positions_ajout(&zone.liste_positions, position_init(2,13));
				liste_positions_ajout(&zone.liste_positions, position_init(3,14));
				break;
		}
	}
	return zone;
}

