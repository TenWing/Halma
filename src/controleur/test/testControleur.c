// ###############################
// Inlcusions
#include <stdio.h>
#include <stdlib.h>
#include <controleur.h>
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
	printf("%c\n", recuperer_caractere());
	printf("%d\n", recuperer_entier());

	// ##########################################
	// TEST MODULE CONTROLEUR 
	// ##########################################

	Controleur controleur = controleur_init(4);

	Joueur joueur_ROUGE = joueur_init(&(controleur.modele.plateau), ROUGE);

	jouer_tour(&joueur_ROUGE, &(controleur.modele));


	return 0;


}