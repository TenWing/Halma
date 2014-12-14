
/**
* \file		tour.c
* \author	Tendry
* \date		26 Novembre 2014
* \brief	Contient le code source des fonctions concernant le module tour
*/

// #######################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <tour.h>
// #######################

Tour tour_init(Pion* p)
{
	// Création du tour
	Tour tour;

	// On alloue ce qui peut-être alloué
	tour.pion = p;
	tour.depart = position_init(p->position.x, p->position.y);
	tour.pile_coups=pileCoups_init();

	// on renvoie le tour initialisé
	return tour;
}

PileTours pileTours_init()
{
	// Création de la pile
	PileTours piletours;
	
	// Initialisation du premier élément
	piletours.premier = NULL;

	// renvoi de la pile prête
	return piletours;
	
}

Tour pileTours_depiler(PileTours* pile)
{
	//Pointeur pour manipuler le haut de la pile
	NoeudTour* tete = malloc(sizeof(NoeudTour));

	//Le tour qu'on cherche
	Tour tour;

	//Si la pile n'est pas vide
	if(pile->premier != NULL)
	{
		//On pointe sur l'élément en haut de la pile
		tete = pile->premier;

		//On récupère le tour
		tour = tete->tour;

		//Le haut de la pile est l'élément suivant
		pile->premier = tete->suivant;

		//On détruit le précédent haut de pile
		free(tete);
	}

	return tour;

}

void pileTours_ajouterTour(PileTours* pile, Tour tour)
{
	//L'élément ajouté à la pile
	NoeudTour* ajout = malloc(sizeof(NoeudTour));

	//On créé le noeud qui sera ajouté à la pile
	ajout->tour = tour;

	//On place l'élément précédent en dessous de celui ajouté
	ajout->suivant = pile->premier;

	//On indique bien que l'élément ajouté est la tête de la pile
	pile->premier = ajout;
}

void sauvegardeTour(Tour tour, char* emplacement_fichier_sauvegarde)
{
	NoeudCoup* actuel = tour.pile_coups.premier;
	FILE *fichier_contient_tour;
	fichier_contient_tour = fopen(emplacement_fichier_sauvegarde, "a");

	while(actuel != NULL)
	{
		sauvegardeCoup(actuel->coup, emplacement_fichier_sauvegarde);

		actuel = actuel -> suivant;

		if (fichier_contient_tour != NULL)
	    {	    
	    	fwrite(&tour.depart.x, sizeof(int) , 1, fichier_contient_tour);
	    	fwrite(&tour.depart.y, sizeof(int) , 1, fichier_contient_tour);
	    	fwrite (tour.pion , sizeof(Pion) , 1 , fichier_contient_tour);

			fclose(fichier_contient_tour);			
	    }

		else
	    {
	         printf("Impossible d'ouvrir le fichier sauvegarde.txt\n");
	    }
	}



}
