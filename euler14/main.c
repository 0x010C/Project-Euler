/*
   Probleme 14 : Trouver le nombre <= 1 000 000 qui produit la plus longue chaine de Collatz (--> Wikipedia)
Resolution : Ce problème nécessite de manière évidente une simple fonction récursive.
 */

#include <stdlib.h>
#include <stdio.h>

long collatz(long n) //La fonction retourne le nombre de maillons de la chaine commencant par nb (passé en paramètre)
{
	if(n == 1) // cas trivial
		return 1;
	else if(n%2 == 0) // si n est pair
		return collatz(n/2) + 1;
	else // si n est impaire
		return collatz((3*n)+1) + 1;
}

int main()
{
	/* Déclaration des variables */
	long n = 0, nMax = 0, l = 0, lMax = 0;

	/* On teste chaque nombre un par un */
	for(n=1;n<=1000000;n++)
	{
		l=collatz(n);
		if(l > lMax)
		{
			lMax = l;
			nMax = n;
		}
	}

	printf("\033[1mResultat : %ld\033[0m\n", nMax);
	return 0;
}
