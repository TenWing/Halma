
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
// #################################

int sauvegarderPartie(Modele* modele, int sauvegarde)
{
	FILE *fichier_contient_partie;
	switch(sauvegarde)
	{
		case 1 :
			
			fichier_contient_partie = fopen("../../../bin/Parties/partie_1/general.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	sauvegarderModele(*modele, fichier_contient_partie, "../../../bin/Parties/partie_1/plateau.txt");
			   	fclose(fichier_contient_partie);

			   	return 1;

			}

			else
			{
			    return 0;
			}
			break;
		case 2 :
			
			fichier_contient_partie = fopen("../../../bin/Parties/partie_2/general.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	sauvegarderModele(*modele, fichier_contient_partie, "../../../bin/Parties/partie_2/plateau.txt");
			   	fclose(fichier_contient_partie);

			   	return 1;

			}

			else
			{
			    return 0;
			}
			break;
		case 3 :
			
			fichier_contient_partie = fopen("../../../bin/Parties/partie_3/general.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	sauvegarderModele(*modele, fichier_contient_partie, "../../../bin/Parties/partie_3/plateau.txt");
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
/*
Modele* chargerPartie(int charger)
{
	Modele modele;

	switch(sauvegarde)
	{
		case 1 :
			FILE *fichier_contient_partie;
			fichier_contient_partie = fopen("../../../bin/Parties/partie_1/general.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	modele=chargerModele(fichier_contient_partie, "../../../bin/Parties/partie_1/plateau.txt");
			   	fclose(fichier_contient_partie);

			   	return &modele;

			}

			else
			{
			    return &modele;
			}
			break;
		case 2 :
			FILE *fichier_contient_partie;
			fichier_contient_partie = fopen("../../../bin/Parties/partie_2/general.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	modele=chargerModele(fichier_contient_partie, "../../../bin/Parties/partie_2/plateau.txt");
			   	fclose(fichier_contient_partie);
			   	
			   	return &modele;

			}

			else
			{
			    return &modele;
			}
			break;
		case 3 :
			FILE *fichier_contient_partie;
			fichier_contient_partie = fopen("../../../bin/Parties/partie_3/general.txt", "wb");

			if (fichier_contient_partie != NULL)
			{
			   	modele=chargerModele(fichier_contient_partie, "../../../bin/Parties/partie_3/plateau.txt");
			   	fclose(fichier_contient_partie);

			   	return &modele;

			}

			else
			{
			    return &modele;
			}
			break;
		default :
			break;
	}
}*/