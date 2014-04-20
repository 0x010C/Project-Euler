/*
Resolution : Je me suis pas embêté, j'y suis allé par force brute, en comptant pour chaque duo (a;b) le nombre de nombres premiers consecutifs qu'ils génèrent.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(n)
{
	int i;
	if (n <= 1)
		return 0;
	for(i=2;i<=sqrt(n);i++)
		if(n%i == 0)
			return 0;
	return 1;
}

int main()
{
	int n, a, b, nMax = 0, aMax = 0, bMax = 0;
	for(a=-999;a<1000;a++)
	{
		for(b=-999;b<1000;b++)
		{
			n=0;
			while(isPrime((n*n) + (a*n) + b))
				n++;
			if(n > nMax)
			{
				nMax = n;
				aMax = a;
				bMax = b;
			}
		}
	}  
	printf("\033[1ma=%d && b=%d\nReponse : %d\n\033[0m", aMax, bMax, aMax*bMax);
	return 0;
}

