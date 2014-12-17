
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
#include <pion.h>
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

void sauvegardeTour(Tour tour, FILE* emplacement_fichier_sauvegarde)
{
	//On déclare un coup qui se deplacera dans la pile de coup
	NoeudCoup* actuel = tour.pile_coups.premier;

	//On déclare un compteur et une varible muette
	int i,compteur=0;

	//On crée un tour factice pour la pile de coups
	Tour factice;

	//On initialise la pile de coups du tour factice
	factice.pile_coups=pileCoups_init();

	//On compte le nombre de coup qu'il y a dans le tour que l'on veut sauvegarder
	while(actuel != NULL)
	{
		compteur++;

		actuel = actuel -> suivant;
	}

	//On dépile le nombre de coups dans le tour et on les empile tout de suite dans la pile du tour factice
	for (i = 0; i < compteur; i++)
	{
		pileCoups_ajouterCoup(&factice.pile_coups, pileCoups_depiler(&tour.pile_coups));
	}

	//On créé un coup qui va se déplacer dans la pile de coup du tour factice
	NoeudCoup* actuelFactice = factice.pile_coups.premier;

	//On écrit le nombre de coup dans la pile de coup du tour
	fwrite(&compteur, sizeof(int), 1, emplacement_fichier_sauvegarde);

	//On sauvegarde tous les coups dans le fichier texte dans l'ordre où ils ont été joué
	while(actuelFactice != NULL)
	{
		sauvegardeCoup(actuelFactice->coup, emplacement_fichier_sauvegarde);

		actuelFactice = actuelFactice -> suivant;
	}
	   
	//On déclare un pion qui prend la valeur du pointeur de pion dans le tour
	Pion p = *tour.pion;

	//On stocke la position de depart du pion, et les données du pointeur de pion
	fwrite(&tour.depart.x, sizeof(int), 1, emplacement_fichier_sauvegarde);
	fwrite(&tour.depart.y, sizeof(int), 1, emplacement_fichier_sauvegarde);
	fwrite(&p, sizeof(Pion), 1, emplacement_fichier_sauvegarde);

}

Tour chargerTour(FILE* emplacement_fichier, Modele* modele)
{
	//On déclare un tour, un pion, un compteur et une variable muette
	Tour tour;
	Pion p;
	int compteur,i;

	//On initialise la pile de coups du tour
	tour.pile_coups = pileCoups_init();

	//On charge le nombre de coup du tour
	fread(&compteur, sizeof(int), 1, emplacement_fichier);

	//On empile le nombre de coups qu'il y avait dans le tour sauvegarder
	for (i = 0; i < compteur; i++)
	{
		pileCoups_ajouterCoup(&tour.pile_coups, chargerCoup(emplacement_fichier));
	}
	
	//On charge la position de depart du pion et les données du pointeur de pion
	fread(&tour.depart.x, sizeof(int), 1, emplacement_fichier);
	fread(&tour.depart.y, sizeof(int), 1, emplacement_fichier);
	fread(&p, sizeof(Pion), 1, emplacement_fichier);

	//On stocke dans le pointeur de pion dans tour les données precedemment chargées
	tour.pion = modele_get_reference_pion(modele, p);

	printf("x : %d, y : %d\n", tour.pion ->position.x, tour.pion->position.y);


	//On retourne le tour
	return tour;
}


PileTours inversePile(PileTours pile_tours)
{

	PileTours pile_inverser = pileTours_init();

	NoeudTour* actuel = pile_tours.premier;

	while(actuel != NULL)
	{
		pileTours_ajouterTour(&pile_inverser, actuel->tour);
		
		actuel = actuel -> suivant;
	}

	return pile_inverser;
}