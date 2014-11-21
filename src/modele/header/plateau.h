/**
 * \file      plateau.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit le plateau
 * \details   Définit une matrice pour le plateau
 */

#ifndef PION_H
#define PION_H

#include "position.h"
#include "couleur.h"
#include "pion.h"

 typedef(struct Plateau, Plateau);

 struct Plateau {
 	Matrice matrice;
 	Pion pion;
 };

 #endif