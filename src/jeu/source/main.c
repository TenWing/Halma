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

//Inclusion du modele
#include <modele.h>

//Inclusion du controleur
#include <controleur.h>
#include <saisie.h>
#include <vue_plateau.h>
//###########################################

/**
* \brief Fonction principale du programme
* \author Tendry
* \version 1.0
* \return 0 exit success
*/
int main()
{
	char choix, choix2;
	int nombre_joueur,i;
	Controleur controleur;
	Couleur couleur;
	
	//Permettra de savoir quel joueur a gagné
	int victoire=0;

	clean_terminal();
	presentation_jeu();

	affiche_menu_principal();

	//Choix de l'une des 4 options du menu principal
	printf("Choix: ");
	choix=recuperer_caractere();

	while(choix != 'd')
	{	
		switch(choix)
		{
			//Le controleur a décidé de jouer au jeu
			case 'a' :
						clean_terminal();
						affiche_configuration_partie();
						printf("Choix: ");

						//On demande le nombre de joueur pour initialiser le jeu
						nombre_joueur = recuperer_entier();

						controleur = controleur_init(nombre_joueur);

						clean_terminal();

						//On affiche le tableau de départ
						affiche_plateau(&(controleur.modele.plateau), 0);

						//Tant qu'il n'y a pas de joueur gagnant
						while(victoire != 1)
						{
							//Les joueurs jouent chacuns à leur tour
							for(i=0; i<nombre_joueur; i++)
							{
								jouer_tour(&(controleur.modele.tableau_joueur[i]), &(controleur.modele));

								//Si l'un des joueur a placé tous ses pions dans la zone de victoire
								if(victoire == verification_zone(&(controleur.modele.tableau_zone[i]), &(controleur.modele.tableau_joueur[i])))
								{
									//i=8 va permettre de sortir de la boucle for
									i=8;

									//Permet de savoir quel joueur a gagné par rapport à sa couleur
									couleur= controleur.modele.tableau_joueur[i].couleur;
								}
							}
						}

						//On regarge la couleur du joueur gagnant et on le félicite
						switch(couleur)
						{
							case 0 :
								printf("\n\n\n Felicitation Joueur Rouge!\n");
								printf("Vous avez ecrasé vos concurrents!");
								break;
							case 1 :
								printf("\n\n\n Felicitation Joueur Bleu!\n");
								printf("Vous avez ecrasé vos concurrents!");
								break;
							case 2 :
								printf("\n\n\n Felicitation Joueur Vert!\n");
								printf("Vous avez ecrasé vos concurrents!");
								break;
							case 3 :
								printf("\n\n\n Felicitation Joueur Jaune!\n");
								printf("Vous avez ecrasé vos concurrents!");
								break;
							default :
								break;
						}

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