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

<<<<<<< HEAD

#include <pion.h>
=======
#include <matrice.h>
#include <modele.h>
>>>>>>> ccd8a93946359553769c40db6785730decfb506c
#include <coup.h>

 int main () 
 {
 
<<<<<<< HEAD
Pion pion;
pion.position.x=7;
pion.position.y=7;

printf("x=%d\n", pion.position.x);
printf("y=%d\n", pion.position.y);

pion=init_pion(1,1,2,0);

printf("x=%d\n", pion.position.x);
printf("y=%d\n", pion.position.y);

pion=coupSimple(pion,0,0);

printf("x=%d\n", pion.position.x);
printf("y=%d\n", pion.position.y);
if(pion.position.x != 0 || pion.position.y != 0)
{
	printf("erreur de la fonction coupSimple\n");
}
else
{
	printf("ca fonctionne\n");
}
=======
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
>>>>>>> ccd8a93946359553769c40db6785730decfb506c

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
