/*
Resolution : Le problème n'est pas dure en soit (on somme le terme courant avec le précédent, et on compte le nombre de chiffre), si ce n'est la taille des nombres en jeu. J'utilisa pour cela la bibliothèque "gmp" qui permet de gérer de tels nombres. Sous ubuntu, pour pouvoir l'utiliser, il faut installer le paquet "libgmp3-dev".
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main()
{
	int i=0;
	mpz_t temp;
	mpz_t current;
	mpz_t prev;
	mpz_t n;

	mpz_init(temp);
	mpz_init(current);
	mpz_init(prev);
	mpz_init(n);

	mpz_set_str(current, "1", 10);
	mpz_set_str(prev, "1", 10);
	mpz_set_str(n, "3", 10);

	while(mpz_sizeinbase(current, 10) < 1000)
	{
		mpz_add_ui(n, n, 1);
		mpz_add(temp, current, prev);
		mpz_set(prev, current);
		mpz_set(current, temp);
	}
	gmp_printf("\033[1mResultat : Fib(%Zd) = %Zd\033[0m\n", n, current);

	mpz_clear(temp);
	mpz_clear(prev);
	mpz_clear(current);
	mpz_clear(n);
	return 0;
}

