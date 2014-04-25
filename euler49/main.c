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

int isPermutable(int a, int b) //on sait que a et b sont tous deux composés d'exactement 4 chiffres
{
int digit1 = a/1000;
int digit2 = (a%1000)/100;
int digit3 = (a%100)/10;
int digit4 = a%10;

if(digit1 != b/1000 && digit1 != (b%1000)/100 && digit1 != (b%100)/10 && digit1 != b%10)
	return 0;
if(digit2 != b/1000 && digit2 != (b%1000)/100 && digit2 != (b%100)/10 && digit2 != b%10)
        return 0;
if(digit3 != b/1000 && digit3 != (b%1000)/100 && digit3 != (b%100)/10 && digit3 != b%10)
        return 0;
if(digit4 != b/1000 && digit4 != (b%1000)/100 && digit4 != (b%100)/10 && digit4 != b%10)
        return 0;

return 1;
}

int main()
{
	int p=1009; //le premier nombre premier à 4 chiffres
	int pas = 1;

	for(p=1488;p<10000;p++) //je suis passé de 1009 à 1487 pour éviter que le programme s'arrête sur cette série, afin de trouver la seconde
	{
		if(isPrime(p))
		{
			for(pas=1;p+pas+pas<10000;pas++)
			{
				if(isPrime(p+pas) && isPrime(p+pas+pas))
				{
					if(isPermutable(p,p+pas) && isPermutable(p+pas,p) && isPermutable(p,p+pas+pas) && isPermutable(p+pas+pas,p))
					{
						printf("\033[1mResultat : %d%d%d\033[0m\n", p, p+pas, p+pas+pas);
						return 0;
					}
				}
			}
		}
	}

	printf("\033[1mSérie non trouvé ... :-(\033[0m\n");

	return 1;
}
