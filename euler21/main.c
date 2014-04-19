/*
   Probleme 21 : Faire la somme de tous les nombre amicaux (--> Wikipédia) inférieur à 10 000
   Résolution : Pas grand chose à dire, je le fais à la brutale sans trop d'optimisation, on teste tout, tout simplement :-)
 */

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1 //uniquement pour la clareté du code
#define FALSE 0

int sommeDiviseurs(int n)
{
	int somme = 0;
	int diviseur = 1;

	for(diviseur=1;diviseur < n;diviseur++) //on teste la divisibilité avec chaque nombre successivement (théoriquement, diviseur < sqrt(n) suffit)
	{
		if(n%diviseur == 0)
			somme += diviseur;
	}
	return somme;
}

int isAmical(int n) //test si n est un nombre amicale
{
	if(sommeDiviseurs(sommeDiviseurs(n)) == n && sommeDiviseurs(n) != n)
		return TRUE;
	return FALSE;
}

int main()
{
	int i = 0;
	int somme = 0;

	for(i=2;i<10000;i++) //on teste tout les nombre jusqu'à 10 000
	{
		if(isAmical(i) == TRUE) //et on somme ceux qui sont amicaux
			somme += i;
	}

	printf("\033[1mResultat : %d\033[0m\n", somme);

	return 0;
}
