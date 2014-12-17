/**
* \file		intelligence.h
* \author	Tendry
* \brief	
* \version	1.0
*/

#ifndef INTELLIGENCE_H
#define	INTELLIGENCE_H

// #####################
// INLCUSIONS
#include <modele.h>
#include <direction.h>
#include <position.h>
#include <coup.h>
// #####################

/**
* \brief	Un coup possible avec sa valeur de poids pour
			pour indiquer s'il est favorable d'effectuer ce coup
* \author	Tendry
* \version	1.0
*/
typedef struct Possibilite Possibilite;
struct Possibilite
{
	/**
	* \brief 	le poids, ou intérêt du coup
	*/
	int poids;

	/**
	* \brief	la position du coup
	*/
	Position position;
};

/**
* \brief 	un noeud pour implémenter une liste de coups possibles
* \author	Tendry
* \version	1.0
*/
typedef struct NoeudPossibilite NoeudPossibilite;
struct NoeudPossibilite
{
	/**
	* \brief	une possibilité de coup
	*/
	Possibilite possibilite;

	/**
	* \brief	le noeud suivant
	*/
	NoeudPossibilite* suivant;
};

/**
* \brief 	Une liste de possibilités pour un bot
* \author	Tendry
* \version	1.0
*/
typedef struct ListePossibilites ListePossibilites;
struct ListePossibilites
{
	/**
	* \brief le poids d'une liste de coups possibles
	*		 (pour dire quel pion serait plus judicieux à déplacer)
	*/
	int poids;

	/**
	* \brief concerne un pion selectionné
	*/
	Pion pion;

	/**
	* \brief le premier noeud de la liste de possibilites
	*/ 
	NoeudPossibilite* premier;
};

/**
* \brief	Un noeud d'une liste de listes
* \author	Tendry
* \version	1.0
*/
typedef struct NoeudListe NoeudListe;
struct NoeudListe
{
	/**
	* \brief	la liste des coups possibles pour un pion
	*/
	ListePossibilites liste;

	/**
	* \brief 	le noeud suivant
	*/
	NoeudListe* suivant;
};

/**
* \brief	Contient l'ensemble de TOUS les coups possibles par
			une IA
* \author	Tendry
* \version	1.0
*/
typedef struct EnsemblePossibilites EnsemblePossibilites;
struct EnsemblePossibilites
{
	/**
	* \brief 	le premier noeud de la liste des listes
	*/
	NoeudListe* premier;
};

// #############################
// FONCTIONS POSSIBILITES

/**
* \brief	alloue une possibilité
* \author	Tendry
* \version	1.0
* \param	poids le poids du coup possible
* \param	position la position correspondant au coup
* \return	une possibilité initialisée
*/
Possibilite possibilite_init(int poids, Position position);

// #############################

// #############################
// FONCTIONS LISTE POSSIBILITEES

/**
* \brief	Initialise une liste de possibilités pour l'IA
* \author	Tendry
* \version	1.0
* \param	pion le pion qui concerne l'ensemble des possibilité de lui-même (INCEPTION)
* \return	Une liste bien allouée
*/
ListePossibilites liste_possibilites_init(Pion pion);

/**
* \brief	vide/détruit une liste de possibilités
* \author	Tendry
* \version	1.0
* \param	liste la liste réinitialisée
*/
void liste_possibilites_detruire(ListePossibilites* liste);

/**
* \brief	Ajoute une possibilité dans une liste de possibilités
* \author	Tendry
* \version	1.0
* \param	liste la liste modifiée
* \param	ajout l'élément ajouté
*/
void liste_possibilites_ajout(ListePossibilites* liste, Possibilite ajout);

// #############################

// #############################
// FONCTIONS ENSEMBLES POSSIBILITES

/**
* \brief	Initialise un ensemble de possibilités pour l'IA
* \author	Tendry
* \version	1.0
* \return	Une liste bien allouée
*/
EnsemblePossibilites ensemble_possibilites_init();

/**
* \brief	Ajoute une liste dans une liste de liste
* \author	Tendry
* \version	1.0
* \param	liste la liste modifiée
* \param	ajout l'élément ajouté
*/
void ensemble_possibilites_ajout(EnsemblePossibilites* liste, ListePossibilites ajout);

/**
* \brief	vide/détruit un ensemble de possibilités
* \author	Tendry
* \version	1.0
* \param	liste la liste réinitialisée
*/
void ensemble_possibilites_detruire(EnsemblePossibilites* liste);

// #############################

// #############################
// MACRO FONCTIONS

/**
* \brief	Fonction opaque qui fait jouer le coup à l'IA
* \author	Tendry
* \version 	1.0
* \param	modele le modele qui est le jeu en cours
* \param	joueur le joueur (IA) qui doit jouer le coup
*/
void ia_jouer_coup(Modele* modele, Joueur* joueur);

/**
* \brief	Construit l'ensemble des coups possible d'un joueur
* \author	Tendry
* \version	1.0
* \param	modele le modele qui est le jeu en cours
* \param	joueur le joueur (IA) qui doit jouer le coup
* \return	un ensemble de possibilités pour une IA
*/
EnsemblePossibilites construire_possibilites(Modele* modele, Joueur* joueur);

/**
* \brief	Construit l'ensemble des coups possible pour UN pion
* \author	Tendry
* \version	1.0
* \param	modele le modele qui est le jeu en cours
* \param	pion le pion qui sert à chercher les coups
* \param	joueur le joueur qui sait dans quelle direction il est plus favorable d'aller
* \return	un ensemble de possibilités pour un pion
*/
ListePossibilites possibilites_du_pion(Modele* modele, Pion pion, Joueur* joueur);

/**
* \brief	Crée une liste de coups que l'IA peut jouer
			ils sont sensés être les meilleurs en se basant
			sur le poids de chaque possibilité
* \author	Tendry
* \version	1.0
* \param	ensemble l'ensemble de TOUS les coups possibles par l'IA
*/
PileCoups recuperer_meilleurs_coups(EnsemblePossibilites* ensemble);

/**
* \brief	récupère un coup au hasard dans une liste de coups
* \author	Tendry
* \version	1.0
* \param	liste la liste de coups avec laquelle on travaille
* \return	un coup choisi au hasard
*/
Coup coup_au_hasard(PileCoups* liste);

// #############################

#endif