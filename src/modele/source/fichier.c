
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

Modele chargerPartie(int charger)
{
	Modele modele;
	FILE *fichier_contient_partie;

		
	switch(charger)
	{
		case 1 :
			fichier_contient_partie = fopen("Parties/general_1.txt", "rb");

			if (fichier_contient_partie != NULL)
			{

			   	modele=chargerModele(fichier_contient_partie, "Parties/plateau_1.txt");
			   	fclose(fichier_contient_partie);

			   	return modele;

			}

			else
			{
			    return modele;
			}
			break;
		case 2 :
			fichier_contient_partie = fopen("Parties/general_2.txt", "rb");

			if (fichier_contient_partie != NULL)
			{
			   	modele=chargerModele(fichier_contient_partie, "Parties/plateau_2.txt");
			   	fclose(fichier_contient_partie);
			   	
			   	return modele;

			}

			else
			{
			    return modele;
			}
			break;
		case 3 :
			fichier_contient_partie = fopen("Parties/general_3.txt", "rb");

			if (fichier_contient_partie != NULL)
			{
			   	modele=chargerModele(fichier_contient_partie, "Parties/plateau_3.txt");
			   	fclose(fichier_contient_partie);

			   	return modele;

			}

			else
			{
			    return modele;
			}
			break;
		default :
			break;
	}
}