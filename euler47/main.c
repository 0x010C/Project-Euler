/*
Attention : Ce programme est fonctionnel, mais il n'est pas opptimisé. Il demande plusieurs heures pour trouver la réponse ( > 5h chez moi)
*/

#include <stdlib.h>
#include <stdio.h>

int isPrime(unsigned long long n)
{
	unsigned long long i = 3;
	if(n == 2)
		return 1;
	while(i <= n/2)
	{
		if(n%i == 0)
			return 0;
		i++;
	}
	return 1;
}


long countPrimeFactors(unsigned long long n)
{
	unsigned long long i = 2;
	long nbPrimeFactors = 0;

	while(n != 1)
	{
		//printf("n=%ld\ti=%ld\n", n, i);
		if(isPrime(i) && n%i == 0)
		{
			nbPrimeFactors++;
			while(n%i == 0)
				n /= i;
		}
		i++;
	}

	return nbPrimeFactors;
}

int main()
{
	int consecutifs = 0;
	unsigned long long n = 1;

	while(consecutifs < 4)
	{
		n++;
		if(countPrimeFactors(n) >= 4)
			consecutifs++;
		else
			consecutifs = 0;
		//printf("n = %lld (%d)\n", n, consecutifs);
	}

	printf("\033[1mResultat : %lld\033[0m\n", n-3);

	//scanf("%ld", &n);
	//printf("%d\n", countPrimeFactors(n));
	return 0;
}

