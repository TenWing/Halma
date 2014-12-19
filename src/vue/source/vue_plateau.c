
/**
* \file		vue_plateau.c
* \brief	Contient le code source du module vue_plateau
* \author	Tendry
* \date		29 Novembre 2014
*/

// ######################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <vue_plateau.h>
#include <position.h>
#include <modele.h>
// ######################

void affiche_plateau(Modele* modele, Mode mode)
{
	Plateau* plateau = &modele->plateau;
	// Variables de parcours
	int i = 0, j = 0;

	for(i = 0; i < plateau->matrice.nbLignes; i++)
	{
		// A chaque ligne on décale l'affichage
		printf("\t");
		for(j = 0; j < plateau->matrice.nbColonnes; j++)
		{
			Position position = position_init(i, j);
			affiche_case(modele, &position, mode);

		}
		printf("\n");

	}
}

void affiche_case(Modele* modele, Position* position, Mode mode)
{
	Plateau* plateau = &modele->plateau;

	int i = 0;

	// On récupère le contenu 
	Pion pion = plateau_getpion(plateau, *position);
	// S'il y a un pion à la position
	if(pion.identifiant != -1)
	{
		char affiche[2];

		// On adapte la taille de ce qui sera affiché
		if(pion.identifiant < 10)
			sprintf(affiche , "0%d", pion.identifiant);
		else
			sprintf(affiche, "%d", pion.identifiant);

		// On adapte la couleur !!
		char couleur[10];

		// Si le pion est selectionné alors il est mis en surbrillance
		if(pion.selectionne)
			sprintf(couleur,"%s", "\033[30m\033[47m");
		// Sinon il s'affiche normalement
		else
		{
			switch(pion.couleur)
			{
				case ROUGE:
					sprintf(couleur,"%s", "\033[30m\033[41m");
					break;

				case BLEU:
					sprintf(couleur,"%s", "\033[30m\033[44m");
					break;

				case VERT:
					sprintf(couleur,"%s", "\033[30m\033[42m");
					break;

				case JAUNE:
					sprintf(couleur,"%s", "\033[30m\033[43m");					
					break;

				default:
					break;		
			}
		}

		// On affiche la couleur
		printf("%s", couleur);

		// Puis le pion
		if(mode == SELECTION)
			printf("[%s]", affiche);
		else
			printf("[☯☯]");
	}
	else
	{
		// Si la case est vide
		Position* ptr = plateau_getVide(plateau, *position);
		// et est marquée
		if(ptr != NULL && ptr -> marque)
			// On affiche une portée
			printf("\033[39m[++]");

		// On affiche une case vide
		else
		{
			// On adapte la couleur !!
			char couleur[10];

			// Mais avant on va regarder si c'est une case dans une zone
			int taille = 0;
			if(modele->nombreJoueurs == 2)
				taille = 2;
			else
				taille = 4;

			Couleur color = FAIL;

			for(i = 0; i < taille; i++)
			{
				// Si la position est dans une zone de couleur alors on colorie la case
<<<<<<< HEAD
				/*if(position_dans_zone(*ptr, &modele->tableau_zone[i]))
=======
				if(position_dans_zone(*position, &modele->tableau_zone[i]))
>>>>>>> 67519d83d47f259b53805fe3dfea299a70039755
				{
					color = modele->tableau_zone[i].couleur_zone;

					switch(color)
					{
						case ROUGE:
							sprintf(couleur,"%s", "\033[31m");
							break;

						case BLEU:
							sprintf(couleur,"%s", "\033[34m");
							break;

						case VERT:
							sprintf(couleur,"%s", "\033[32m");
							break;

						case JAUNE:
							sprintf(couleur,"%s", "\033[33m");					
							break;

						default:
							break;		
					}
				}*/
			}

			// Si la case est dans une zone
			if(color != FAIL)
			{
				// On affiche la case de manière colorée à la zone
				printf("%s", couleur);
				printf("[  ]");

			}
			// sinon affichage normal
			else
				printf("\033[37m[  ]");
		}
	}

	// On remet la couleur par défaut
	printf("\033[0m");
}
