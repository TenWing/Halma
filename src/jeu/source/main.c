/**
* \file 		main.c
* \author		Tendry
* \version		1.0
* \brief		Fichier principal du programme
* \details		Appelle la structure MVC du code, en soit, est juste le point de départ de l'appli
*/

#include <stdio.h>
#include <stdlib.h>

//INCLUDES
//###########################################
//Inclusion de la bibliothèque matrice
#include "../../../include/libMatrice/matrice.h"

//Inclusion de la vue
#include "../../vue/header/vue.h"
//###########################################

/**
* \brief Fonction principale du programme
* \author Tendry
* \version 1.0
* \return 0 exit success
*/
int main()
{
	Matrice m = alloue(5,5);
	affiche();
	printf("%d tu pues du cul\n", m.nbLignes);
	return 0;
}