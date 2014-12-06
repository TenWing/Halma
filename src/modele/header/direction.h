/**
* \file		direction.h
* \author	Tendry
* \date 	25 Novembre 2014
* \brief 	Fichier qui définit l'énumération des directions possibles
* \details	8 directions possibles (celles d'une boussole)
* \version	1.0
*/

#ifndef DIRECTION_H
#define DIRECTION_H

/**
* \brief	Définit une direction de déplacement
* \author 	Tendry
* \version 	1.0
*/
typedef enum Direction Direction;
enum Direction
{
	GAUCHE, 
	HAUT_GAUCHE, 
	HAUT, 
	HAUT_DROITE, 
	DROITE, 
	BAS_DROITE, 
	BAS, 
	BAS_GAUCHE,
	ERREUR
};

Direction direction_souhaitee(int pave_numerique);

#endif