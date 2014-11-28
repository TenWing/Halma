/**
 * \file      plateau.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit le plateau
 * \details   Définit une matrice pour le plateau
 */


#ifndef PLATEAU_H
#define PLATEAU_H
#define Taille_plateau 16;
#define TAILLE_MAX 1000

//Inclusion des éléments nécessaires à notre structure
#include <matrice.h>
#include <pion.h>

/**
* \brief Un élément d'une liste de pions
* \auhtor Quentin
* \version 1.0
*/
typedef struct NoeudPion NoeudPion;
struct NoeudPion
{
	Pion pion;
	NoeudPion *suivant;
};

/**
* \brief une liste de pions
* \author Quentin
* \version 1.0
*/
typedef struct ListePions ListePions;
struct ListePions
{
	NoeudPion *premier;
};

/**
* \brief Le plateau où se déroule une partie
* \author Quentin
* \version 1.0
*/
typedef struct Plateau Plateau;
struct Plateau
{
	/**
	* \brief La matrice, tableau à 2 dimensions représentant le plateau physique
	* \see Matrice
	*/
 	Matrice matrice;

 	/**
 	* \brief la liste de tous les pions du jeu
 	* \see ListePions
 	*/
 	ListePions liste_pions;
};

/**
 * \brief    Génère le plateau de jeu
 * \details  Permet de créer le plateau de jeu à partir des fonctions de la librairie matrice
 *             
 * \param    Plateau plateau
 * \return   Le plateau de jeu
 */
Plateau plateau_init();

/**
 * \brief    Génère la liste des pions
 * \details  Permet de créer la liste des pions de l'ensemble du tableau
 * \author 	 Quentin          
 * \version  1.0
 * \return   La Liste des pions
 */
ListePions liste_pions_init();

/**
 * \brief    Ajoute un pion dans la liste des pions
 * \author 	 Quentin          
 * \version  1.0
 */
void liste_pions_ajout(ListePions* liste, Pion pion);

/**
* \brief 	Vérifie si la position choisie est un pion ou non
* \author 	Quentin
* \param	Position 	la position choisie
* \param	plateau 	le plateau où se situe l'ensemble des pions
* \version	1.0
* \return 	Un pion : soit un pion fictif avec des donnees seulement utiles pour le développeur, soit un pion du jeu
*/
Pion plateau_getpion(Plateau* plateau, Position position);

/**
* \brief indique si une position est en dehors de la zone de jeu
* \author Tendry
* \version 1.0
* \param pion la position testée
* \param plateau le plateau de jeu testé
* \return 1 si oui hors limite, 0 sinon
*/
int position_hors_plateau(Position* position, Plateau* plateau);

 #endif