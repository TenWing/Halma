// ###############################
// Inlcusions
#include <stdio.h>
#include <stdlib.h>
#include <controleur.h>
#include <saisie.h>
#include <vue_plateau.h>
#include <vue.h>
#include <mode.h>
// ###############################

/**
* \brief	fonction de test du cotrôleur
* \author	Tendry
*/
int main(void)
{

	// ##########################################
	// TEST MODULE SAISIE
	// ##########################################
	// printf("%c\n", recuperer_caractere());
	// printf("%d\n", recuperer_entier());

	// ##########################################
	// TEST MODULE CONTROLEUR 
	// ##########################################

	Controleur controleur = controleur_init(4);

//	affiche_plateau(&controleur.modele.plateau, AFFICHAGE);
//	affiche_plateau(&controleur.modele.plateau, SELECTION);

	controleur_jouer_tour(&controleur.modele.tableau_joueur[0], &(controleur.modele));

	

	return 0;


}