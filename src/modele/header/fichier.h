

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
* \param	le nom du fichier
* \version 	1.0
* \return 	1 si la sauvegarde a reussi, 0 si echec
*/
int sauvegarderPartie(Modele* modele, char fichier[100]);

/**
* \brief 	Charge le modele a l'état initiale
* \author 	Quentin
* \param	Le nom du fichier
* \version 	1.0
* \return 	le modele
*/
Modele chargerModele(char fichier[100]);

/**
* \brief 	Charge le modele avec tous les tours qui ont été joué
* \author 	Quentin
* \param 	le modele
* \param	Le nom du fichier
* \version 	1.0
* \return 	1 si succès 0 si echec
*/
int chargerPartie(Modele* modele, char fichier[100]);

#endif