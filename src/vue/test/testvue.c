
/**
*	\file	testvue.c
*	\brief	teste les fonctions d'affichage
* 	\author Tendry
*	\date	29 Novembre 2014
*/

// ######################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <vue.h>
#include <plateau.h>
#include <vue_plateau.h>
// ######################

/**
* \brief Fonction principale de test
* \author Tendry
* \version 1.0
* \return 0 exit success
*/
int main(void)
{
	Mode mode;
	Plateau plateau = plateau_init(2);

	affiche_plateau(&plateau, mode);

	printf("\n\n");

	pion_deplacer(&plateau.liste_pions.premier->pion, &plateau, BAS);

	affiche_plateau(&plateau, mode);

	presentation_jeu();
	affiche_menu_principal();
	affiche_configuration_partie();
	affiche_regles();
	return 0;
}
