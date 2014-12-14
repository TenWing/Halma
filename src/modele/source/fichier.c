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

int sauvegardePartie(Modele* modele, char* emplacement_fichier_sauvegarde)
{
	FILE *fichier_contient_partie;
	fichier_contient_partie = fopen(emplacement_fichier_sauvegarde, "wb");

   int i, j;

	 if (fichier_contient_partie != NULL)
	    {

			fprintf(fichier_contient_partie, "%d %d", modele->plateau.matrice.nbLignes, modele->plateau.matrice.nbColonnes);
		    fprintf(fichier_contient_partie, "\n");
					
			for(i=0; i<modele->plateau.matrice.nbLignes; i++)
			{
				for(j=0; j<modele->plateau.matrice.nbColonnes; j++)
				{
		    		fprintf(fichier_contient_partie, "%d", modele->plateau.matrice.donnees[i][j]);
		    		fprintf(fichier_contient_partie, " ");		    		
	  			}

	   			fprintf(fichier_contient_partie, "\n");
	    	}

	    	fprintf(fichier_contient_partie, "%d\n", modele->nombreJoueurs);
	    	fprintf(fichier_contient_partie, "\n");





			fclose(fichier_contient_partie);
			return 1;
	    }

	    else
	    {
	         printf("Impossible d'ouvrir le fichier sauvegarde.txt\n");
	         return 0;
	    }
}