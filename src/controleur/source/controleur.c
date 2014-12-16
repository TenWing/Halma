

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
#include <fichier.h>
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
	int tour=0;
	int sauvegarde;
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
		affiche_menu_tour(tour);
		choix = recuperer_caractere();

		// Cas joueur joue un coup :
		if(choix == 'a')
		{
			// On doit selectionner un pion
			while(!selectionner_pion(modele, joueur, &pion));			 
		
			// On commence un tour
			commencer_tour(modele, pion);

			// On joue un ou des coups
			tour=controleur_jouer_coup(joueur, modele, pion);
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
			affiche_sauvegarde(0);
			sauvegarde=recuperer_entier();

			if(sauvegarderPartie(modele, sauvegarde))
			{
				affiche_sauvegarde(1);
			}
			else
			{
				affiche_sauvegarde(2);
			}
		}
	}while(choix != 'd');

	if(pion != NULL)
	{
		fin_tour(&pion);	
	}
}

int controleur_jouer_coup(Joueur* joueur, Modele* modele, Pion* pion)
{
	// Les variable qui stocke les choix utilisateur
	char choix;
	int nombreCoup;

	//Booléen pour l'erreur de déplacement
	int jouerCoup=0;

	//Autre variables
	int i;
	int coup=0;
	int echec=0;

	// La direction d'envoi du pion
	Direction direction;

	do
	{
		// une fois selectionné on marque les positions possibles
		// autour du pion
		if(pion->saut || jouerCoup == 0)
		{
			pion_marquer(pion, &modele->plateau);
		}

		// Affichage + demande choix utilisateur
		system("clear");
		affiche_plateau(&modele->plateau, AFFICHAGE);
		affiche_joueur(joueur->couleur);
		affiche_menu_coup(coup);
		choix = recuperer_caractere();

		// Cas joueur déplace :
		if(choix == 'a')
		{
			if(jouerCoup == 1 && pion->saut == 1)
				{
					jouerCoup=0;
					echec=1;
				}

			while(jouerCoup == 0)
			{	
				// Il doit selectionner une direction
				while(!selectionner_direction(modele, &direction));
		
				// Tout est bon on joue le coup !
				jouerCoup=jouer_coup(modele, pion, direction);
				pion_demarquer(&(modele->plateau));
				if(jouerCoup == 0)
				{
					if(pion->saut == 0)
					{
						//Affichage + demande utilisateur
						affiche_joueur(joueur->couleur);
						affiche_echec_deplacement(echec);
						choix = recuperer_caractere();

						if(choix == 'a')
						{
							//L'utilisateur va changer de pion

							//On  déselectionne le pion qui avait été choisi
							pion->selectionne=0;

							//On dépile le tour qui est inutile
							pileTours_depiler(&modele->pile_tours);

							return 0;
						}
					}
					else
					{
						affiche_joueur(joueur->couleur);
						affiche_echec_deplacement(echec);
						choix = recuperer_caractere();

						if(choix == 'd')
						{
							//On retourne que le deplacement du pion a bien été effectué
							return 1;
						}
						else if(choix =='r')
						{
							//L'utilisateur veut annuler son coup

							//Le joueur ne peut plus déplacer son pion
							jouerCoup =1;
							
							//On affiche le menu adéquate
							coup=1;
						}
					}
				}

			}
		}
		// Cas joueur annule un coup
		else if(choix == 'r')
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
			coup=0;
		}
	}while(choix != 'd');
	pion_demarquer(&(modele->plateau));

	return 1;
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

void jouer_partie(int jouer)
{
	int nombre_joueur,i;
	Controleur controleur;
	Couleur couleur;
	
	//Permettra de savoir quel joueur a gagné
	int victoire=0;
	int verification = 1;

	if(jouer)
	{
		clean_terminal();
		affiche_configuration_partie();
		printf("Choix: ");

		//On demande le nombre de joueur pour initialiser le jeu
		nombre_joueur = recuperer_entier();

		controleur = controleur_init(nombre_joueur);
	}
	else
	{
		controleur = controleur_charger();
	}
	printf("chargement controleur OK");
	//Tant qu'il n'y a pas de joueur gagnant
		while(victoire != 1)
		{
			//Les joueurs jouent chacuns à leur tour
			for(i=0; i<nombre_joueur; i++)
			{
				controleur_jouer_tour(&(controleur.modele.tableau_joueur[i]), &(controleur.modele));

				//Si l'un des joueur a placé tous ses pions dans la zone de victoire
				if(verification == verification_zone(&(controleur.modele.tableau_zone[i]), &(controleur.modele.tableau_joueur[i])))
				{
					//i=8 va permettre de sortir de la boucle for
					victoire = 1;
						
					//Permet de savoir quel joueur a gagné par rapport à sa couleur
					couleur = controleur.modele.tableau_joueur[i].couleur;
				}
			}
		}

		affichage_victoire(couleur);			
}

Controleur controleur_charger()
{
	int partie;
	Controleur controleur;

	printf("numéro de la partie à charger :");

	partie = recuperer_entier();
	
	controleur.modele = chargerPartie(partie);

	controleur.nombreJoueurs = controleur.modele.nombreJoueurs;

	return controleur;
}
	