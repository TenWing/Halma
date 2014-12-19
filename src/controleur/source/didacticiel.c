/**
* \file		didacticiel.c
* \brief	Contient le code source des fonctions du didacticiel
* \version 	1.0
* \date		18 Décembre 2114
*/

// #################################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <matrice.h>
#include <vue.h>
#include <vue_plateau.h>
#include <plateau.h>
#include <saisie.h>
#include <mode.h>
// #################################


void didacticiel()
{
	Modele modele;

	char choix;

	do
	{	
		clean_terminal();

		didacticiel_principal();

		choix=recuperer_caractere();

		if(choix == 'a')
		{
				clean_terminal();

				modele=modele_init(2,0,0);

				but_jeu();

				getchar();

				affiche_plateau(&modele, AFFICHAGE);

				printf("\n");

				modele=modele_init(2,0,0);
				modele.plateau=plateau_init(1,1);

				affiche_plateau(&modele,AFFICHAGE);

				printf("\n 		Voilà le joueur jaune à la place exacte du joueur bleu!!\n");
				printf(" 		Pas le joueur bleu.....\n");
				printf("		appuyer sur entree pour continuer\n");				

				getchar();
				clean_terminal();

				didacticiel_principal();
				choix=recuperer_caractere();
		}		
		else if(choix == 'b')
		{
				clean_terminal();

				modele=modele_init(2,0,0);
				modele.plateau=plateau_init(2,1);

				deplacements(1);

				printf("\n");
				printf(" 		appuyer sur entree pour faire défiler la suite\n");

				affiche_plateau(&modele, 1);

				getchar();

				modele.plateau=plateau_init(5,1);

				printf("\n");

				affiche_plateau(&modele, 1);

				printf("\n");
				printf(" 		On voit bien que le pion a fait un déplacement simple\n");
				printf("\n");

				deplacements(1);

				printf("\n");
				printf(" 		appuyer sur entree pour faire défiler la suite\n");

				getchar();

				clean_terminal();
				
				modele.plateau=plateau_init(6,1);

				printf("\n");

				affiche_plateau(&modele, 1);

				getchar();

				clean_terminal();

				modele.plateau=plateau_init(7,1);

				printf("\n");

				affiche_plateau(&modele, 1);

				getchar();

				clean_terminal();

				modele.plateau=plateau_init(8,1);

				printf("\n");

				affiche_plateau(&modele, 1);

				getchar();

				clean_terminal();

				modele.plateau=plateau_init(9,1);

				printf("\n");

				affiche_plateau(&modele, 1);

				getchar();

				clean_terminal();

				modele.plateau=plateau_init(10,1);

				printf("\n");

				affiche_plateau(&modele, 1);

				getchar();

				clean_terminal();

				modele.plateau=plateau_init(11,1);

				printf("\n");

				affiche_plateau(&modele, 1);

				printf("\n");

				printf("  		Voilà le déplacement par saut !!\n\n");
				didacticiel_principal();
				choix=recuperer_caractere();
		}
	}while(choix != 'c');
}