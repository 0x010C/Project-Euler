/*
   Probleme n°12 : Le but est de trouver le premier nombre triangulaire à avoir plus de 500 diviseurs
Algos :
- Pour trouver un nombre triangulaire, on a deux façons symples : Un = U(n-1) + n et Un = [n(n+1)]/[2]
- Pour trouver le nombre de diviseurs N , on fait N = (x+1)*(y+1)*(z+1)*... si la decomposition en facteurs premiers est  a^x+b^y+c^z+...
 */

#include <stdlib.h>
#include <stdio.h>

int countDivisors(unsigned long long nb)
{
	int puissances[80]; //On va stoquer dans ce tableau les puissances des diviseurs
	int diviseur=2;
	int i=0, j=0;
	int nbFactors=1;

	puissances[0] = 0;
	while(diviseur <= nb) //on effectue des divisions successive
	{		
		if(nb%diviseur == 0) //si le nombre est divisible par le diviseur, on fait la division
		{
			puissances[i]++;
			nb /= diviseur;
		}
		else //sinon on cherche un autre diviseur
		{
			if(puissances[i] > 0)
			{
				i++;
				puissances[i] = 0;
			}
			diviseur++;
		}
	}

	for(j=i;j>=0;j--)
		nbFactors *= puissances[j]+1;

	return nbFactors;
}

int main()
{
	unsigned long long Un = 1, n = 1; //Je sais pas trop à quoi m'attendre, donc je mets le max
	while(countDivisors(Un) < 500) //On cherche un nombre avec plus de 500 diviseurs
	{
		n++;
		Un += n; //Un = U(n-1) + n
		printf("U_%lld = %lld\n", n, Un);
	}

	return 0;
}
