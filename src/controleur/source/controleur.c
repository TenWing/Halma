/**
* \file		controleur.c
* \brief	Contient le code source des fonctions de contrôle
* \version 	1.0
* \date		01 Décembre 2014
*/

// #################################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <vue.h>
#include <modele.h>
#include <string.h>
#include <saisie.h>
#include <controleur.h>
#include <direction.h>
// #################################

Controleur controleur_init(int nombreJoueurs)
{
	Controleur controleur;

	controleur.nombreJoueurs = nombreJoueurs;

	controleur.modele = modele_init(nombreJoueurs);

	return controleur;
}

void jouer_tour(Joueur* joueur, Modele* modele)
{
	// Le pion qui jouera
	Pion* pion = NULL;

	// La direction qu'il prendra
	//Direction direction;

	// int deplacement=1, jouer=1;
	// char demande_fin_tour, demande_annuler_coup, demande_garder_pion;
	// int pave_numerique;

	// On demande à l'utilisateur de sélectionner
	// ABSOLUMENT un pion
	while(!selectionner_pion(joueur, &pion));	

	commencer_tour(modele, pion);
	/*
	// Tant que l'utilisateur DOIT jouer
	while(jouer)
	{
		// L'utilisateur DOIT choisir une direction
		while(!selectionner_direction(&direction));

		// Ensuite il joue le coup
		deplacement = jouer_coup(modele, pion, direction_souhaitee(pave_numerique));
		
		// S'il n'a pas réussit à jouer du tout :(
		if(deplacement == 0 && pion->saut == 0)
		{	
			printf("déplacement impossible\n");
			printf("Voulez vous garder votre pion : Y/N\n");
			//On demande si le joueur veut garder son pion ou non
			demande_garder_pion = recuperer_caractere();
			
			if(demande_garder_pion == 'y')
				jouer = 1;
			else
			{	//On demande au joueur de selectionner un pion avec son identifiant
				printf("saisir l'identifiant d'un pion\n");
				//On récupère un identifiant d'un pion
				identifiant=recuperer_entier();
					//On vérifie que l'identifiant correspond à un pion du joueur
				pion = joueur_get_reference_pion(joueur, identifiant);
				jouer = 1;
			}
		}

		if(pion->saut == 0 && deplacement == 1)
		{
			printf("Fin du tour ? Y/N\n");
			//Demande si c'est la fin du tour
			demande_fin_tour = recuperer_caractere();
			if(demande_fin_tour == 'y')
				jouer = 0;
			else
				annuler_coup(modele, pion);
		}

		while(pion->saut)
		{
			printf("direction: \n");
			pave_numerique = recuperer_entier();

			//On joue le coup voulu
			jouer_coup(modele, pion, direction_souhaitee(pave_numerique));

			printf("Fin du tour ? Y/N\n");
			//Demande si c'est la fin du tour
			demande_fin_tour = recuperer_caractere();
				
			if(demande_fin_tour == 'y')
			{	
				fin_tour(pion);
				jouer = 0;
			}
			else
			{
				printf("Annulation du coup ? Y/N\n");
				//Demande si on veut annuler le coup
				demande_annuler_coup = recuperer_caractere();
			
				if(demande_annuler_coup == 'y')
					annuler_coup(modele, pion);
			}
		}
	}*/
}

int selectionner_pion(Joueur* joueur, Pion** pion)
{
	// L'identifiant du pion qu'on veut récuperer
	int identifiant;

	// FONCTION DE LA VUE QUI AFFICHE CE QUE DOIT FAIRE L'UTILISATEUR
	printf("Selectionnez un pion\n");

	//On récupère un identifiant d'un pion
	identifiant=recuperer_entier();

	// On récupère le pion dans ceux possible
	*pion = joueur_get_reference_pion(joueur, identifiant);

	// Si on a pas réussit à récupèrer de pion on indique 
	// Que c'est faux
	if(pion == NULL)
		return 0;

	// Sinon on a réussit et bravo et yeah
	return 1;
}

int selectionner_direction(Direction* direction)
{
	// La selection de la direction
	int pave_numerique;

	//FONCTION DE LA VUE QUI Demander la direction
	printf("Direction: \n");

	// On récupère la direction souhaitée
	pave_numerique = recuperer_entier();

	// Si l'utilisateur fait nimp'
	if(direction_souhaitee(pave_numerique) == ERREUR)
		return 0;
	
	// Sinon c'est bon la direction choisie est bonne
	*direction = direction_souhaitee(pave_numerique);

	return 1;
}