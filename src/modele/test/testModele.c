
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
#include <direction.h>
#include <plateau.h>
#include <joueur.h>
#include <zone.h>
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

	// ##########################################
	// TEST MODULE PLATEAU 
	// ##########################################

 	
 	Plateau plateau;

 	//on crée le plateau de jeu
 	plateau=plateau_init(2);
 	int i,j;

 	  for(i=0;i<16;i++) {

    for(j=0; j<16; j++) {

	printf("%c", plateau.matrice.donnees[i][j]);

    }
  printf("\n");
  }


 	// On teste si le plateau est bien un carré de 16x16
 	if(	plateau.matrice.nbLignes != 16 || plateau.matrice.nbColonnes != 16 )
 	{
 		printf("erreur de la définition de Taille_plateau\n");
 	}

 	else 
 	{
 		printf("Plateau fonctionnel\n");
 	}
 	
	// ##########################################
	// TEST MODULE POSITION
	// ##########################################

 	//On crée une position
	position=position_init(1,2);

	//On teste si les coordonnées sont les bonnes
 	if(	position.x != 1 || position.y != 2)
 	{
 		printf("erreur de la fonction position\n");
 	}

 	else 
 	{
 		printf("Fonction position OK. Abscisse : %d, ordonnée : %d\n", position.x, position.y);
 	}

	// ##########################################
	// TEST LISTE DE PIONS
	// ##########################################

 	//Initialisation de 2 pions
 	Pion pion3 = pion_init(ROUGE, position_init(16,15), 8);
 	Pion pion4 = pion_init(BLEU, position_init(16,16), 7);
  	Pion pion5 = pion_init(ROUGE, position_init(0,16), 10);

 	//Création de la liste de pions
 	ListePions liste_pions=liste_pions_init();

 	//Insertion des 2 pions dans la liste_pions
  	liste_pions_ajout(&liste_pions, pion5);
 	liste_pions_ajout(&liste_pions, pion3);
 	liste_pions_ajout(&liste_pions, pion4);

 	//Création d'un élément qui va se balader dans la liste
 	NoeudPion* actuel = liste_pions.premier;

 	//Dans que actuel n'a pas atteint l'élément NULL
 	while( actuel != NULL)
 	{
 		printf("x = %d, y = %d\n", actuel->pion.position.x, actuel -> pion.position.y);
 		//Actuel pointe sur l'élément suivant
 		actuel = actuel->suivant;
 	}

	// #########################################
	// TEST JOUEUR
	// #########################################

 	plateau = plateau_init(2);

	Joueur joueur1 = joueur_init(&plateau, JAUNE);
	Joueur joueur2 = joueur_init(&plateau, BLEU);	
	Pion* pion_test;

	printf("Id de pions : %d\n", joueur1.liste_references_pions.premier->pion->identifiant);
	printf("Id de pions : %d\n", joueur2.liste_references_pions.premier->pion->identifiant);


	pion_test=joueur_get_reference_pion(&joueur1, 25);

	if(pion_test != NULL)
	printf("%d\n", pion_test->identifiant);

	else
	printf("Le pointeur est nul\n");

	// #########################################
	// TEST ZONE
	// #########################################

	//Initialisation de la zone
	Zone zone = zone_init(ROUGE);

	//Initialisation position arbitraire
	Position position100=position_init(100,100);

	liste_positions_ajout(&zone.liste_positions, position100);

 	//Création d'un élément qui va se balader dans la liste
 	NoeudPosition* actuel_position = zone.liste_positions.premier;

 	//Dans que actuel n'a pas atteint l'élément NULL
 	while( actuel_position != NULL)
 	{
 		printf("x = %d, y = %d\n", actuel_position->position.x, actuel_position -> position.y);
 		//Actuel pointe sur l'élément suivant
 		actuel_position = actuel_position->suivant;
 	}

	return 0;

	// #########################################
	// TEST ANNULER
	// #########################################

	Modele modele = modele_init(2);	
	Pion* testeur = &modele.plateau.liste_pions.premier->pion;

	commencer_tour(&modele, testeur);
}

