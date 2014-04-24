/*
Resolution : Je me suis basé pour résoudre ce problème sur cette base :
 * We are trying to solve phi(n)/(n-1)<a where a = 15499/94744.
 * This is the same as phi(n)/n + a/n < a. phi(n)/n has formula
 * prod (p-1)/p over all primes p dividing n. So the smallest n 
 * satisfying the initial conditions has primes so that phi(n)/n < a.
 * This is satisfied if the primes are consecutive 2,3,5...,23.
*/

#include <stdlib.h>
#include <stdio.h>

unsigned long long recherche()
{
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	long double ratio = 15499/94744.0;
	unsigned long long d=1, s=1;
	int p=0, i=2;
	for(p=0;p<10;p++)
	{
		d *= primes[p];
		s *= primes[p]-1;
		for(i=2;i<=primes[p];i++)
		{
			if(s*i / (d*i-1.) < ratio)
				return d*i;
		}
	}
	return 0;

}


int main()
{
	printf("%lld", recherche());
}
