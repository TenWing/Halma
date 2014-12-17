
/**
* \file		joueur.c
* \author 	Tendry
* \brief	Définit le code source des fonctions du joueur
* \date		29 Novembre 2014
*/

// #########################################
// Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <joueur.h>
#include <plateau.h>
// #########################################

Joueur joueur_init(Plateau* plateau, Couleur couleur)
{
	// Création du joueur
	Joueur joueur;

	// Affectation des membres
	joueur.couleur = couleur;
	joueur.liste_references_pions = liste_references_pions_init();

	// On va récupérer les pions du jeu et pointer
	// Sur ceux qui appartiennent au joueur
	NoeudPion* actuel = plateau->liste_pions.premier;

	while(actuel->suivant != NULL)
	{
		// Si on trouve un pion du joueur
		if(actuel->pion.couleur == couleur)
		{
			// On ajoute une référence vers ce pion
			liste_references_pions_ajout(&joueur.liste_references_pions, &actuel->pion);
		}
		actuel = actuel->suivant;
	}

	return joueur;
}

ListeReferencePions liste_references_pions_init()
{
	// Création de la liste
	ListeReferencePions liste;

	// Attribution nulle
	liste.premier = NULL;

	return liste;
}

void liste_references_pions_ajout(ListeReferencePions* liste, Pion* pion)
{
	// Création du noeud
	NoeudReferencePion* noeud = malloc(sizeof(NoeudReferencePion));

	// Attribution de la référence
	noeud->pion = pion;
	noeud->suivant = NULL;

	// Cas du premier ajout
	if(liste->premier == NULL)
		liste->premier = noeud;
	else
	{
		// On parcoure la liste
		NoeudReferencePion* tmp = liste -> premier;
		while(tmp -> suivant != NULL)
		{
			tmp = tmp -> suivant;
		}

		// On dit que le suivant du dernier est le dernier
		tmp->suivant = noeud;
	}
}

Pion* joueur_get_reference_pion(Joueur* joueur, int identifiant)
{
	//Declaration d'un pointeur qui parcoura la liste et d'un pointeur de pion
	NoeudReferencePion* actuel;
	actuel = joueur -> liste_references_pions.premier;
	Pion* pion_nulle=NULL;

	//Tant qu'il y a un pion dans la liste de reference
	while(actuel != NULL)
	{

		if(identifiant == actuel->pion->identifiant)
		{
			//Si les deux identifiants sont corrects

			//On dit  qu'on selectionne bien ce pion
			actuel->pion->selectionne = 1;

			//On le retourne
			return (actuel->pion);
		}

		actuel = actuel -> suivant;
	}

	//Sinon, on retourne le pointeur nulle : le joueur n'a pas ce pion dans sa liste
	return pion_nulle;
}

int joueur_nombre_pions(Joueur* joueur)
{
	NoeudReferencePion* actuel;
	actuel = joueur -> liste_references_pions.premier;
	int nombre_joueur=0;

	while(actuel != NULL)
	{
		nombre_joueur++;
		actuel = actuel -> suivant;
	}

	return nombre_joueur;
}