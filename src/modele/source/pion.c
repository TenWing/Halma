
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
	//On vérifie que les pointeurs ne sont pas nuls
	if (liste_pions == NULL || pion == NULL || plateau == NULL)
	{
		//Si un d'eux est nul, on quitte le programme
		exit(EXIT_FAILURE);
	}

	//Création d'un pion fictif et de la postion de la direction où le pion doit aller
	Position position_direction;
	Pion pion_fictif;

	//Selon la direction voulue, on assigne la postion_direction
	switch(direction)
	{
	 case 0 :
		position_direction.x = (*pion).position.x;
		position_direction.y = (*pion).position.y - 2;
		break;
		
	

	 case 1 :
		position_direction.x = (*pion).position.x - 2;
		position_direction.y = (*pion).position.y - 2;
		break;

	 case 2 :
		position_direction.x = (*pion).position.x - 2;
		position_direction.y = (*pion).position.y;
		break;
	

	 case 3 :
		position_direction.x = (*pion).position.x - 2;
		position_direction.y = (*pion).position.y + 2;
		break;
	

	 case 4 :
		position_direction.x = (*pion).position.x;
		position_direction.y = (*pion).position.y + 2;
		break;
	

	 case 5 :
		position_direction.x = (*pion).position.x + 2;
		position_direction.y = (*pion).position.y + 2;
		break;
	

	 case 6 :
		position_direction.x = (*pion).position.x + 2;
		position_direction.y = (*pion).position.y;
		break;
	

	 case 7 :
		position_direction.x = (*pion).position.x + 2;
		position_direction.y = (*pion).position.y - 2;
		break;
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
	//La position de la direction souhaitée
	Position position_direction;

	//Element qui permettra de se déplacer dans la liste de pions
	Element* actuel = liste_pions -> premier;

	//Entier qui déterminera si le pion peut sauter ou non
	int saut;

	//On vérifie si les pointeurs ne sont pas nuls
	if (pion == NULL || plateau == NULL)
	{
		//Si un d'eux est nul, on quitte le programme
		exit(EXIT_FAILURE);
	}

		//On regarde qu'elle est le direction souhaitée

	switch(direction)
	{

		case 0 :
		
			// le pion est sur le bord gauche du plateau

			if((*pion).position.y!=0)
			{
				//Le pion n'est pas sur le bord extrème du plateau

				//On crée la postion de la direction
				position_direction=position_init((*pion).position.x, ((*pion).position.y) - 1);

				//On regarde s'il est sur la deuxième colonne du plateau

				if((*pion).position.y==1)
				{
					//Le pion est sur la 2ème colonne

					//On regarde si la case à côté du pion est libre ou pas
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//La case est bien lire donc on déplace le pion
						(*pion).position=position_init( (*pion).position.x, ((*pion).position.y - 1) );

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}

					//Le pion choisi a un pion à sa gauche : il ne peut pas se déplacer

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{
					//Le pion est plus loin que les deux premières colonnes
					while(actuel != NULL)
					{
						//On se déplace dans la liste


						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))
						{
							//Le pion a un pion à sa gauche

							//On regarde s'il le pion choisi peut sauter par dessus le pion
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);


							if(saut == 1)
							{
								//Le pion peut sauter

								//On change sa position
								(*pion).position=position_init((*pion).position.x, (*pion).position.y - 2);

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					//Il n'y a pas de pion à gauche du pion choisi

					//On fait avancer le pion sur sa gauche
					(*pion).position=position_init((*pion).position.x, (*pion).position.y - 1);

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//Le pion est sur la bordure extrème du plateau

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
		
			break;




		case 1 :

			//On veut déplacer le pion en haut à gauche
		
			if( ( (*pion).position.y != 0 ) && ( (*pion).position.x != 0) )
			{
				//Le pion n'est pas sur le bord extreme gauche et haut

				//On crée la position de la direction souhaitée
				position_direction=position_init( (*pion).position.x - 1, (*pion).position.y - 1 );

				if( ( (*pion).position.y == 1 ) || ( (*pion).position.x == 1) )
				{
					//Le pion est sur la limite extrème du bord gauche ou bord haut

					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//La case de la direction n'a pas de pion

						//On change la position du pion
						(*pion).position=position_init( (*pion).position.x -1, (*pion).position.y - 1);

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}
					//Il y a un pion sur la case de la direction souhaitée

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{
					//Le pion est sauf

					while(actuel != NULL)
					{
						//On se ballade dans la liste de pions

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))
						{
							//Il y a un pion en haut à gauche du pion selectionnée

							//On regarde si le pion peut ou pas sauter
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								//Le pion peut sauter

								//on change la position du pion
								(*pion).position=position_init( (*pion).position.x - 2, (*pion).position.y - 2);

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//Le pion est bloqué par un autre pion

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					(*pion).position=position_init( (*pion).position.x - 1, ((*pion).position.y) - 1);

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
		
			break;



		case 2 :

			//On veut déplacer le pion en haut

			if( (*pion).position.x != 0 )
			{
				//Le pion n'est pas sur le bord extrème du plateau

				//On crée la position de la direction
				position_direction=position_init( (*pion).position.x - 1, (*pion).position.y );

				if( (*pion).position.x == 1 )
				{
					//Le pion est sur la limite du bord extreme haut
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//la case en haut est libre pour un  déplacement

						//On change la position du pion
						(*pion).position=position_init( (*pion).position.x -1, (*pion).position.y );

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}

					//Il y a un pion qui empêche le déplacement

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{
					//Le pion est sauf
					while(actuel != NULL)
					{
						//On se ballade dans la liste

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))
						{
							//Il y a un pion en haut du pion selectionné

							//On regarde si un saut est possible
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								//Le saut est possible

								//On change la position du pion selectioné
								(*pion).position=position_init( (*pion).position.x - 2, (*pion).position.y );

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//Le saut n'est pas réalisable

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					//Il n'y a pas de pion à côté du pion selectioné

					//On change la position du pion
					(*pion).position=position_init( (*pion).position.x - 1, ((*pion).position.y) );

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
		
			break;



		case 3 :

			//On déplace le pion en haut à droite

			if( ( (*pion).position.x != 0 ) && ( (*pion).position.y != 15 ) )
			{

				//Le pion n'est pas sur le bord extreme haut et droit

				//On crée la position de la direction
				position_direction=position_init( (*pion).position.x - 1, (*pion).position.y + 1);

				if( ( (*pion).position.x == 1 ) || ( (*pion).position.y == 14 ) )
				{
					//Le pion est sur la limite de la bordure extreme

					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//On change la position du pion
						(*pion).position=position_init( (*pion).position.x -1, (*pion).position.y + 1 );

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}

					//Il y a un pion qui empêche le déplacement

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{

					//Le pion est sauf
					while(actuel != NULL)
					{

						//On se ballade dans la liste

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							//On regarde si un saut est possible
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								//Le saut est possible

								//On change la position du pion
								(*pion).position=position_init( (*pion).position.x - 2, (*pion).position.y + 2 );

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					//Il n'y a pas de pion à côté du pion selectioné

					//On change la position du pion
					(*pion).position=position_init( (*pion).position.x - 1, (*pion).position.y + 1);

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
		
			break;



		case 4 :

			//On déplace le pion à droite

			if( (*pion).position.y != 15  )
			{

				//On crée la position de la direction
				position_direction=position_init( (*pion).position.x, (*pion).position.y + 1);

				if( (*pion).position.y == 14 )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//On change la position du pion
						(*pion).position=position_init( (*pion).position.x, (*pion).position.y + 1 );

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}

					//Il y a un pion qui empêche le déplacement

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{

					//Le pion est sauf
					while(actuel != NULL)
					{

						//On se ballade dans la liste

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							//On regarde si un saut est possible
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								//Le saut est possible

								//On change la position du pion
								(*pion).position=position_init( (*pion).position.x, (*pion).position.y + 2 );

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					//Il n'y a pas de pion à côté du pion selectioné

					//On change la position du pion
					(*pion).position=position_init( (*pion).position.x, (*pion).position.y + 1);

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
		
			break;



		case 5 :

			//On déplace le pion en bas à droite

			if( ( (*pion).position.y != 15 ) && ( (*pion).position.x != 15 ) )
			{

				//On crée la position de la direction
				position_direction=position_init( (*pion).position.x + 1, (*pion).position.y + 1);

				if( (*pion).position.y == 14 || (*pion).position.x == 14 )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//On change la position du pion
						(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y + 1 );

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}

					//Il y a un pion qui empêche le déplacement

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{

					//Le pion est sauf
					while(actuel != NULL)
					{

						//On se ballade dans la liste

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							//On regarde si un saut est possible
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								//Le saut est possible

								//On change la position du pion
								(*pion).position=position_init( (*pion).position.x + 2, (*pion).position.y + 2 );

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					//Il n'y a pas de pion à côté du pion selectioné

					//On change la position du pion
					(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y + 1);

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
		

			break;


		case 6 :

			//On déplace le pion en bas

			if( (*pion).position.x != 15 )
			{

				//On crée la position de la direction
				position_direction=position_init( (*pion).position.x + 1, (*pion).position.y);

				if( (*pion).position.x == 14 )
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//On change la position du pion
						(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y );

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}

					//Il y a un pion qui empêche le déplacement

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{

					//Le pion est sauf
					while(actuel != NULL)
					{

						//On se ballade dans la liste

						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							//On regarde si un saut est possible
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								//Le saut est possible

								//On change la position du pion
								(*pion).position=position_init( (*pion).position.x + 2, (*pion).position.y );

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					//Il n'y a pas de pion à côté du pion selectioné

					//On change la position du pion
					(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y );

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
		
			break;



		case 7 :

			//On déplace le pion en bas à gauche

			if( ( (*pion).position.x != 15 ) && ( (*pion).position.y != 0 ) )
			{

				//On crée la position de la direction
				position_direction=position_init( (*pion).position.x + 1, (*pion).position.y - 1);

				if( ( (*pion).position.x == 14 ) || ( (*pion).position.y == 0 ) ) 
				{
					if( (plateau_getpion(position_direction, plateau, liste_pions)).identifiant == -1)
					{
						//On change la position du pion
						(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y - 1);

						//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
						return 1;
					}

					//Il y a un pion qui empêche le déplacement

					//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
					return 0;
				}

				else
				{
					//Le pion est sauf

					while(actuel != NULL)
					{
						//On se ballade dans la liste
						
						if((actuel -> pion.position.x == position_direction.x )&& 
							(actuel -> pion.position.y == position_direction.y))

						{
							//On regarde si un saut est possible
							saut=pion_peut_sauter(pion,direction,plateau,liste_pions);

							if(saut == 1)
							{
								//Le saut est possible

								//On change la position du pion
								(*pion).position=position_init( (*pion).position.x + 2, (*pion).position.y - 2);

								//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
								return 1;
							}

							//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
							return 0;
						}

						//On pointe sur le suivant tant que la condition n'est pas vérifiée
						actuel = actuel -> suivant;
					}

					//Il n'y a pas de pion à côté du pion selectioné

					//On change la position du pion
					(*pion).position=position_init( (*pion).position.x + 1, (*pion).position.y - 1 );

					//On retourne la valeur 1 pour dire que le déplacement a bien eu lieu
					return 1;
				}
			}

			//On retourne la valeur 0 pour dire que le déplacement n'a bien eu lieu
			return 0;
			break;		
	}
}