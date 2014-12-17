
/**
* \file		fichier.c
* \brief	Contient les fonctions qui permettent de sauvegarder/charger
* \version 	1.0
* \date		14 Décembre 2014
*/

// #################################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <matrice.h>
#include <modele.h>
#include <string.h>
#include <unistd.h>
// #################################

int sauvegarderPartie(Modele* modele, char* fichier)
{	
	FILE* fp;

	/*char* seek;
	strcat(seek, fichier);
	strcat(seek, ".txt");*/

	fp = fopen( "sauvegarde.txt", "wb");

	if(fp != NULL)
	{
		sauvegarderModele(modele, fp);
		fclose(fp);
		return 1;
	}
	else
	{
		printf("erreur : impossible de sauvegarder la partie");
		return 0;
	}
}

Modele chargerModele(char* fichier)
{
	Modele modele;

	int nb_joueurs = 0;

	FILE* fp = NULL;

	//On ouvre le fichier de sauvegarde
	fp = fopen("sauvegarde.txt", "rb");

	if(fp != NULL)
	{
		//On lit le nombre de joueur dans le fichier de sauvegarde
		fread(&nb_joueurs, sizeof(int), 1, fp);

		//On initialise le modele
		modele = modele_init(nb_joueurs);

		//On regarde qu'elle joueur a sauvegardé la partie
		fread(&modele.joueurJoue, sizeof(int), 1, fp);

		//On ferme le fichier de sauvegarde
		fclose(fp);

		return modele;
	}	
	else
		printf("Erreur fichier\n");

	return modele;
}

int chargerPartie(Modele* modele, char* fichier)
{
	FILE *fp = NULL;
		
	/*char* seek = "Parties/";
	strcat(seek, fichier);
	strcat(seek, ".txt");*/

	fp = fopen("sauvegarde.txt", "rb");

	if(fp != NULL)
	{
		modele->pile_tours = charger_tours(fp, modele);
		fclose(fp);
		return 1;
	}
	else
	{
		printf("TUPUES\n");
		return 0;
	}

}