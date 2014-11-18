#include <stdio.h>
#include <stdlib.h>

#include "../include/libMatrice/matrice.h"

int main()
{
	Matrice m = alloue(5,5);
	printf("%d\n", m.nbLignes);
	return 0;
}