/*
Resolution : on effectue une simple boucle et on teste chaque nombres un à un. J'ai vraiment pris super large avec des unsigned long long, car je savais pas à quoi m'attendre.
*/

#include <stdlib.h>
#include <stdio.h>

unsigned long long pow5(unsigned long long n)
{
	return n*n*n*n*n;
}

int main()
{
	unsigned long long i=2;
	unsigned long long somme = 0;

	for(i=2;i<10000000;i++)
		if(pow5(i/10000000)+pow5((i%10000000)/1000000)+pow5((i%1000000)/100000)+pow5((i%100000)/10000)+pow5((i%10000)/1000)+pow5((i%1000)/100)+pow5((i%100)/10)+pow5(i%10) == i)
{		
printf("%lld\n",i);
	somme += i;
}
	printf("\033[1mResultat : %lld\033[0m\n", somme);

	return 0;
}
