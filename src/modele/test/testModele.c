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

#include <pion.h>
#include <matrice.h>
#include <modele.h>
#include <coup.h>

int main () 
{
	// ##########################################
	// TEST MODULE PION 
	// ##########################################

 	Position position;
 	position.x = 0;
 	position.y = 0;

 	//On crée deux pions la seule différence qu'ils ont c'est leur couleur et leur ID
 	Pion pion = pion_init(ROUGE, position, 1);
 	Pion pion2 = pion_init(ORANGE, position, 2);

 	printf("ID : %d, couleur : %d\n", pion.identifiant, pion.couleur);
 	printf("ID : %d, couleur : %d\n", pion2.identifiant, pion2.couleur);

 	//###########################################
 	//TEST MODULE COUP
 	//###########################################

 	//On empile 1 puis 2
 	printf("J'empile 1 puis 2\n");
 	Coup coup = coup_init(&pion, position);
 	Coup coup2 = coup_init(&pion2, position);
 	PileCoups pile = pileCoups_init();
 	pileCoups_ajouterCoup(&pile, coup);
 	pileCoups_ajouterCoup(&pile, coup2);

 	//Donc normalement on devrait lire 2 puis 1
 	printf("Je dépile\n");
 	printf("%d\n", pileCoups_depiler(&pile).pion->identifiant);
 	printf("%d\n", pileCoups_depiler(&pile).pion->identifiant);

	return 0;
}
