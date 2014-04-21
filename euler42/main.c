/*
Resolution : On somme caractères par caractères, puis on teste s'il est triangulaire.

 */

#include <stdlib.h>
#include <stdio.h>

int isTriangular(int n)
{
	int i=1;
	while((i*(i+1))/2 < n)
		i++;
	if((i*(i+1))/2 == n)
		return 1;
	return 0;
}

int main()
{
	FILE *fichier = NULL;
	char letter = 0;
	int nbTriangular = 0, sommeMot = 0;

	fichier = fopen("word", "r");

	do
	{
		fseek(fichier, 1, SEEK_CUR);
		sommeMot = 0;
		while((letter=fgetc(fichier)) != 34)
		{
			sommeMot += letter-64;
			printf("%c", letter);
		}
		printf(" %d\n", sommeMot);
		nbTriangular += isTriangular(sommeMot);
	} while(fgetc(fichier) != 37);
	fclose(fichier);

	printf("\033[1mResultat : %d\033[0m\n", nbTriangular);

	return 0;
}
