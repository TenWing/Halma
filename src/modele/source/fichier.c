


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

int sauvegarderPartie(Modele* modele, char fichier[100])
{	
	//On crée un pointeur sur FILE
	FILE* fp=NULL;

	char ungrostableaucahein[100] = "Parties/";

	//On concatene la chaine de caractère fichier pour avoir fichier.txt
	strcat(ungrostableaucahein, fichier);

	strcat(ungrostableaucahein, ".txt");

	//On ouvre le fichier pour écrire en binaire
	fp = fopen( ungrostableaucahein, "wb");

	if(fp != NULL)
	{
		//On sauvegarde le modele dans le fichier.txt
		sauvegarderModele(modele, fp);

		//On ferme le fichier
		fclose(fp);

		//On retourne un succès
		return 1;
	}
	else
	{
		printf("erreur : impossible de sauvegarder la partie");

		//On retourne un échec
		return 0;
	}


}

Modele chargerModele(char fichier[100])
{
	Modele modele;

	int nb_joueurs = 0, nb_ia, indice_ia;

	FILE* fp = NULL;

	//On ouvre le fichier de sauvegarde sauvé en binaire
	fp = fopen(fichier, "rb");

	if(fp != NULL)
	{
		//On lit le nombre de joueur dans le fichier de sauvegarde
		fread(&nb_joueurs, sizeof(int), 1, fp);

		// On lit le nombre d'IA
		fread(&nb_ia, sizeof(int), 1, fp);

		//On initialise le modele 1 pour indiquer qu'on charge
		modele = modele_init(nb_joueurs, nb_ia, 1);

		// On va chercher quels joueurs sont IA
		int i = 0;
		for(i = 0; i < nb_ia; i++)
		{
			fread(&indice_ia, sizeof(int), 1, fp);
			modele.tableau_joueur[indice_ia].ia = 1;
		}

		//On regarde qu'elle joueur a sauvegardé la partie
		fread(&modele.joueurJoue, sizeof(int), 1, fp);

		//On ferme le fichier de sauvegarde
		fclose(fp);

		return modele;
	}	
	else
		printf("Erreur fichier\n");

	return modele;
}

int chargerPartie(Modele* modele, char fichier[100])
{
	FILE *fp;
	
	//On ouvre le fichier de sauvegarde pour le lire
	fp = fopen(fichier, "rb");

	if(fp != NULL)
	{
		//On initialise la pile du modele à partir du fichier de sauvegarde
		charger_tours(fp, modele);

		//On ferme le fichier texte et on retourne le succès
		fclose(fp);

		return 1;
	}
	else
	{

		printf("Erreur : Impossibilité de charger votre partie....\n");
		return 0;
	}

}