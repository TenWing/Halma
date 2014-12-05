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
#include "../../../include/libMatrice/matrice.h"

//Inclusion de la vue
#include <vue.h>
//###########################################

/**
* \brief Fonction principale du programme
* \author Tendry
* \version 1.0
* \return 0 exit success
*/
int main()
{
	Matrice m = alloue(5,5);
	printf("%d tu pues du cul\n", m.nbLignes);

	/*	char choix;
	int nombre_joueur;

	presentation_jeu();

	affiche_menu_principal();

	choix=saisir_caractere();

	switch(choix)
	{
		case 'a' :
					clean_terminal();
					affiche_configuration_partie();

					nombre_joueur = recuperer_entier();

					switch(nombre_joueur)
					{
						case 2 :
									controleur_init(nombre_joueur);
									clean_terminal();
									break;
						case 4 :
									controleur_init(nombre_joueur);
									clean_terminal();
									break;
						default  :
									erreur_saisie();
									affiche_configuration_partie();
									nombre_joueur = recuperer_entier();
									clean_terminal();
									break;
					}

					break;
		case 'b' :
					clean_terminal();
					break;
		case 'c' :
					clean_terminal();
					break;
		case 'd' :
					clean_terminal();
					break;
		default  :
					clean_terminal();
					break;
	}

	*/
	return 0;
}