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

#include "position.h"
#include "couleur.h"


typedef(struct Pion, Pion);

 struct Pion {
 	int identifiant;
 	Position position;
 	Couleur couleur;
 };

typedef(struct Pions, Pions);

struct Pions {
	int totalPions; //total des pions de l'ensemble ( 9 ou 8 selon la partie jouée)
	Pion pion;
};

 #endif