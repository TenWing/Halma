/**
* \file		modele.c
* \author	Tendry
* \version	1.0
* \date		30 Novembre 2014
* \brief	Contient le code source des fonctions du modèle		
*/

// ###################################
// Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <modele.h>
// ###################################

void commencer_tour(Modele* modele, Pion* pion)
{
	// On crée un tour
	Tour tour = tour_init(*pion);
	
	// On dit au modèle qu'il y a un nouveau tour joué
	pileTours_ajouterTour(&modele->pile_tours, tour);
}

void fin_tour(Modele* modele)
{
	
}
