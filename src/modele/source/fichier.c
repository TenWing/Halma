
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

int sauvegarderPartie(Modele* modele, int sauvegarde)
{
	FILE *fichier_contient_partie;
	switch(sauvegarde)
	{
		// char tampon[1000];
		// printf("%s\n", getcwd(tampon, 1000));
		case 1 :
			fichier_contient_partie = fopen("Parties/general_1.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	sauvegarderModele(*modele, fichier_contient_partie, "Parties/plateau_1.txt");
			   	fclose(fichier_contient_partie);

			   	return 1;

			}

			else
			{
			    return 0;
			}
			break;
		case 2 :
			
			fichier_contient_partie = fopen("Parties/general_2.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	sauvegarderModele(*modele, fichier_contient_partie, "Parties/plateau_2.txt");
			   	fclose(fichier_contient_partie);

			   	return 1;

			}

			else
			{
			    return 0;
			}
			break;
		case 3 :
			
			fichier_contient_partie = fopen("Parties/general_3.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	sauvegarderModele(*modele, fichier_contient_partie, "Parties/plateau_3.txt");
			   	fclose(fichier_contient_partie);

			   	return 1;

			}

			else
			{
			    return 0;
			}
			break;
		default :
			break;
	}
}

Modele chargerModele(char* fichier)
{
	Modele tufaischier;

	int nb_joueurs = 0;

	FILE* fp = NULL;

	fp = fopen(fichier, "r");

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