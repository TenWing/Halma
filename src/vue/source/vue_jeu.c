
/**
* \file		vue_jeu.c
* \author	Tendry
* \version	1.0
* \brief	contient le code source des fonctions d'affichage pendant une partie
* \date		6 Décembre 2014
*/

//######################################
//Inclusions
#include <vue_jeu.h>
#include <stdio.h>
#include <stdlib.h>
//######################################

void affiche_selection_pion()
{
	printf("		########################################\n");
	printf("		__________Sélectionnez un pion__________\n");
	printf("		Entrez un numéro correspondant à l'identifiant\n");
	printf("		du pion que vous souhaitez sélectionner.\n");
	printf("		########################################\n");
}

void affiche_selection_direction()
{
	printf("		########################################\n");
	printf("		_______Sélectionnez une direction_______\n");
	printf("		Entrez la direction dans laquelle doit aller\n");
	printf("		le pion, sur le pavé numérique ceci correspond.\n");
	printf("		aux touches flechées :\n");
	printf("		7		^8^		9\n");	
	printf("		<4				6>\n");
	printf("		1		v2v		3\n");		
	printf("		########################################\n");
}

void affiche_menu_commencer_tour()
{
	printf("		########################################\n");
	printf("		||*----------DEBUT DE TOUR-----------*||\n");
	printf("		########################################\n");
	printf("		a. Sélectionner un pion\n");
	printf("		b. Revenir à votre tour précédent\n");
	printf("		c. Sauvegarder la partie\n");
	printf("		d. Fin de votre tour\n");
	printf("		########################################\n");
}

void affiche_menu_coup(int retour)
{
	printf("		########################################\n");
	printf("		||*-----------JOUER UN COUP----------*||\n");
	printf("		########################################\n");
	printf("		a. Déplacer le pion\n");
	printf("		b. Revenir au coup précédent\n");
	printf("		c. Sauvegarder la partie\n");
	printf("		d. Fin du(es) déplacement de votre pion\n");
	
	if(retour)
	printf("		e.Changer de pion\n");
	
	printf("		########################################\n");
}

void affiche_echec_deplacement()
{
	printf("		#################################################\n");
	printf("		Vous n'avez pas réussi à vous déplacer, \n");
	printf("		Changer de pion ou retenter une autre direction ?\n");
	printf("		a. changer de pion\n");	
	printf("		b. changer de direction\n");
	printf("		#################################################\n");
}

void affiche_joueur(int couleur)
{
	switch(couleur)
	{
		case 0 :
			printf("\n");
			printf("			########################\n");
			printf("			||*---JOUEUR ROUGE---*||\n");
			printf("			########################\n");
			printf("\n");
			break;
		case 1 :
			printf("\n");
			printf("			#######################\n");
			printf("			||*---JOUEUR BLEU---*||\n");
			printf("			#######################\n");
			printf("\n");
			break;
		case 2 :
			printf("\n");
			printf("			#######################\n");
			printf("			||*---JOUEUR VERT---*||\n");
			printf("			#######################\n");
			printf("\n");
			break;
		case 3 :
			printf("\n");
			printf("			########################\n");
			printf("			||*---JOUEUR JAUNE---*||\n");
			printf("			########################\n");
			printf("\n");
			break;
		default :
			break;
	}
}

void affiche_echec_pion()
{
	printf("		###############################################\n");
	printf("		Vous n'avez pas sélecionner l'un de vos pions!\n");
	printf("		Veuillez rentrer un identifiant de vos pions!\n");
	printf("		###############################################\n");
}