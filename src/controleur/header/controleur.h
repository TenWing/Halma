/**
* \file		controleur.h
* \brief	Contient les prototypes des fonctions de contrôle
* \version 	1.0
* \date		01 Décembre 2014
*/

// #################################
// INCLUSIONS
#include <vue.h>
#include <modele.h>
// #################################

/**
* \brief Un contrôleur du jeu de l'Halma
* \author Quentin
* \version 1.0
*/
typedef struct Controleur Controleur;
struct Controleur
{
	/**
 	* \brief Le modele du jeu de l'Halma
 	* \see Modele
 	*/
	Modele modele;

	/**
 	* \brief le nombre de joueurs 
 	*/
 	int nombreJoueurs;
};
/**
* \brief 	permet de jouer un tour de jeu complet
* \author 	Tendry
* \param	joueur le joueur qui joue le tour
*/
void jouer_tour(Joueur* joueur, Modele* modele);

/**
* \brief 	permet de supprimer '\n' d'une chaine
* \author 	Quentin
* \param	chaine la chaine où l'on veut enlever '\n'
*/
void clean(char* chaine);

/**
* \brief 	permet d'initialiser le controleur du jeu de l'halma
* \author 	Quentin
* \param	nombreJoueurs	le nombre de joueurs qui veut jouer au jeu de l'Halma
*/
Controleur controleur_init(int nombreJoueurs);