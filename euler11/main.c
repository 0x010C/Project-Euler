/*
Problème n°11 : Il faut trouver le plus grand produit de 4 nombres en lignes (horizontale, vertical, diagonals) sur une grille de nombres (dans le fichier "grille")
Résolution : récupérer le contenu de la grille et la mettre dans un tableau, puis tester toutes les possibilités de produit.
*/

#include <stdlib.h>
#include <stdio.h>

int max(long a, long b)
{
	if(a > b)
		return a;
	return b;
}

int main()
{
/* Déclaration des variables */
FILE* fichier = NULL;
int grille[20][20];
int i, j;
long produitMax = 0;

/* Récupération de la grile */
fichier = fopen("grille", "r");

for(i=0;i<20;i++)
{
	for(j=0;j<20;j++)
		fscanf(fichier, "%d", &grille[i][j]);
}

fclose(fichier);

/* Test de tout les produits possibles */
/* Pour chaque case, on teste 4 directions (si possible) : droite, diagonale bas-droite, bas, diagonale bas-gauche */

for(i=0;i<20;i++)
{
	for(j=0;j<20;j++)
	{
		if(j <= 16) //droite
			produitMax = max(produitMax, grille[i][j]*grille[i][j+1]*grille[i][j+2]*grille[i][j+3]);
		if(i <= 16 && j <= 16) //bas-droite
			produitMax = max(produitMax, grille[i][j]*grille[i+1][j+1]*grille[i+2][j+2]*grille[i+3][j+3]);
		if(i <= 16) //bas
			produitMax = max(produitMax, grille[i][j]*grille[i+1][j]*grille[i+2][j]*grille[i+3][j]);
		if(i <= 16 && j >= 3) //bas-gauche
			produitMax = max(produitMax, grille[i][j]*grille[i+1][j-1]*grille[i+2][j-2]*grille[i+3][j-3]);
	}
}

/* Affichage de la grille */
for(i=0;i<20;i++)
{
	for(j=0;j<20;j++)
		printf("%2d ", grille[i][j]);
	printf("\n");
}

printf("\033[1mResultat : %ld\033[0m\n", produitMax);

return 0;
}
