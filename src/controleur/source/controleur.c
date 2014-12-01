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
// #################################

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
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

	fgets(chaine, 100, stdin);

	int nombre = atoi(chaine);

	viderBuffer();

	return nombre;
}

void jouer_tour(Joueur* joueur)
{

}