/*
Resolution : Il est interessant pour accélérer les calculs de savoir que tout les nombres hexagonal sont triangulaire (remplacez n par 2m-1 dans la formule du nombre triangulaire et tadaa).
J'ai mis énormément de temps à résoudre ce problème, car j'avais LARGEMENT sous-estimé la taille des nombres générés, ce qui entrainait des boucles infinis ...
 */

#include <stdlib.h>
#include <stdio.h>

int isPentagonal(unsigned long long n)
{
	unsigned long long i=1;
	while((i*(3*i-1))/2 < n)
	{
		i++;
	}
	if((i*(3*i-1))/2 == n)
		return 1;
	return 0;
}

int main()
{
	unsigned long long n=144;
	while(!isPentagonal(n*(2*n-1)))
	{
		n++;
		printf("%lld\n",n*(2*n-1));
	}
	printf("\033[1mResultat : %lld @ %lld\033[0m\n", n, n*(2*n-1));
	return 0;
}
