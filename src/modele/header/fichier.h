
/**
* \file		fichier.h
* \author	Quentin
* \date 	14 Decembre 2014
* \brief 	Fichier qui définit les fonctions de sauvegarde/chargement
* \version	1.0
*/
#ifndef FICHIER_H
#define FICHIER_H

/**
* \brief 	Sauvegarder une partie
* \author 	Quentin
* \param	Modele
* \param	L'emplacement où sera le fichier de sauvegarde
* \version 1.0
* \return 	1 si la sauvegarde a reussi, 0 si echec
*/
int sauvegarderPartie(Modele* modele, char* fichier);

Modele chargerModele(char* fichier);

int chargerPartie(Modele* modele, char* fichier);

#endif