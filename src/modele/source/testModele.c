/**
 * \file      testModele.c
 * \author    Geliot
 * \version   1.0
 * \date      19 Novembre 2014
 * \brief     Teste les fonctions de l'Halma
 *
 *
 *            
 */

#include <stdio.h>
#include <stdlib.h>

#include "../../../include/libMatrice/matrice.h"
#include "../header/position.h"
#include "../header/couleur.h"
#include "../header/pion.h"
#include "../header/joueur.h"
#include "../header/coup.h"
#include "../header/tour.h"
#include "../header/plateau.h"
#include "../header/modele.h"

 int main () 
 {
 	printf("0\n");
 	 	Plateau plateau;

 	plateau=init_plateau(plateau);

 	if(plateau.matrice.nbLignes != 16 && plateau.matrice.nbColonnes != 16)
 	{
 		printf("erreur de dimension\n");
 	}

 	else
 	{
 		printf("plateau créer\n");
 	}



 return 0;}