/**
 * \file      testModele.c
 * \author    Geliot
 * \version   1.0
 * \date      19 Novembre 2014
 * \brief     Teste les fonctions de l'Halma
 *
 *
 *            
 */

#include <stdio.h>
#include <stdlib.h>


#include <pion.h>
#include <coup.h>

 int main () 
 {
 
Pion pion;
pion.position.x=7;
pion.position.y=7;

printf("x=%d\n", pion.position.x);
printf("y=%d\n", pion.position.y);

pion=init_pion(1,1,2,0);

printf("x=%d\n", pion.position.x);
printf("y=%d\n", pion.position.y);

pion=coupSimple(pion,0,0);

printf("x=%d\n", pion.position.x);
printf("y=%d\n", pion.position.y);
if(pion.position.x != 0 || pion.position.y != 0)
{
	printf("erreur de la fonction coupSimple\n");
}
else
{
	printf("ca fonctionne\n");
}


 return 0;}