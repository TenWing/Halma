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

#include <matrice.h>
#include <modele.h>

 int main () 
 {
 
  	Plateau plateau;

 	plateau=alloue_plateau(plateau);

 	if(plateau.matrice.nbLignes != 16 && plateau.matrice.nbColonnes != 16)
 	{
 		printf("erreur de dimension\n");
 	}

 	else
 	{
 		printf("plateau créer\n");
 	}



 return 0;}