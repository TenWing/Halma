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
#include <vue.h>
#include <modele.h>
#include <string.h>
// #################################

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void clean (char* chaine)
{
	char* p = strchr(chaine, '\n');

	if(p)
		*p = 0;
	else
		viderBuffer();
}

char recuperer_caractere()
{
	char retour = fgetc(stdin);
	viderBuffer();
	return retour;
}

int recuperer_entier()
{	
	char chaine[100];
	int nombre;

	fgets(chaine, sizeof chaine, stdin);

	clean(chaine);

	sscanf(chaine, "%d", &nombre);

	return nombre;
}

void jouer_tour(Joueur* joueur)
{
	Pion* pion=NULL;
	int identifiant;
	int deplacement=1;

	//////////////////////:
	//Juste pour le moment
	Direction direction=DROITE;
	////////////////////////////
	
	Plateau* plateau;
	char finTour = 'N';

	//le jour doit déplacer un de ces pions
	while(finTour != 'o' || finTour != 'O')
	{
		while(pion == NULL)
		{
			//On récupère un identifiant d'un pion
			identifiant=recuperer_entier();
///// problème à partir d'ici ////////////
			//On vérifie que l'identifiant correspond à un pion du joueur
			pion = joueur_get_reference_pion(joueur, identifiant);
		}

		while(deplacement == 1)
		{
			//Le joueur choisi la direction où il veut déposer le pion
			deplacement=pion_deplacer(pion, plateau, direction);
			direction=DROITE;	
		}
					printf("ici");

		finTour = recuperer_caractere();
	}	




	

}