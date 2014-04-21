/*

*/

#include <stdlib.h>
#include <stdio.h>

long factorial(int n)
{
	long resultat = 1, i = 1;

	for(i=1;i<=n;i++)
		resultat *= i;

	return resultat;
}

int isDigitalFactorials(long n)
{
	int sommeFact = 0;

	if(n/100000 != 0)
		sommeFact = factorial((n%1000000)/100000)+factorial((n%100000)/10000)+factorial((n%10000)/1000)+factorial((n%1000)/100)+factorial((n%100)/10)+factorial(n%10);
	else if(n/10000 != 0)
		sommeFact = factorial((n%100000)/10000)+factorial((n%10000)/1000)+factorial((n%1000)/100)+factorial((n%100)/10)+factorial(n%10);
	else if((n%10000)/1000 != 0)
		sommeFact = factorial((n%10000)/1000)+factorial((n%1000)/100)+factorial((n%100)/10)+factorial(n%10);
	else if((n%1000)/100 != 0)
		sommeFact = factorial((n%1000)/100)+factorial((n%100)/10)+factorial(n%10);
	else if((n%100)/10 != 0)
		sommeFact = factorial((n%100)/10)+factorial(n%10);
	else
		sommeFact = factorial(n%10); 

	if(sommeFact == n)
		return 1;
	return 0;
}

int main()
{
	long n = 3; //on ne veut pas prendre en compte les cas particuliers 1 et 2
	long somme = 0;

	for(n=3;n<999999;n++)//on va jusqu'à une limite arbitraire, un peu au pif vu que je sais pas a quoi m'attendre ...
	{
		if(isDigitalFactorials(n))
		{
			printf("%ld\n", n);
			somme += n;
		}
	}
	printf("\033[1mResultat : %ld\033[0m\n", somme);

	return 0;
}
