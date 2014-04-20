/*
Resolution : Pas tres complexe, tester chaque chiffre un a un, stoquer le compte dans un tableau et voir s'il n'y a pas de doublon où de manque. Et faire ca pour chaque paire de nombre (i,j) tel que i*j=k
 */

#include <stdlib.h>
#include <stdio.h>

int isPandigital(int a, int b, int c)
{
	int i = 0;
	int chiffre[10] = {1,0,0,0,0,0,0,0,0,0}; //le 1 est en position 0 car on ne veut que des chiffres de 1 à 9

	if(a > 1000)
		chiffre[a/1000]++;
	if(a > 100)
		chiffre[(a%1000)/100]++;
	if(a > 10)
		chiffre[(a%100)/10]++;
	chiffre[a%10]++;

	if(b > 1000)
		chiffre[b/1000]++;
	if(b > 100)
		chiffre[(b%1000)/100]++;
	if(b > 10)
		chiffre[(b%100)/10]++;
	chiffre[b%10]++;


	if(c > 100000)
		chiffre[(c%1000000)/100000]++;
	if(c > 10000)
		chiffre[(c%100000)/10000]++;
	if(c > 1000)
		chiffre[(c%10000)/1000]++;
	if(c > 100)
		chiffre[(c%1000)/100]++;
	if(c > 10)
		chiffre[(c%100)/10]++;
	chiffre[c%10]++;

	for(i=0;i<10;i++)
		if(chiffre[i] != 1)
			return 0;

	return 1;
}

int inTable(int n, int *table, int size)
{
int i=0;

for(i=0;i<size;i++)
	if(table[i] == n)
		return 1;
return 0;
}

int main()
{
	int i, j, somme = 0, nbPandigital = 0;
	int pandigital[20]; //pour eviter les doublons

	for(i=1;i<10000;i++)
	{
		for(j=1;j<1000;j++)//limite a revoir
		{
			if(isPandigital(i,j,i*j) && !inTable(i*j, pandigital, nbPandigital))
			{
				printf("%d * %d = %d\n", i, j, i*j);
				somme += i*j;
				pandigital[nbPandigital] = i*j;
				nbPandigital++;
			}
		}
	}
	printf("\033[1mReponse : %d\033[0m\n", somme);
	return 0;
}
