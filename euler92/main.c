/*

 */

#include <stdlib.h>
#include <stdio.h>

int pow2(int n)
{
	return n*n;
}

unsigned long long sd(unsigned long long n) //TODO: square digit
{
	unsigned long long somme = 0;

	somme += pow2((n%100000000)/10000000);
	somme += pow2((n%10000000)/1000000);
	somme += pow2((n%1000000)/100000);
	somme += pow2((n%100000)/10000);
	somme += pow2((n%10000)/1000);
	somme += pow2((n%1000)/100);
	somme += pow2((n%100)/10);
	somme += pow2((n%10)/1);

	return somme;
}

int sdc(unsigned long long n) //square digit chains
{
	if(n == 1)
		return 1;
	else if(n == 89)
		return 89;
	else
		return sdc(sd(n));
}

int main()
{
	unsigned long long i, somme = 0;

	for(i=1;i<10000000;i++)
	{
		if(sdc(i) == 89)
			somme++;
	}

	printf("\033[1mResultat : %lld\033[0m\n", somme);

	return 0;
}
