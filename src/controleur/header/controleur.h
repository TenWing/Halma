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
*/
Controleur controleur_init(int nombreJoueurs);

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
* \brief 	Sauvegarde une partie
* \author	Quentin
* \param	Matrice 	la matrice du jeu de l'halma
* \param	pointeur : emplacement_fichier_sauvegarde	là où le fichier contenant la matrice
* \param 	choix 		si la sauvegarde est en décimale ou binaire
* \version	1.0
* \return 	1 si succès 0 si échec
*/
int SauvegardeMatrice(Matrice matrice, char *emplacement_fichier_sauvegarde, int choix);

/**
* \brief 	Charge une partie
* \author	Quentin
* \param	pointeur : emplacement_fichier_	là où le fichier contenant la matrice
* \param 	choix 		si le chargement doit être en décimale ou binaire
* \version	1.0
* \return 	la matrice qui est en fait le plateau du jeu de l'halma
*/
Matrice chargerMatrice(char *emplacement_fichier, int choix);

Controleur controleur_charger();
