/*

 */

#include <stdlib.h>
#include <stdio.h>

int isPandigital(int *tab, int size)
{
	int i=0;
	int chiffre[10] = {1,0,0,0,0,0,0,0,0,0}; //le 1 est en position 0 car on ne veut que des chiffres de 1 à 9

	for(i=0;i<size;i++)
	{
		if(tab[i] > 100000)
			chiffre[(tab[i]%1000000)/100000]++;
		if(tab[i] > 10000)
			chiffre[(tab[i]%100000)/10000]++;
		if(tab[i] > 1000)
			chiffre[(tab[i]%10000)/1000]++;
		if(tab[i] > 100)
			chiffre[(tab[i]%1000)/100]++;
		if(tab[i] > 10)
			chiffre[(tab[i]%100)/10]++;
		chiffre[tab[i]%10]++;
	}

	for(i=0;i<10;i++)
		if(chiffre[i] != 1)
			return 0;

	return 1;
}


int main()
{
	int n, i, j;
	int tab[9];

	for(n=2;n<=9;n++)
	{
		for(i=1;i<10000;i++) //je reste comme d'hab très large sur les bornes pour éviter de louper des valeurs
		{
			for(j=0;j<n;j++)
				tab[j]=i*(j+1);
			if(isPandigital(tab, n))
			{
				for(j=0;j<n;j++)
					printf("%d", tab[j]);
				printf("\n");
			}
		}
	}
	return 0;
}
