

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
#include <direction.h>
#include <plateau.h>
#include <joueur.h>
#include <zone.h>
int main () 
{
	///////////////////////////
	// TEST SAUVEGARDE
	///////////////////////////

	Modele modele = modele_init(2);

	FILE *fichier_contient_pion;
	fichier_contient_pion = fopen("sauvegardetest.txt", "wb");

	sauvegarderModele(modele, fichier_contient_pion, "sauvegardePlateau.txt");

	fclose(fichier_contient_pion);




	///////////////////////////
	// TEST CHARGEMENT
	///////////////////////////




	fichier_contient_pion = fopen("sauvegardetest.txt", "rb");

	Modele modele2= chargerModele(fichier_contient_pion, "sauvegardePlateau.txt");

	fclose(fichier_contient_pion);

	printf("nombre de joueurs (2 normalement) : %d\n", modele2.nombreJoueurs);
	
	return 0;	
}

