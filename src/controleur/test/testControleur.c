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
	printf("%c\n", recuperer_caractere());
	printf("%d\n", recuperer_entier());

	Plateau plateau;
	Joueur joueur_ROUGE;
	ListePions liste_pions;
	Pion pion;

	plateau = plateau_init(4);
	liste_pions = liste_pions_init();
	pion = pion_init(ROUGE, position_init(0,0), 3);
	liste_pions_ajout(&liste_pions, pion);
	
	joueur_ROUGE = joueur_init(&plateau, ROUGE);

	jouer_tour(&joueur_ROUGE);


	return 0;


}