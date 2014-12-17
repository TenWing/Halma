



/**
* \file 		vue.c
* \author		Tendry
* \version		1.0
* \brief		Fichier de gestion de l'affichage
* \details		La vue observe le modele et s'occupe d'afficher les informations
*/

#include <stdio.h>
#include <stdlib.h>

void affiche_menu_principal()
{
	printf("		########################################\n");
	printf("		||*----------MENU PRINCIPAL----------*||\n");
	printf("		########################################\n");
	printf("		____Menu principal du jeu de l'Halma____\n");
	printf("		a. Commencer une nouvelle partie\n");
	printf("		b. Charger une partie\n");
	printf("		c. Afficher les règles du jeu\n");
	printf("		d. Quitter\n");
	printf("		########################################\n");
}

void affiche_regles()
{
	printf("		########################################\n");
	printf("		||*----------REGLES DU JEU-----------*||\n");
	printf("		########################################\n");
	printf("		Chaque joueur se voit attribuer une couleur\n");
	printf("		Les pions de la couleur du joueur doivent\n");
	printf("		tous aller du côté opposé à leurs positions\n");
	printf("		de départ pour que le joueur gagne.\n\n");
	printf("		Chaque pion peut se déplacer d'un pas sur\n");
	printf("		une case inoccupée, mais il peut aussi sauter\n");
	printf("		par dessus n'importe quel pion !\n\n");
	printf("		Lorsqu'il saute, il peut enchaîner les sauts\n");
	printf("		tant que c'est possible, le joueur décide\n");
	printf("		quand le déplacement s'achève afin d'appliquer\n");
	printf("		la meilleure stratégie pour pouvoir être\n");
	printf("		le premier à apporter tous ses pions dans la\n");
	printf("		zone de victoire !\n");
	printf("		########################################\n");	
}

void affiche_configuration_partie()
{
	printf("		########################################\n");
	printf("		||*-------CONFIGURATION PARTIE-------*||\n");
	printf("		########################################\n");	
	printf("		Sélectionnez le nombre de joueurs!\n");
	printf("		Le nombre de joueurs varie entre 1 et 4 joueurs\n");
	printf("		La partie commencera juste après !\n");
	printf("		########################################\n");	
}

void affiche_configuration_partie_bot()
{
	printf("		########################################\n");
	printf("		||*-------CONFIGURATION PARTIE-------*||\n");
	printf("		########################################\n");	
	printf("		Sélectionnez le nombre de bots à ajouter!\n");
	printf("		Soit 1 pour une partie 1V1\n");
	printf("		Soit 3 pour une partie chacun pour soi\n");
	printf("		Soit 0 : Vous êtes assez de joueurs physiques\n");
	printf("		La partie commencera juste après !\n");
	printf("		########################################\n");
}

void presentation_jeu()
{
	printf("\n\n");
	printf("		#####################################################\n");
	printf("		####  ||  || ||||||| ||     ||||   |||| |||||||  ####\n");
	printf("		####  ||  || ||   || ||     || || || || ||   ||  ####\n");
	printf("		####  ||  || ||   || ||     ||   |   || ||   ||  ####\n");
	printf("		####  |||||| ||||||| ||     ||       || |||||||  ####\n");
	printf("		####  ||  || ||   || ||     ||       || ||   ||  ####\n");
	printf("		####  ||  || ||   || ||     ||       || ||   ||  ####\n");
	printf("		####  ||  || ||   || |||||| ||       || ||   ||  ####\n");
	printf("		#####################################################\n");
	printf("\n\n\n\n\n");
}

void clean_terminal()
{
	system("clear");
}

void erreur_saisie()
{
	printf("		Veuillez rentrer les caractères qui vous sont demandés !\n");
}

void nombre_coup()
{
	printf("		Nombre de coups à annuler : ");
}


