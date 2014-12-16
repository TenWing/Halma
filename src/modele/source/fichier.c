
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
	Modele tufaischier;

	int nb_joueurs = 0;

	FILE* fp = NULL;

	fp = fopen(fichier, "rb");

	if(fp != NULL)
	{
		fread(&nb_joueurs, sizeof(int), 1, fp);
		fclose(fp);
		return modele_init(nb_joueurs);
	}	
	else
		printf("Erreur fichier\n");

	return tufaischier;
}

int chargerPartie(Modele* modele, char* fichier)
{
	FILE *fp = NULL;
		
	char* seek = "Parties/";
	strcat(seek, fichier);
	strcat(seek, ".txt");

	fp = fopen(seek, "rb");

	if(fp != NULL)
	{
		modele->pile_tours = charger_tours(fp, modele);
		fclose(fp);
	}
	else
		printf("TUPUES\n");

}