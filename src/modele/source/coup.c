

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

void sauvegardeCoup(Coup coup, char* emplacement_fichier_sauvegarde)
{
	sauvegardePion(coup.pion, emplacement_fichier_sauvegarde);

	FILE *fichier_contient_coup;
	fichier_contient_coup = fopen(emplacement_fichier_sauvegarde, "wb");

	if (fichier_contient_coup != NULL)
	    {
	    	fprintf(fichier_contient_coup, "%d%d", coup.precedente.x, coup.precedente.y);
			fclose(fichier_contient_coup);			
	    }

	else
	    {
	         printf("Impossible d'ouvrir le fichier sauvegarde.txt\n");
	    }
}