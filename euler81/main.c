/*
Resolution : la stratégie est similaire à celle des problèmes 18 et 67 : on remplace de proche en proche chaque case par elle même + min(celle au dessus ; celle à gauche)
 */

#include <stdlib.h>
#include <stdio.h>

int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int main()
{
	int matrix[80][80] = {0};
	FILE *fichier = NULL;
	int i=0, j=0;

	fichier = fopen("matrix", "r");

	for(i=0;i<80;i++)
		for(j=0;j<80;j++)
			fscanf(fichier,"%d,", &matrix[i][j]);

	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
		{
			if(i == 0 && j != 0)
				matrix[i][j] += matrix[i][j-1];
			else if(j == 0 && i != 0)
				matrix[i][j] += matrix[i-1][j];
			else if(j != 0 || i != 0)// pour eviter la case 0,0
				matrix[i][j] += min(matrix[i-1][j],matrix[i][j-1]);
		}
	}

	printf("\033[1mResultat : %d\033[0m\n", matrix[79][79]);

	return 0;
}
