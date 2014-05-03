/*
	Resolution : Le problème n'est pas dure en soit (on lit le fichier ligne par ligne et on somme le nombre lu), si ce n'est la taille des nombres en jeu. J'utilisa pour cela la bibliothèque "gmp" qui permet de gérer de tels nombres. Sous ubuntu, pour pouvoir l'utiliser, il faut installer le paquet "libgmp3-dev".
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void)
{
	int i=0;
	mpz_t temp;
	mpz_t somme;
	FILE* fichier;
	char* recup;

	fichier = fopen("input", "r");
	mpz_init(temp);
	mpz_init(somme);
	recup = (char*) malloc(sizeof(char) * 50);

	for(i=0;i<100;i++)
	{
		fscanf(fichier, "%s", recup);
		mpz_set_str(temp, recup, 10);
		mpz_add(somme, somme, temp);
	}
	gmp_printf("\033[1mResultat : %Zd\033[0m\n", somme);

	/* free used memory */
	mpz_clear(temp);
	mpz_clear(somme);
	return EXIT_SUCCESS;
}

