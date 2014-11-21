
/**
 * \file      modele.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit les fonctions pour modeliser le jeu de l'halma
 */

#ifndef MODELE_H
#define MODELE_H

 //######################################
//Inclusions
#include "../../../include/libMatrice/matrice.h"
#include "../header/position.h"
#include "../header/couleur.h"
#include "../header/pion.h"
#include "../header/joueur.h"
#include "../header/coup.h"
#include "../header/tour.h"
#include "../header/plateau.h"
//######################################

/**
 * \brief    Génère le plateau de jeu
 * \details  Permet de créer le plateau de jeu à partir des fonctions de la librairie matrice
 *             
 * \param    Plateau plateau
 * \return   Le plateau de jeu
 */
Plateau alloue_plateau(Plateau plateau);

 #endif