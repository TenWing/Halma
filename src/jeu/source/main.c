
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
						jouer_partie();
						break;
			case 'b' :
						clean_terminal();
						break;
			case 'c' :
						while(choix2 != 'y')
						{
							//Le controleur regarde les regles du jeu de l'halma
							clean_terminal();
							affiche_regles();
							printf("\nAppuyer sur la touche Y pour retourner au menu principal \n");
							choix2 = recuperer_caractere();
						}

						clean_terminal();

						affiche_menu_principal();
						printf("Choix: ");
						choix=recuperer_caractere();
						break;
			default  :
						clean_terminal();
						break;
		}
	}
	
	return 0;
}
