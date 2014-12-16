
/**
 * \file      modele.c
 * \author    Geliot
 * \version   1.0
 * \date      19 Novembre 2014
 * \brief     Définit les fonctions pour jouer au jeu de l'Halma
 *
 * \details   Ces fonctions permettent de créer le jeu, pouvoir y jouer ...
 *            
 */

#include <stdio.h>
#include <stdlib.h>
#include <matrice.h>
#include <plateau.h>
#include <pion.h>
#include <unistd.h>
#include <zone.h>

/**
 * \brief    Génère le plateau de jeu
 * \details  Permet de créer le plateau de jeu à partir des fonctions de la librairie matrice
 * \param	 int nombre_joueur        
 * \param    Plateau plateau
 * \return   Le plateau de jeu
 */
Plateau plateau_init(int nombre_joueur) 
{
	Plateau plateau;
		
	// On initialise la liste
	plateau.liste_pions = liste_pions_init();

	plateau.vides = liste_positions_init();

	// On initialise avec les fichiers
	if(nombre_joueur == 4)
	{
		plateau.matrice = initMatrice("depart_jeu_halma_4.txt");
	}
	else
	{
		plateau.matrice = initMatrice("depart_jeu_halma_2.txt");
	}

	// On récupère les pions !
	int i =0, j = 0, id = 0;

	// On parcoure notre matrice
	for(i = 0; i < plateau.matrice.nbLignes; i++)
	{
		for(j = 0; j < plateau.matrice.nbColonnes; j++)
		{
			// S'il y a un pion
			if(plateau.matrice.donnees[i][j] != '.')
			{
				// Convertit bien le nombre récupéré en entier
				int number = plateau.matrice.donnees[i][j] - '0';
				
				// Récupération de la couleur
				Pion pion = pion_init(number, position_init(i, j), id);
				liste_pions_ajout(&plateau.liste_pions, pion);
				id++;
			}
			// Sinon on stocke la position vide
			else
			{
				liste_positions_ajout(&plateau.vides, position_init(i,j));
			}
		}
	}

	return plateau;
}

// JAMAIS JAMAIS ON NE MET QUELQUE CHOSE DANS UNE LISTE
// QUI SE CREE, ELLE EST VIDE !!! TOUJOURS !!!
ListePions liste_pions_init()
{
	// Création de la liste
	ListePions liste;
	
	// Le premier élément est nul
	liste.premier = NULL;

	return liste;
}

void liste_pions_ajout(ListePions* liste, Pion pion)
{
	//Création d'un nouvel élément
	NoeudPion* nouveau = malloc(sizeof(NoeudPion));

	if(nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Le noeud possède le pion comme valeur
	nouveau->pion = pion;
	nouveau->suivant = NULL;

	//Le premier élément de la liste
	if(liste->premier == NULL)
		liste -> premier = nouveau;
	// Après on ajoute à la fin
	else
	{
		// On parcoure la liste
		NoeudPion* tmp = liste -> premier;
		while(tmp -> suivant != NULL)
		{
			tmp = tmp -> suivant;
		}

		// On dit que le suivant du dernier est le dernier
		tmp->suivant = nouveau;
	}
}

Pion plateau_getpion(Plateau* plateau, Position position)
{
	// On quitte si un élément passé est nul (ERROR before exec)
	if (plateau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Pion pion;
	pion.identifiant = -1;

	// On va parcourir la liste des pions et si on ne trouve aucune position
	// Correspondant à un pion = à position alors il n'y a pas de pion a la position donnée

	// On prend le premier noeud de la liste
	NoeudPion* actuel = plateau->liste_pions.premier;

	// Si la liste est vide il n'y a pas de pions en jeu !
	if(actuel == NULL)
		return pion;

	// Tant qu'il y a des éléments dans la liste
	while(actuel != NULL)
	{	
		if(actuel->pion.position.x == position.x && actuel->pion.position.y == position.y)
		{
			pion = pion_copie(actuel->pion);
			return pion;
		}

		// passage au noeud suivant
		actuel = actuel->suivant;
	}

	// Aucun pion trouvé à cette position -1
	return pion;
}

Position* plateau_getVide(Plateau* plateau, Position position)
{
	// On récupère le premier noeud de la liste des noeuds
	NoeudPosition* noeud = plateau->vides.premier;

	// liste non vide
	if(noeud != NULL)
	{
		// Parcours de la liste
		while(noeud->suivant != NULL
			&& !position_egale(noeud->position, position))
		{
			noeud = noeud -> suivant;
		}

		// Renvoi du vide
		if(position_egale(noeud->position, position))
		{
			return &noeud->position;
		}
	}

	// Sinon renvoi de rien
	return NULL;
}

int position_hors_plateau(Position* position, Plateau* plateau)
{
	// On vérifie si on ne déborde pas du plateau en sautant
	if((position->x < 0 || position->x >= plateau->matrice.nbLignes)
		|| (position->y < 0 || position->y >= plateau->matrice.nbColonnes))
	{
		// Si jamais une de ces condition est vraie on est HORS LIMITES
		return 1;
	}
	else 
		return 0;
}

Plateau updateMatrice(Plateau* plateau)
{
	int i,j;


		for(i=0; i<plateau->matrice.nbLignes; i++)
		{
			for(j=0; j<plateau->matrice.nbColonnes; j++)
			{
				Position position = position_init(i,j);
				Pion pion = plateau_getpion(plateau, position);

				if(pion.identifiant != -1)
				{
					switch(pion.couleur)
					{
						case ROUGE :
							plateau->matrice.donnees[i][j] = '0';
							break;
						case BLEU :
							plateau->matrice.donnees[i][j] = '1';
							break;
						case VERT :
							plateau->matrice.donnees[i][j] = '2';
							break;
						case JAUNE :
							plateau->matrice.donnees[i][j] = '3';
							break;
						default :
							break;
					}
				}
				else
				{
					plateau->matrice.donnees[i][j] = '.';
				}
			}
		}

	return *plateau;
}

void sauvegardePlateau(Plateau plateau, char* emplacement_fichier_sauvegarde)
{
	sauvegardeMatrice(plateau.matrice, emplacement_fichier_sauvegarde);
}

Plateau chargerPlateau(char* emplacement_fichier)
{
	printf("%s\n", emplacement_fichier);
	Plateau plateau;

	// On initialise la liste
	plateau.liste_pions = liste_pions_init();

	plateau.vides = liste_positions_init();

	plateau.matrice = initMatrice(emplacement_fichier);
	printf("%s\n", emplacement_fichier);
	// On récupère les pions !
	int i =0, j = 0, id = 0;

	// On parcoure notre matrice
	for(i = 0; i < plateau.matrice.nbLignes; i++)
	{
		for(j = 0; j < plateau.matrice.nbColonnes; j++)
		{ 	
			// S'il y a un pion
			if(plateau.matrice.donnees[i][j] != '.')
			{
/*
				// Convertit bien le nombre récupéré en entier
				int number = plateau.matrice.donnees[i][j] - '0';
				
				// Récupération de la couleur
				Pion pion = pion_init(number, position_init(i, j), id);
				liste_pions_ajout(&plateau.liste_pions, pion);
				id++;*/
			}
			// Sinon on stocke la position vide
			else
			{
				//liste_positions_ajout(&plateau.vides, position_init(i,j));
			}
		}
	}

	return plateau;
}