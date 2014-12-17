




/**
 * \file      modele.c
 * \author    Geliot
 * \version   1.0
 * \date      19 Novembre 2014
 * \brief     Définit les fonctions pour jouer au jeu de l'Halma
 *
 * \details   Ces fonctions permettent de créer le jeu, pouvoir y jouer ...
 *            
 */

// ############################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <pion.h>
#include <plateau.h>
// ############################

Pion pion_init(Couleur couleur, Position position, int identifiant)
{
	//Le pion qui sera initialisé
	Pion pion;
	
	// Couleur
	pion.couleur = couleur;

	//Copie de la position
	pion.position = position;
	
	// Copie de l'identifiant
	pion.identifiant = identifiant;

	// Il saute pas !!!!
	pion.saut = 0;

	// Il est pas selectionné
	pion.selectionne = 0;

	return pion;
}

Pion pion_copie(Pion pion)
{
	// La copie
	Pion copie;
	
	// Couleur
	copie.couleur = pion.couleur;

	//Copie de la position
	copie.position = pion.position;
	
	// Copie de l'identifiant
	copie.identifiant = pion.identifiant;

	// Il saute pas !!!!
	copie.saut = pion.saut;

	// Il est pas selectionné
	copie.selectionne = pion.selectionne;

	return copie;
}

int pion_deplacer(Pion* pion, Plateau* plateau, Direction direction)
{
	//La position de la direction souhaitée
	Position position_direction = pion->position;

	//On vérifie si les pointeurs ne sont pas nuls
	if (pion == NULL || plateau == NULL)
	{
		//Si un d'eux est nul, on quitte le programme
		exit(EXIT_FAILURE);
	}

	//On regarde qu'elle est le direction souhaitée
	switch(direction)
	{
		case HAUT:
			position_direction.x--;
			break;

		case HAUT_DROITE:
			position_direction.x--;
			position_direction.y++;
			break;

		case DROITE:
			position_direction.y++;
			break;

		case BAS_DROITE:
			position_direction.y++;
			position_direction.x++;
			break;

		case BAS:
			position_direction.x++;
			break;

		case BAS_GAUCHE:
			position_direction.x++;
			position_direction.y--;
			break;

		case GAUCHE:
			position_direction.y--;
			break;

		case HAUT_GAUCHE:
			position_direction.x--;
			position_direction.y--;
			break;

		default:
			break;
	}

	// ############################################
	// Si le pion est entrain de sauter
	if(pion->saut)
	{
		// On regarde s'il va sauter par dessus un pion
		if(plateau_getpion(plateau, position_direction).identifiant != -1)
		{
			// On essaye de le faire sauter
			if(pion_sauter(pion, direction, plateau))
			{
				// S'il a réussit a sauter déplacement fait
				return 1;		
			}
			else
				// Sinon il n'a pas réussit a sauter il peut essayer de sauter dans une autre direction
				return 0;
		}
		else
			// Sinon il n'a pas réussit a sauter il peut essayer de sauter dans une autre direction
			return 0;
	}
	// ############################################


	// On regarde si quelque chose empêche le déplacement !
	if(position_hors_plateau(&position_direction, plateau))
	{
		return 0;
	}

	// S'il y a un pion là on on veut aller 
	if(plateau_getpion(plateau, position_direction).identifiant != -1)
	{
		// alors on regarde si un saut est possible !
		if(pion_sauter(pion, direction, plateau))
		{
			// Le pion est entrain de sauter il peut continuer a se déplacer en sautant
			pion-> saut = 1;

			// Si oui le saut est fait et le déplacement est fait !
			return 1;
		}
		else
			// Sinon on va proposer à l'utilisateur de rejouer
			return 0;
	}

	// On effectue le déplacement ^^
	// Mais avant on change les positions vides existantes
	liste_positions_ajout(&plateau->vides, pion->position);
	pion->position = position_direction;
	liste_positions_supprimer(&plateau->vides, position_direction);
	return 1;
}

int pion_sauter(Pion* pion, Direction direction, Plateau* plateau)
{
	Position position_direction = pion->position;

	//On regarde qu'elle est le direction souhaitée
	switch(direction)
	{
		case HAUT:
			position_direction.x -= 2;
			break;

		case HAUT_DROITE:
			position_direction.x -= 2;
			position_direction.y += 2;
			break;

		case DROITE:
			position_direction.y += 2;
			break;

		case BAS_DROITE:
			position_direction.y += 2;
			position_direction.x += 2;
			break;

		case BAS:
			position_direction.x += 2;
			break;

		case BAS_GAUCHE:
			position_direction.x += 2;
			position_direction.y -= 2;
			break;

		case GAUCHE:
			position_direction.y -= 2;
			break;

		case HAUT_GAUCHE:
			position_direction.x -= 2;
			position_direction.y -= 2;
			break;

		default:
			break;
	}

	// On regarde si quelque chose empêche le déplacement !
	if(position_hors_plateau(&position_direction, plateau))
	{
		return 0;
	}

	// S'il y a un pion la où on veut aller 
	if(plateau_getpion(plateau, position_direction).identifiant != -1)
	{
		// On renvoie faux le déplacement est impossible !
		return 0;
	}

	// Arrivé ici bingo saut effectué
	liste_positions_ajout(&plateau->vides, pion->position);
	pion->position = position_direction;

	liste_positions_supprimer(&plateau->vides, position_direction);
	
	return 1;
}

void sauvegardePion(Pion pion, FILE* emplacement_fichier_sauvegarde)
{
	//On écrit dans le fichier texte les données du pion
   	fwrite(&pion.couleur, sizeof(Couleur) , 1, emplacement_fichier_sauvegarde);
   	fwrite(&pion.position.x, sizeof(int) , 1, emplacement_fichier_sauvegarde);
   	fwrite(&pion.position.y, sizeof(int) , 1, emplacement_fichier_sauvegarde);
   	fwrite(&pion.identifiant, sizeof(int) , 1, emplacement_fichier_sauvegarde);
}


void pion_marquer(Pion* pion, Plateau* plateau)
{
	pion_analyse_marquage_direction(pion, plateau, HAUT);	
	pion_analyse_marquage_direction(pion, plateau, HAUT_DROITE);	
	pion_analyse_marquage_direction(pion, plateau, DROITE);	
	pion_analyse_marquage_direction(pion, plateau, BAS_DROITE);	
	pion_analyse_marquage_direction(pion, plateau, BAS);	
	pion_analyse_marquage_direction(pion, plateau, BAS_GAUCHE);	
	pion_analyse_marquage_direction(pion, plateau, GAUCHE);	
	pion_analyse_marquage_direction(pion, plateau, HAUT_GAUCHE);	
}

void pion_demarquer(Plateau* plateau)
{
	NoeudPosition* noeud = plateau->vides.premier;
	if(noeud != NULL)
		noeud->position.marque = 0;

	while(noeud -> suivant != NULL)
	{
		noeud = noeud -> suivant;
		noeud->position.marque = 0;
	}

	noeud->position.marque = 0;
}

void pion_analyse_marquage_direction(Pion* pion, Plateau* plateau, Direction direction)
{
	// La position analysée
	Position position_direction = position_init(pion->position.x, pion->position.y);
	Position position_direction_saut = position_init(pion->position.x, pion->position.y);

	// On regarde la direction analysée
	switch(direction)
	{
		case HAUT:
			position_direction.x -= 1;
			position_direction_saut.x -= 2;
			break;

		case HAUT_DROITE:
			position_direction.x -= 1;
			position_direction.y += 1;
			position_direction_saut.x -= 2;
			position_direction_saut.y += 2;
			break;

		case DROITE:
			position_direction.y += 1;
			position_direction_saut.y += 2;
			break;

		case BAS_DROITE:
			position_direction_saut.y += 2;
			position_direction_saut.x += 2;
			position_direction.y += 1;
			position_direction.x += 1;
			break;

		case BAS:
			position_direction_saut.x += 2;
			position_direction.x += 1;
			break;

		case BAS_GAUCHE:
			position_direction_saut.x += 2;
			position_direction_saut.y -= 2;
			position_direction.x += 1;
			position_direction.y -= 1;
			break;

		case GAUCHE:
			position_direction_saut.y -= 2;
			position_direction.y -= 1;
			break;

		case HAUT_GAUCHE:
			position_direction.x -= 1;
			position_direction.y -= 1;
			position_direction_saut.x -= 2;
			position_direction_saut.y -= 2;
			break;

		default:
			break;
	}

	// Si on saute
	if(pion->saut)
	{
		// On ne regarde la portée de ce qui est a portée dez saut
		// SI ET SEULEMENT SI un pion est a portée directe
		if(plateau_getVide(plateau, position_direction) == NULL)
		{
			Position* p = plateau_getVide(plateau, position_direction_saut);
			if(p != NULL)
			{
				p -> marque = 1;
			}
		}
	}
	// Si on saute pas
	else
	{
		// On regarde ce qui est à portée
		Position* p = plateau_getVide(plateau, position_direction);
		if(p != NULL)
		{
			p -> marque = 1;
		}
		// S'il y a un pion a portée on regarde s'il on peut sauter
		else
		{
			p = plateau_getVide(plateau, position_direction_saut);
			if(p != NULL)
				p -> marque = 1;
		}
	}
}

Pion chargerPion(FILE* emplacement_fichier)
{
	Pion pion;

	//On lit les données du fichier texte
	fread(&pion.couleur, sizeof(int) , 1, emplacement_fichier);
	fread(&pion.position.x, sizeof(int) , 1, emplacement_fichier);
	fread(&pion.position.y, sizeof(int) , 1, emplacement_fichier);
	fread(&pion.identifiant, sizeof(int) , 1, emplacement_fichier);	
	
	//On retourne le pion
	return pion;
}