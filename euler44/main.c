/*

 */

#include <stdlib.h>
#include <stdio.h>

int isPentagonal(unsigned long long n)
{
	unsigned long long i=1;
	if(n < 1)
		return 0;
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
	unsigned long long i, j, D, pi, pj;

	for(i=1;i<3000;i++)
	{
		pi = i*(3*i-1)/2;
		for(j=1;j<i;j++)
		{
			pj = j*(3*j-1)/2;
			if(isPentagonal(pi+pj) && isPentagonal(pi-pj))
				D = pi - pj;	
		}
	}

	printf("\033[1mResultat : %lld\033[0m\n", D);

	return 0;
}
