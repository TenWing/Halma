
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
	pion.identifiant=identifiant;

	// Il saute pas !!!!
	pion.saut = 0;

	// Son symbole sur le plateau
	pion.symbole='*';

	return pion;
}

Liste *liste_pion_init()
{
	//On alloue dynamiquement la structure de contrôle avec un malloc
	Liste *liste = malloc(sizeof(*liste));

	//On alloue dynamiquement la mémoire pour le stockage du premier element
	Element *element = malloc(sizeof(*element));

	// Vérification des allocations dynamiques
	if (liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	//L'élément pion est défini par défaut
	element->pion = pion_init(ROUGE, position_init(0,0), 1);
	
	//Le pointeur suivant pointe vers NULL
	element->suivant = NULL;

	//La liste pointe vers le premier élément qui est le pion
	liste -> premier = element;

	//On retourne la liste
	return liste;

}

void insertion_pion(Liste *liste_pions, Pion pion_nouveau)
{
	//Création d'un nouvel élément
	Element *nouveau = malloc(sizeof(*nouveau));

	if (liste_pions == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	nouveau -> pion = pion_nouveau;

	//Insertion de l'élément au début de la liste
	nouveau -> suivant = liste_pions -> premier;
	liste_pions -> premier = nouveau;
}

Pion plateau_getpion(Position position, Plateau* plateau, Liste *liste_pions)
{

	if (liste_pions == NULL || plateau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	//Création d'un pointeur sur element qui se balladera dans la liste
	Element *actuel = liste_pions -> premier;

	//Création d'un pion fictif qui sera retourner si à la postion demandée il n'y a pas le symbole d'un pion
	Pion pion_fictif;
	Position position_fictive=position_init(100,100);
	pion_fictif=pion_init(ORANGE, position_fictive, -1);

	//Condition pour savoir si à la position choisie, il y a un pion ou non
	if(plateau->matrice.donnees[position.x][position.y] != '*')
	{
		// le symbole n'est pas celui d'un pion, retourner le pion fictif
		return pion_fictif;
	}

	else
	{
		//le symbole est celui d'un pion

		//tant que actuel n'a pas atteint le dernier element de la liste
		while(actuel != NULL)
		{
			//On fait pointer actuel sur la position du pion de la liste et on teste l'égalité des positions

			if((actuel->pion.position.x == position.x) && (actuel -> pion.position.y == position.y) )
			{
				//les positions sont correctes

				//On retourne le pion qui est pointé par actuel
				return (actuel -> pion);
			}

			else
			{
				//les positions ne sont pas correctes

				//On fait pointer actuel sur le prochain élément
				actuel = actuel -> suivant;
			}
		}
	}
}

int pion_peut_sauter(Pion* pion, Direction direction, Plateau* plateau, Liste* liste_pions)
{
	if (liste_pions == NULL || pion == NULL || plateau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	//Création d'un pion fictif et de la postion de la direction où le pion doit aller
	Position position_direction;
	Pion pion_fictif;

	//Selon la direction voulue, on assigne la postion_direction
	if(direction == GAUCHE)
	{
		position_direction.x = (*pion).position.x;
		position_direction.y = (*pion).position.y - 2;
		
	}

	else if(direction == HAUT_GAUCHE)
	{
		position_direction.x = (*pion).position.x - 2;
		position_direction.y = (*pion).position.y - 2;
	}

	else if(direction == HAUT)
	{
		position_direction.x = (*pion).position.x - 2;
		position_direction.y = (*pion).position.y;
	}

	else if(direction == HAUT_DROITE)
	{
		position_direction.x = (*pion).position.x - 2;
		position_direction.y = (*pion).position.y + 2;
	}

	else if(direction == DROITE)
	{
		position_direction.x = (*pion).position.x;
		position_direction.y = (*pion).position.y + 2;
	}

	else if(direction == BAS_DROITE)
	{
		position_direction.x = (*pion).position.x + 2;
		position_direction.y = (*pion).position.y + 2;
	}

	else if(direction == BAS)
	{
		position_direction.x = (*pion).position.x + 2;
		position_direction.y = (*pion).position.y;
	}

	else if(direction == BAS_GAUCHE)
	{
		position_direction.x = (*pion).position.x + 2;
		position_direction.y = (*pion).position.y - 2;
	}

	//On regarde si à l'emplacement de la direction souhaitée, il y a un pion ou non
	pion_fictif=plateau_getpion(position_direction, plateau, liste_pions);

	//On retourne un entier selon si le pion fictif est un vrai pion ou non
	if(pion_fictif.identifiant == -1)
	{
		//Le pion fictif n'est pas un pion de la liste des pions

		//On retourne la valeur 1
		return 1;
	}

	else
	{
		//Le pion fictif est pas un pion de la liste des pions

		//On retourne la valeur 0
		return 0;
	}
	
}


int pion_deplacer(Pion* pion, Plateau* plateau, Direction direction, Liste* liste_pions)
{

	Position position_direction;
	Element* actuel = liste_pions -> premier;
	int saut;

	if (pion == NULL || plateau == NULL)
	{
		exit(EXIT_FAILURE);
	}


	else
	{


		if(direction == GAUCHE)
		{
			if((*pion).position.y!=0)
			{
				position_direction=position_init((*pion).position.x, ((*pion).position.y) - 1);

				if((*pion).position.y==1)
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x, ((*pion).position.y - 1) );
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))
						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init((*pion).position.x, ((*pion).position.y - 2));
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init((*pion).position.x, ((*pion).position.y) - 1);
					return 1;
				}
			}

			return 0;
		}




		else if(direction == HAUT_GAUCHE)
		{
			if( ( (*pion).position.y != 0 ) && ( (*pion).position.x != 0) )
			{
				position_direction=position_init( (*pion).position.x - 1, (*pion).position.y - 1 );

				if( ( (*pion).position.y == 1 ) || ( (*pion).position.x == 1) )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x -1, (*pion).position.y - 1);
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))
						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init( (*pion).position.x - 2, (*pion).position.y - 2);
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x - 1, ((*pion).position.y) - 1);
					return 1;
				}
			}

			return 0;
		}




		else if(direction == HAUT)
		{
			if( (*pion).position.x != 0 )
			{
				position_direction=position_init( (*pion).position.x - 1, (*pion).position.y );

				if( (*pion).position.x == 1 )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x -1, (*pion).position.y );
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))
						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init( (*pion).position.x - 2, (*pion).position.y );
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x - 1, ((*pion).position.y) );
					return 1;
				}
			}

			return 0;
		}




		else if(direction == HAUT_DROITE)
		{
			if( ( (*pion).position.x != 0 ) && ( (*pion).position.y != 15 ) )
			{
				position_direction=position_init( (*pion).position.x - 1, (*pion).position.y + 1);

				if( ( (*pion).position.x == 1 ) || ( (*pion).position.y == 14 ) )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x -1, (*pion).position.y + 1 );
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init( (*pion).position.x - 2, (*pion).position.y + 2 );
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x - 1, (*pion).position.y + 1);
					return 1;
				}
			}

			return 0;
		}




		else if(direction == DROITE)
		{
			if( (*pion).position.y != 15  )
			{
				position_direction=position_init( (*pion).position.x, (*pion).position.y + 1);

				if( (*pion).position.y == 14 )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x, (*pion).position.y + 1 );
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init( (*pion).position.x, (*pion).position.y + 2 );
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x, (*pion).position.y + 1);
					return 1;
				}
			}

			return 0;
		}




		else if(direction == BAS_DROITE)
		{
			if( ( (*pion).position.y != 15 ) && ( (*pion).position.x != 15 ) )
			{
				position_direction=position_init( (*pion).position.x + 1, (*pion).position.y + 1);

				if( (*pion).position.y == 14 || (*pion).position.x == 14 )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y + 1 );
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init( (*pion).position.x + 2, (*pion).position.y + 2 );
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y + 1);
					return 1;
				}
			}

			return 0;
		}




		else if(direction == BAS)
		{
			if( (*pion).position.x != 15 )
			{
				position_direction=position_init( (*pion).position.x + 1, (*pion).position.y);

				if( (*pion).position.x == 14 )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y );
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init( (*pion).position.x + 2, (*pion).position.y );
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y );
					return 1;
				}
			}

			return 0;
		}




		else if(direction == BAS_GAUCHE)
		{
			if( ( (*pion).position.x != 15 ) && ( (*pion).position.y != 0 ) )
			{
				position_direction=position_init( (*pion).position.x + 1, (*pion).position.y - 1);

				if( ( (*pion).position.x == 14 ) || ( (*pion).position.y == 0 ) ) 
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y - 1);
						return 1;
					}

					return 0;
				}

				else
				{
					while(actuel != NULL)
					{

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								(*pion).position=position_init( (*pion).position.x + 2, (*pion).position.y - 2);
								return 1;
							}
							return 0;
						}

						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y - 1 );
					return 1;
				}
			}

			return 0;
		}
	}
}