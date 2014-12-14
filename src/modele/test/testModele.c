

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

	Pion pion = pion_init(BLEU, position_init(4,2), 9);
	Coup coup = coup_init(&pion, position_init(3,3));



	FILE *fichier_contient_pion;
	fichier_contient_pion = fopen("sauvegardetest.txt", "wb");

	sauvegardeCoup(coup, fichier_contient_pion);

	fclose(fichier_contient_pion);









	///////////////////////////
	// TEST CHARGEMENT
	///////////////////////////




	fichier_contient_pion = fopen("sauvegardetest.txt", "rb");

	Coup coup2=chargerCoup(fichier_contient_pion);

	fclose(fichier_contient_pion);

	printf("ID : %d\n", coup2.pion.identifiant);
	printf("precedent x : %d\n", coup2.precedente.x);

	return 0;	
}

