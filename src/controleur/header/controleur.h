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
* \param	modele le moteur de jeu pour jouer le coup
*/
void controleur_jouer_tour(Joueur* joueur, Modele* modele);

/**
* \brief	sous fonction permettant de jouer un coup
* \author	Tendry
* \version	1.0
* \param	joueur le joueur qui joue le tour
* \param	modele le moteur de jeu pour jouer le coup 
*/
int controleur_jouer_coup(Joueur* joueur, Modele* modele, Pion* pion);

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
* \param	nombreIA	le nombre de joueurs IA
*/
Controleur controleur_init(int nombreJoueurs, int nombreIA);

/**
* \brief 	Fait sélectionner un pion par le joueur courant
* \author	Tendry
* \param	joueur le joueur qui sélectionne un de ses pions
* \param	pion le pion qui sera selectionné
* \version 	1.0
* \return	1 si succès 0 si échec
*/
int selectionner_pion(Modele* modele, Joueur* joueur, Pion** pion);

/**
* \brief 	Demande à l'utilisateur une direction
* \author	Tendry
* \param	direction la direction qui sera choisie
* \version	1.0
* \return	1 si succès 0 si échec
*/
int selectionner_direction(Modele* modele, Direction* direction);

/**
* \brief 	Lance une partie du jeu
* \author	Quentin
*/
void jouer_partie(int jouer);

/**
* \brief 	Charge le controleur
* \author	Quentin
* \version	1.0
* \return 	le controleur chargé
*/
Controleur controleur_charger();
