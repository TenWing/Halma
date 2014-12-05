/**
* \file		saisie.c
* \brief	Contient le code source des fonctions de saisie
* \version 	1.0
* \date		03 Décembre 2014
*/

// #################################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <saisie.h>
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
	// on récupère le premier caractère de TOUTE saisie possible
	char retour = fgetc(stdin);

	// On vide le buffer d'un aller à la ligne
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

