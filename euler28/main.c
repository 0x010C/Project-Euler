/*
Probleme 28 : dans une grille de 1001x1001, on desine une spirale de nombre de 1 en 1, à partir du centre. Le but est de trouver la somme de tous les nombres diagonaux.
Resolution : On peut remarquer que la diagonale haut-droite est une série de carré des nombres impaires. Ducoup, on a :
    3²         5²         7²
    3²-2       5²-4       7²-6
    3²-2-2     5²-4-4     7²-6-6
1 + 3²-2-2-2 + 5²-4-4-4 + 7²-6-6-6 + ...
Une fois cela constaté, ca deviens une bête boucle for à réaliser.
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
	unsigned long long somme = 1;
	int n = 2;

	for(n=2;n<=1001;n=n+2)
		somme += 4*(n+1)*(n+1) - (6*n);

	printf("\033[1mResultat : %lld\033[0m\n",somme);
	return 0;
}
