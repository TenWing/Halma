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
	Pion* pion=NULL;
	int identifiant;
	int deplacement=1, jouer=1;
	char demande_fin_tour, demande_annuler_coup, demande_garder_pion;
	int pave_numerique;

	
	while(pion == NULL)
		{
			printf("saisir l'identifiant d'un pion\n");
			//On récupère un identifiant d'un pion
			identifiant=recuperer_entier();

			//On vérifie que l'identifiant correspond à un pion du joueur
			pion = joueur_get_reference_pion(joueur, identifiant);
		}

	commencer_tour(modele, pion);

	while(jouer)
	{

		//Demander la direction
		printf("Direction: \n");
		pave_numerique = recuperer_entier();

		deplacement = jouer_coup(modele, pion, direction_souhaitee(pave_numerique));

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
			{	printf("direction: \n");
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
	}
}