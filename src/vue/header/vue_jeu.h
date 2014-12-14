
/**
* \file 	vue_jeu.h
* \author	Tendry
* \brief	Définit les diverses indications qui s'afficheront
			pour aider l'utilisateur en jeu
* \version	1.0
* \date		6 Décembre 2014
*/

#ifndef VUE_JEU_H
#define VUE_JEU_H

/**
* \brief	Affiche ce qu'il est nécessaire de savoir
			pour la sélection d'un pion
* \author	Tendry
* \version	1.0
*/
void affiche_selection_pion();

/**
* \brief	Affiche les infos pour le choix de direction
* \author	Tendry
* \version	1.0
*/
void affiche_selection_direction();

/**
* \brief	Affiche un menu contextuel des actions du tour
* \param	entier 		tour qui change le menu selon l'avancée du tour
* \author	Tendry
* \version	1.0
*/
void affiche_menu_tour(int tour);

/**
* \brief	Affiche un menu contextuel des actions pendant un coup
* \author	Tendry
* \param	retour indique s'il est possible de revenir
			au menu de départ du tour
* \version	1.0
*/
void affiche_menu_coup(int coup);


/**
* \brief	Affiche ce que l'utilisateur peut faire dans le cas d'un échec
			de déplacement
* \author	Tendry
* \version	1.0
*/
void affiche_echec_deplacement();

/**
* \brief	Dit à l'utilisateur quel joueur doit jouer
* \author	Quentin
* \version	1.0
*/
void affiche_joueur(int couleur);

/**
* \brief	Dit à l'utilisateur qu'il n'a pas pris un de ces pions
* \author	Quentin
* \version	1.0
*/
void affiche_echec_pion();

/**
* \brief	Affiche qui a gagné !!!
* \author	Quentin
* \version	1.0
*/
void affichage_victoire();

/**
* \brief	Affiche un menu pour la sauvegarde
* \author	Quentin
* \version	1.0
*/
void affiche_sauvegarde();

#endif