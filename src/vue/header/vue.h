/**
* \file 		vue.h
* \author		Tendry
* \version		1.0
* \brief		Header du fichier vue.c
*/

#ifndef VUE_H
#define VUE_H

// ##########################
// INCLUSIONS
// ##########################

/**
* \brief 	affiche le menu principal
* \author	Tendry
* \details	Affiche le menu de configuration de partie, 
			charger et règles du jeu
* \version	1.0
*/
void affiche_menu_principal();

/**
* \brief	affiche l'ensemble des règles du jeu
* \author 	Tendry
* \version 	1.0
*/
void affiche_regles();

/**
* \brief	affiche ce qui est nécessaire pour configurer une partie
* \author	Tendry
* \version	1.0
*/
void affiche_configuration_partie();

/**
* \brief	affiche le nombre de bots à initialiser
* \author	Tendry
* \version	1.0
*/
void affiche_configuration_partie_bot();


/**
* \brief	affiche la présentation du jeu de l'Halma
* \author	Tendry
* \version	1.0
*/
void presentation_jeu();

/**
* \brief	rafraîchit le terminal
* \author	Tendry
* \version	1.0
*/
void clean_terminal();

/**
* \brief	Demande à l'utilisateur de saisir les choix imposés
* \author	Quentin
* \version	1.0
*/
void erreur_saisie();

/**
* \brief	Demande à l'utilisateur combien de coups à annuler
* \author	Quentin
* \version	1.0
*/
void nombre_coup();


#endif