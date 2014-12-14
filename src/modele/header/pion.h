
/**
 * \file      pion.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit un pion et un ensemble de pion
 *
 * \details   Définit la structure d'un pion et d'une structure pour un ensemble de pions
 */
 
#ifndef PION_H
#define PION_H

 //######################################
//Inclusions
#include <position.h>
#include <couleur.h>
#include <direction.h>
 //######################################

typedef struct Plateau Plateau;
struct Plateau;

/**
* \brief Un pion, un élément de jeu du plateau
* \author Quentin
* \version 2.0
*/
typedef struct Pion Pion;
struct Pion
{
	/**
	* \brief chaque pion est identifié par un ID unique
	*/
 	int identifiant;

 	/**
 	* \brief La position du pion sur le plateau
 	* \see Position
 	*/
 	Position position;

 	/**
 	* \brief La couleur du pion
 	* \see Couleur
 	*/
 	Couleur couleur;

 	/**
 	* \brief indique si le pion est entrain d'effectuer des sauts ou non
 	*/
 	int saut;

 	/**
 	* \brief indique si le pion a été selectionné par le joueur
 	*/
 	int selectionne;
};

/**
 * \brief    Génère un pion
 * \details  Permet de créer un pion (son identifiant, sa position et sa couleur)
 * \author	 Tendry        
 * \param    couleur la couleur du pion
 * \param	 position la position par défaut du pion
 * \version  2.0
 * \return   Le pion initialisé
 */
Pion pion_init(Couleur couleur, Position position, int identifiant);

/**
* \brief	permet de copier un pion
* \author 	Tendry
*/
Pion pion_copie(Pion pion);

/**
* \brief	déplace un pion sur la grille
* \author 	Tendry
* \param	pion 		le pion qui sera déplacé
* \param 	plateau 	le plateau (la grille de jeu)
* \param 	direction 	la direction dans laquelle le pion se déplace
* \details	Gère les déplacements complexes via des sous fonctions (saut de pion etc.)	
* \return 	1 Si le déplacement s'est bien effectué, 0 pour déplacement raté
*/
int pion_deplacer(Pion* pion, Plateau* plateau, Direction direction);

/**
* \brief 	fait sauter un pion
* \author	Tendry
* \version 	1.0
* \param	pion le pion qui saute
* \param	direction la direction
*/
int pion_sauter(Pion* pion, Direction direction, Plateau* plateau);

/**
<<<<<<< HEAD
* \brief	marque les positions autour du pion où celui-ci peut se rendre
* \author	Tendry
* \version	1.0
* \param	pion le pion qui sert à marquer les positions
* \param	plateau le plateau qui contient toutes les positions
*/
void pion_marquer(Pion* pion, Plateau* plateau);

/**
* \brief	marque les positions possible de déplacement autour du pion pour un direction donnée
* \author	Tendry
* \version	1.0
* \param	pion le pion qui sert à marquer les positions
* \param	plateau le plateau qui contient toutes les positions
* \param	direction la direction dans laquelle on teste les déplacements
*/
void pion_analyse_marquage_direction(Pion* pion, Plateau* plateau, Direction direction);

/**
* \brief 	sauvegarde un pion dans un fichier texte
* \author	Quentin
* \version 	1.0
* \param	pion 	le pion a sauvegardé
* \param	emplacement_fichier_sauvegarde
*/

void sauvegardePion(Pion pion, char* emplacement_fichier_sauvegarde);

 #endif