/*
   Probleme 67 : Ce problème est identique au probleme 18, à la taille du triangle près. Pour plus d'info, voir ce dernier :-)
*/

#include <stdlib.h>
#include <stdio.h>
#define TAILLE 100

int main()
{
	/* Déclaration des variables */
	FILE* fichier = NULL;
	int grille[TAILLE][TAILLE];
	int i, j;
	long sommeMax = 0;

	/* Récupération du triangle */
	fichier = fopen("triangle", "r");

	for(i=0;i<TAILLE;i++)
	{
		for(j=0;j<=i;j++)
			fscanf(fichier, "%d", &grille[i][j]);
	}

	fclose(fichier);

	/* On somme case par case en fonction de la brique la plus élevée des deux du dessus */
	for(i=1;i<TAILLE;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j == 0) //si on est au bord gauche, y a pas le choix
				grille[i][j] += grille[i-1][j];
			else if(j == i) //idem si on est au bord droit
				grille[i][j] += grille[i-1][j-1];
			else if(grille[i-1][j-1] >= grille[i-1][j]) //sion on cheque le plus grand des deux au dessus, et on somme en fonction
				grille[i][j] += grille[i-1][j-1];
			else
				grille[i][j] += grille[i-1][j];
		}
	}

	/* On parcours la dernière ligne pour checker la plus grande somme */
	for(j=0;j<TAILLE;j++)
	{
		if(grille[TAILLE-1][j] > sommeMax)
			sommeMax = grille[TAILLE-1][j];
	}

	/* On affiche le triangle, pour le lolz */
	for(i=0;i<TAILLE;i++)
	{
		for(j=0;j<=i;j++)
			printf("%2d ", grille[i][j]);
		printf("\n");
	}

	/* Et voilà enfin le resultat */
	printf("\033[1mResultat : %ld\033[0m\n", sommeMax);

	return 0;
}
