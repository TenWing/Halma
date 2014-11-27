
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

	// ##########################################
	// TEST MODULE PLATEAU 
	// ##########################################

 	Plateau plateau;

 	//on crée le plateau de jeu
 	plateau=plateau_init(plateau);

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
	// TEST MODULE LISTE DE PIONS
	// ##########################################

 	Pion pion3, pion4;

 	//Initialisation de 2 pions
 	pion3 = pion_init(ROUGE, position_init(1,0), 8);
 	pion4 = pion_init(BLEU, position_init(1,1), 7);

 	//Création de la liste de pions
 	Liste *liste_pions=liste_pion_init();

 	//Insertion des 2 pions dans la liste_pions
 	insertion_pion(liste_pions, pion3);
 	insertion_pion(liste_pions, pion4);

 	//Création d'un élément qui va se balader dans la liste
 	Element* actuel;
 	actuel = liste_pions -> premier;

 	//Dans que actuel n'a pas atteint l'élément NULL
 	while( actuel != NULL)
 	{
 		//Actuel pointe sur l'identfiant de l'élément de la liste (ici dans l'ordre 7 8 1)
 		printf("%d\n", actuel->pion.identifiant);

 		//Actuel pointe sur l'élément suivant
 		actuel = actuel -> suivant;
 	}

	// ##########################################
	// TEST MODULE FONCTIONS GETPION
	// ##########################################

 	//On crée les paramètres pour tester la fonction getpion

 	//Pour tester pleinement la fonction, il faut changer les symboles * et .
 	plateau.matrice.donnees[1][1]='*';
 	Position position1;
 	position1=position_init(1,1);

 	//On regarde l'identifiant du pion. Si on affiche un -1, c'est que la position selectionnée n'est pas un pion.
 	//Sinon, elle retourne bien un identifiant d'un pion du jeu
	printf("%d\n", (plateau_getpion(position1,plateau,liste_pions).identifiant));

	return 0;
}
