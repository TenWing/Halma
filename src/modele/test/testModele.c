

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

	modele.plateau=updateMatrice(modele.plateau);

	NoeudPion* actuel = modele.plateau.liste_pions.premier;

	while(actuel != NULL)
	{
		printf("ID : %d\n", actuel -> pion.identifiant);

		actuel = actuel -> suivant;
	}


	
	
	return 0;	
}

