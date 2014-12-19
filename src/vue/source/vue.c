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
	//printf("		La partie commencera juste après !\n");
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

void didacticiel_principal()
{
	printf("		########################################\n");
	printf("		||*------------DIDACTICIEL-----------*||\n");
	printf("		########################################\n");	
	printf("		Sélectionnez un des choix suivant\n");
	printf("		a. But du jeu de l'Halma\n");
	printf("		b. Deplacement\n");
	printf("		c. Revenir au menu principal du jeu!\n");
	printf("\n");
	printf("		Dans la suite du didacticiel, vous serez assimiler\n");
	printf("		à un joueur dans une partie 1V1.\n");
	printf("		Ce que vous verez dans le didacticiel est universel\n");
	printf("		au jeu de l'Halma. Peu importe le nombre de joueur\n");
	printf("		qui joue.\n");
	printf("		########################################\n");
}

void but_jeu()
{
	printf("\n\n");
	printf("		#####################################################\n");
	printf("		Nous allons voir le but du jeu de l'Halma\n");
	printf("\n");
	printf("		Nous supposerons que vous êtes le jouer jaune\n");
	printf("		Votre objectif est de placer vos pions exactement où \n");
	printf("		sont les pions du joueur bleu\n");
	printf("\n");
	printf("		Pour se faire, vous allez devoir déplacer vos pions... \n");
	printf("		Le tableau qui s'affichera vous montrera où doivent aller vos pions \n");
	printf("\n");
	printf("		Appuyer sur entrée pour continuer\n");
	printf("		#####################################################\n");

}

void deplacements(int deplacement)
{

	if(deplacement)
	{	
		printf("\n\n");
		printf("		#####################################################\n");
		printf("		Nous allons les déplacements du jeu de l'Halma\n");
		printf("\n");
		printf("		Il existe deux types de déplacements\n");
		printf("		1er : déplacement simple \n");
		printf("		2nd : déplacement par saut\n");
		printf("\n");

		printf("		Le déplacement simple\n");
		printf("		Le déplacement simple est un déplacement où le pion se déplace\n");
		printf("		d'une case dans la direction que vous aurez choisi.\n");
		printf("		Bin evidemment, il faut que la case où veut aller le pion soit libre\n");
	}

	else
	{
		printf("		Le déplacement par saut\n");
		printf("		Un pion peut sauter un autre pion qu'il soit de sa couleur ou non\n");
		printf("		La seule condition est que la case dérrière le pion soit libre\n");
		printf("\n");
		printf("		Si un pion a sauté un autre pion, il a le droit de sauter d'autres pions\n");
		printf("		s'il peut le faire\n");
		printf("\n");
		printf("		Des plateaux seront affichés pour que vous voyez ces deux déplacements\n");
		printf("		Appuyer sur entrée pour changer de tableau\n");
		printf("		#####################################################\n");
	}

}