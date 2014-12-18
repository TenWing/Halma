

/**
* \file 		main.c
* \author		Tendry
* \version		1.0
* \brief		Fichier principal du programme
* \details		Appelle la structure MVC du code, en soit, est juste le point de départ de l'appli
*/

#include <stdio.h>
#include <stdlib.h>

//INCLUDES
//###########################################
//Inclusion de la bibliothèque matrice
#include <matrice.h>

//Inclusion de la vue
#include <vue.h>

//Inclusion du modele
#include <modele.h>

//Inclusion du controleur
#include <controleur.h>
#include <saisie.h>
#include <vue_plateau.h>
#include <didacticiel.h>
//##########################################

/**
* \brief Fonction principale du programme
* \author Tendry
* \version 1.0
* \return 0 exit success
*/
int main()
{
	char choix='l';
	char choix2;

	while(choix != 'd')
	{	
			clean_terminal();
		presentation_jeu();

		affiche_menu_principal();

		//Choix de l'une des 4 options du menu principal
		printf("Choix: ");
		choix=recuperer_caractere();

		switch(choix)
		{
			//Le controleur a décidé de jouer au jeu
			case 'a' :
						jouer_partie(1);
						break;
			case 'b' :
						
						jouer_partie(0);
						break;
			case 'c' :
						
							//Le controleur regarde les regles du jeu de l'halma
							clean_terminal();
							affiche_regles();
							printf("Si vous voulez lancer le didacticiel, appuyer sur : a\n");
							printf("\nSinon appuyer sur une touche pour retourner au menu principal \n");
							choix2 = recuperer_caractere();

							if(choix2 == 'a')
							{
								didacticiel();
							}
		
						break;
			default  :
						clean_terminal();
						break;
		}
	}
	
	return 0;
}
