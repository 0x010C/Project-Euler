#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
	int i = 3;
	if(n%2 == 0)
		return 0;
	while(i <= sqrt(n))
	{
		if(n%i == 0)
			return 0;
		i++;
	}
	return 1;
}

int main()
{
unsigned long long i, j, somme, sommeMax, nbConsecutive, nbConsecutiveMax;

	for(i=2;i<1000000;i++)
	{
		if(isPrime(i))
		{
			somme = i;
			nbConsecutive=0;
			for(j=i+1;somme<1000000;j++)
			{
				if(isPrime(j))
				{
					somme += j;
					nbConsecutive++;
					if(nbConsecutive > nbConsecutiveMax && isPrime(somme))
					{
						nbConsecutiveMax = nbConsecutive;
						sommeMax = somme;
					}
				}
			}
		}
	}
	printf("\033[1mResultat : %lld\033[0m\n", sommeMax);
	return 1;
}
