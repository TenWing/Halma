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
#include <matrice.h>
#include <vue.h>
#include <vue_jeu.h>
#include <vue_plateau.h>
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

void controleur_jouer_tour(Joueur* joueur, Modele* modele)
{
	int i;
	// Le pion qui jouera
	Pion* pion = NULL;

	// La variable qui stocke les choix utilisateur
	char choix;

	do
	{
		system("clear");
		// On affiche le menu de debut de tour
		affiche_plateau(&modele->plateau, AFFICHAGE);
		affiche_joueur(joueur->couleur);
		affiche_menu_commencer_tour();
		choix = recuperer_caractere();

		// Cas joueur joue un coup :
		if(choix == 'a')
		{
			// On doit selectionner un pion
			while(!selectionner_pion(modele, joueur, &pion));			 
		
			// On commence un tour
			commencer_tour(modele, pion);

			// On joue un ou des coups
			controleur_jouer_coup(joueur, modele, pion);


		}
		// Cas joueur revient au tour d'avant
		else if(choix == 'b')
		{
			if(modele->pile_tours.premier != NULL)
			{
				if(modele->nombreJoueurs>2)
				{
					for(i=0; i<4; i++)
					{
						annuler_tour(modele);
					}
				}
				else
				{
					for(i=0; i<2; i++)
					{
						annuler_tour(modele);
					}
				}
			}
		}
		// Cas sauvegarder
		else if(choix == 'c')
		{
			// TODO
		}
	}while(choix != 'd');

	if(pion != NULL)
	{
		fin_tour(&pion);	
	}
}

void controleur_jouer_coup(Joueur* joueur, Modele* modele, Pion* pion)
{
	// Les variable qui stocke les choix utilisateur
	char choix;
	int nombreCoup;

	//Booléen pour l'erreur de déplacement
	int jouerCoup=0;

	//Autre variables
	int i;

	// La direction d'envoi du pion
	Direction direction;

	do
	{
		// Affichage + demande choix utilisateur
		system("clear");
		affiche_plateau(&modele->plateau, AFFICHAGE);
		affiche_joueur(joueur->couleur);
		affiche_menu_coup(0);
		choix = recuperer_caractere();

		// Cas joueur déplace :
		if(choix == 'a')
		{
			while(jouerCoup == 0)
			{	
				// Il doit selectionner une direction
				while(!selectionner_direction(modele, &direction));
		
				// Tout est bon on joue le coup !
				jouerCoup=jouer_coup(modele, pion, direction);

				if(jouerCoup == 0)
				{
					//Affichage + demande utilisateur
					affiche_joueur(joueur->couleur);
					affiche_echec_deplacement();
					choix = recuperer_caractere();

					if(choix == 'a')
					{
						//L'utilisateur va changer de pion

						//On brise la boucle du while de jouerCoup
						jouerCoup = 1;

						//On brise la boucle du while de choix
						choix = 'd';
					}
				}
			}
		}
		// Cas joueur annule un coup
		else if(choix == 'b')
		{
			//Demande à l'utilisateur combien de coups il souhaite annuler
			nombre_coup();

			//On récupère le nombre de coups à annuler
			nombreCoup=recuperer_entier();

			//On annule les coups
			for(i=0; i<nombreCoup; i++)
			{
				annuler_coup(modele, pion);
			}

			jouerCoup = 0;
		}
		// Cas sauvegarder
		else if(choix == 'c')
		{
			// TODO
		}
	}while(choix != 'd');
}

int selectionner_pion(Modele* modele, Joueur* joueur, Pion** pion)
{
	// L'identifiant du pion qu'on veut récuperer
	int identifiant;

	// FONCTION DE LA VUE QUI AFFICHE CE QUE DOIT FAIRE L'UTILISATEUR
	system("clear");
	affiche_plateau(&modele->plateau, SELECTION);
	affiche_joueur(joueur->couleur);
	affiche_selection_pion();

	//On récupère un identifiant d'un pion
	identifiant=recuperer_entier();

	// On récupère le pion dans ceux possible
	*pion = joueur_get_reference_pion(joueur, identifiant);

	while(*pion == NULL)
	{
		affiche_joueur(joueur->couleur);
		affiche_echec_pion();

		//On récupère un identifiant d'un pion
		identifiant=recuperer_entier();

		// On récupère le pion dans ceux possible
		*pion = joueur_get_reference_pion(joueur, identifiant);
	}

	// Si on a pas réussit à récupèrer de pion on indique 
	// Que c'est faux
	if(pion == NULL)
		return 0;

	// Sinon on a réussit et bravo et yeah
	return 1;
}

int selectionner_direction(Modele* modele, Direction* direction)
{
	// La selection de la direction
	int pave_numerique;

	//FONCTION DE LA VUE QUI Demander la direction
	system("clear");
	affiche_plateau(&modele->plateau, AFFICHAGE);
	affiche_selection_direction();

	// On récupère la direction souhaitée
	pave_numerique = recuperer_entier();

	// Si l'utilisateur fait nimp'
	if(direction_souhaitee(pave_numerique) == ERREUR)
		return 0;
	
	// Sinon c'est bon la direction choisie est bonne
	*direction = direction_souhaitee(pave_numerique);

	return 1;
}