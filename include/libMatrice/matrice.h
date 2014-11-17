#ifndef MATRICE_H
#define MATRICE_H

//La taille max d'une chaîne de caractère
#define TAILLE_MAX 1000

/**
* Une matrice, tableau à deux dimensions contenant des données
* ici une matrice de caractères
* \author Tendry
* \version 1.0
*/
typedef struct Matrice Matrice;
struct Matrice 
{
	/**
	* La matrice de données
	* tableau à 2 dimensions de caractères
	*/
	char **donnees;

	/**
	* Le nombre de ligne de la matrice
	*/
	int nbLignes;

	/**
	* Le nombre de colonnes de la matrice
	*/
	int nbColonnes; 

	/**
	* Indique si la matrice est corrompue ou non
	*/
	int corrompue;
};

/**
* Renvoie une matrice allouée dynamiquement
* grâce aux paramètres fournis
* \param nbLig le nombre de lignes de la matrice crée
* \param nbCol le nombre de colonnes de la matrice crée
* \return renvoie une matrice allouée dynamiquement
*/
Matrice alloue(int nbLig, int nbCol);

/**
* Initialise une matrice à partir d'un fichier texte
* \param fichier le chemin vers le fichier
* \return la matrice remplie
*/
Matrice initMatrice(char *fichier);

/**
* Désalloue le contenue de la matrice passée
* \param un pointeur e la matrice à "détruire"
*/
void detruire(Matrice* m);

/**
* Affiche le contenu d'une matrice à l'écran
* \param m la matrice à afficher
*/
void afficheMatrice(Matrice m);

/**
* Sauvegarde une matrice dans un fichier
* \param m la matrice à sauvegarder
* \param fichier une chaîne de caractère correspondant au fichier
*/
void sauvegardeMatrice(Matrice m, char *fichier);

#endif