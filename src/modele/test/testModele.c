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
#include <coup.h>

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

 	//###########################################
 	//TEST MODULE COUP
 	//###########################################
 	Position position;
 	position.x = 0;
 	position.y = 0;

 	//On crée deux pions la seule différence qu'ils ont c'est leur couleur et leur ID
 	Pion pion;
 	pion.couleur = ROUGE;//0
 	pion.identifiant = 1;
 	pion.position = position;

 	Pion pion2;
 	pion2.couleur = ORANGE;//5
 	pion2.identifiant = 2;
 	pion2.position = position;

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