
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
#include <tour.h>
#include <time.h>
// ###################################

Modele modele_init(int nombreJoueurs, int nombreIA, int charge)
{
	int i;

	// On se prépare a la distribution aléatoire de l'IA
	srand(time(NULL));

	// On Crée le modèle
	Modele modele;

	modele.nombreJoueurs = nombreJoueurs;
	modele.nombreIA = nombreIA;
	modele.plateau = plateau_init(nombreJoueurs, 0);
	modele.pile_tours = pileTours_init();
	modele.joueurJoue = 0;

	// On attribue le bon nombre de joueurs
	if(nombreJoueurs > 2)
	{
		for(i=0; i<4; i++)
		{
			modele.tableau_joueur[i] = joueur_init(&modele.plateau, i);		

			Direction destination;
			switch(i)
			{
				// Joueur en haut a gauche
				case 0:
					destination = BAS_DROITE;
					break;
				// Joueur en haut a droite
				case 1:
					destination = BAS_GAUCHE;
					break;
				// Joueur en bas à droite
				case 2:
					destination = HAUT_GAUCHE;
					break;
				// Joueur en bas à gauche
				case 3:
					destination = HAUT_DROITE;
					break;
			}
			modele.tableau_joueur[i].direction = destination;
			modele.tableau_zone[i] = zone_init(i, nombreJoueurs);
		}

		// Cas on veut jouer avec une(des) IA
		if(nombreIA > 0 && !charge)
		{	
			int indice = rand() % 4;
			int j = 0, done = 0;
			for(j = 0; j < nombreIA; j++)
			{
				done = 0;
				// Si ce n'est pas déja une ia
				if(!modele.tableau_joueur[indice].ia)
					modele.tableau_joueur[indice].ia = 1;
				else
				{
					// Sinon tant que c'est pas fait ben on cherche
					while(!done)
					{
						indice = rand() % 4;
						// Si ce n'est pas déja une ia
						if(!modele.tableau_joueur[indice].ia)
						{
							modele.tableau_joueur[indice].ia = 1;
							done = 1;
						}
					}
				}
			}
		}
	}
	else
	{
		modele.tableau_joueur[0] = joueur_init(&modele.plateau, 1);
		modele.tableau_joueur[0].direction = BAS_GAUCHE;		
		modele.tableau_zone[0] = zone_init(1, nombreJoueurs);


		modele.tableau_joueur[1] = joueur_init(&modele.plateau, 3);		
		modele.tableau_joueur[1].direction = HAUT_DROITE;		
		modele.tableau_zone[1] = zone_init(3, nombreJoueurs);

		// Cas on veut jouer avec une(des) IA
		if(nombreIA == 1 && !charge)
		{	
			modele.tableau_joueur[1].ia = 1;
		}
		else if(nombreIA == 2 && !charge)
		{
			modele.tableau_joueur[0].ia = 1;
			modele.tableau_joueur[1].ia = 1;
		} 
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

void sauvegarderModele(Modele* modele, FILE* emplacement_fichier_sauvegarde)
{
	//écrit le nombre de joueurs dans le fichier de sauvegarde
	fwrite(&modele->nombreJoueurs, sizeof(int), 1, emplacement_fichier_sauvegarde);

	// écrit le nombre d'IA dans le fichier de sauvegarde
	fwrite(&modele->nombreIA, sizeof(int), 1, emplacement_fichier_sauvegarde);

	// On stocke ensuite les id des joueurs qui sont IA
	int q = 0;
	for(q = 0; q < modele->nombreJoueurs; q++)
	{
		if(modele->tableau_joueur[q].ia)
			fwrite(&q, sizeof(int), 1, emplacement_fichier_sauvegarde);
	}

	//écrit quel joueur a sauvegardé
	fwrite(&modele->joueurJoue, sizeof(int), 1, emplacement_fichier_sauvegarde);

	//Déclaration d'un pointeur qui parcoura la pile de tours
	NoeudTour* actuel = modele->pile_tours.premier;

	//Déclaration d'un variable muette et d'un compteur
	int i, compteur=0;

	//Déclaration d'un modele qui aura pour but de retourner la pile d etours
	Modele factice;

	//On initialise la pile de tours
	factice.pile_tours = pileTours_init();

	//On parcourt la pile du vrai modele
	while(actuel != NULL)
	{
		//On compte le nombre de tours qu'il y a dans la pile
		compteur++;

		actuel = actuel -> suivant;
	}

	//On dépile les tours de la pile du vrai modele pour les empiler dans la pile du modele factice
	for (i = 0; i < compteur; i++)
	{
		pileTours_ajouterTour(&factice.pile_tours, pileTours_depiler(&modele->pile_tours));
	}

	//On crée un pointeur qui parcoura la pile de tours du faux modele
	NoeudTour* actuelFactice = factice.pile_tours.premier;

	//On écrit le nombre de tour qu'il y a dans le fichier de sauvegarde
	fwrite(&compteur, sizeof(int), 1, emplacement_fichier_sauvegarde);

	//On sauvegarde tous les tours dans l'ordre où ils ont été joué dans le jeu dans le fichier de sauvegarde
	while(actuelFactice != NULL)
	{
		sauvegardeTour(actuelFactice->tour, emplacement_fichier_sauvegarde);

		actuelFactice = actuelFactice -> suivant;
	}

	
}

Pion* modele_get_reference_pion(Modele* modele, Pion pion)
{
	//On crée un pointeur qui parcoura la liste de pions
	NoeudPion* actuel;
	actuel = modele -> plateau.liste_pions.premier;

	//On parcourt la liste de pions
	while(actuel != NULL)
	{
		//On vérifie la condition sur les identifiants
		if(pion.identifiant == actuel->pion.identifiant)
		{
			//S'ils sont égaux on retourne l'adresse du pion de la liste de pions
			return &actuel->pion;
		}

		actuel = actuel -> suivant;
	}

	//Sinon on retourne un pointeur nul
	return NULL;
}

void charger_tours(FILE* fp, Modele* modele)
{
	printf("Il est la\n");
	//On déclare une variable muette et un compteur et deux entiers inutiles 
	//(juste utilisés pour faire avancer le curseur dans le fichier de sauvegarde)
	int i,compteur=0, nb_joueur, nb_ia, a;

	//On initialise la pile de tours du modele
	modele->pile_tours = pileTours_init();

	// On lit le nb de joueur pour décaler le curseur
	fread(&nb_joueur, sizeof(int), 1, fp);

	// On lit le nb d'ia pour décaler le curseur
	fread(&nb_ia, sizeof(int), 1, fp);
	for(i=0; i < nb_ia; i++)
	{
		printf("read_ia\n");
		fread(&a, sizeof(int), 1, fp);
	}

	// Enfin on lit qui a sauvegardé la partie
	fread(&a, sizeof(int), 1, fp);
	
	//On lit dans le fichie de sauvegarde le nombre de tour
	fread(&compteur, sizeof(int), 1, fp);

	printf("Compteur : %d\n", compteur);

	//On ajoute tous les tours dans la pile du modele
	for(i=0; i<compteur; i++)
	{
		pileTours_ajouterTour(&modele->pile_tours, chargerTour(fp, modele));
	}
}

Zone* zone_de_direction(Modele* modele, Direction direction)
{
	int i = 0;

	for(i=0; i < 4; i++)
	{
		if(modele->tableau_zone[i].position == direction)
			return &modele->tableau_zone[i];
	}

	return NULL;
}