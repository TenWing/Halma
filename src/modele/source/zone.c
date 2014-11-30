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

Zone zone_init(Couleur couleur)
{
	//Initialise la zone
	Zone zone;

	//On initialise la liste
	zone.liste_positions = liste_positions_init();

	//La couleur de la zone
	zone.couleur_zone = couleur;

	return zone;
}