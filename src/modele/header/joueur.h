/**
 * \file      joueur.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit d'un joueur
 *
 * \details   Définit la structure d'un joueur par un ensemble de pions
 */
 
#ifndef JOUEUR_H
#define JOUEUR_H

//######################################
//Inclusions
#include <pion.h>
//######################################

/**
* \brief Un élément d'une liste de pions pour un joueur
* \auhtor Quentin
* \version 1.0
*/
typedef struct NoeudReferencePion NoeudReferencePion;
struct NoeudReferencePion
{
	Pion* pion;
	NoeudReferencePion* suivant;
};

/**
* \brief une liste de pions pour un joueur
* \author Quentin
* \version 1.0
* \details Il est nécessaire que la liste liste bien des
		   références vers les pions pour ne pas surcharger
		   la mémoire
*/
typedef struct ListeReferencePions ListeReferencePions;
struct ListeReferencePions
{
	NoeudReferencePion* premier;
};

 /**
* \brief  Un joueur, peut effectuer des actions
*		  mais n'est qu'une référence de liste et une couleur
* \auhtor Quentin
* \version 1.0
*/
typedef struct Joueur Joueur;
struct Joueur
{
	/**
	* \brief la couleur du joueur
	* \see Couleur
	*/
	Couleur couleur;

 	/**
	* \brief    Une liste de références de pions
	*/
 	ListeReferencePions liste_references_pions;
};

// ###################################
// FONCTIONS JOUEUR
// ###################################

/**
* \brief initialise un joueur à partir de sa couleur
* \author Tendry
* \param plateau le plateau qui contient tout 
* \param couleur la futur couleur du joueur
* \return un joueur initialisé
*/
Joueur joueur_init(Plateau* plateau, Couleur couleur);

// ###################################
// FONCTIONS REFERENCES PIONS
// ###################################

/**
* \brief initialise une liste de références vers les pions
* \author Tendry
* \return une liste initialisée
*/
ListeReferencePions liste_references_pions_init();

/**
* \brief ajoute une référence vers un pion à la liste
* \author Tendry
* \param liste la liste modifiée
* \param pion la référence ajoutée
* \version 1.0
*/
void liste_references_pions_ajout(ListeReferencePions* liste, Pion* pion);

/**
* \brief renvoie la référence d'un pion, si elle est nulle le joueur n'a pas ce pion
* \author Tendry
* \param Joueur* joueur 	Un joueur du jeu
* \param int indentifiant	un entier qui est l'identifiant d'un pion
* \version 1.0
*/
Pion* joueur_get_reference_pion(Joueur* joueur, int identifiant);

/**
* \brief renvoie le nombre de pion qu'à un joueur
* \author Tendry
* \param Joueur* joueur 	Un joueur du jeu
* \version 1.0
*/
int joueur_nombre_pions(Joueur* joueur);
#endif

