/*
Project Euler 20
Temps d'exec : 0.001s
Reponse : 648
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main()
{
    int i = 100;
    mpz_t j, res, somme, temp, diviseur;

    mpz_init_set_si(j,10);
    mpz_init_set_si(res,1);
    mpz_init_set_si(somme,0);
    mpz_init(temp);
    mpz_init_set_si(diviseur,10);

    for(i=152;i>0;i--)
    {
        mpz_mul(diviseur,diviseur,j);
    }

    for(i=100;i>0;i--)
    {
        mpz_set_si(j,i);
        mpz_mul(res,res,j);
    }
    mpz_out_str(stdout, 10, res);
    printf("\n");

    for(i=154;i > 0;i--) //environ 160 chiffres
    {
        mpz_div(temp,res,diviseur);
        mpz_out_str(stdout, 10, temp);
        mpz_add(somme,somme,temp);
        mpz_mul(temp,temp,diviseur);
        mpz_sub(res,res,temp);
        mpz_set_si(temp,10);
        mpz_div(diviseur,diviseur,temp);
        /*
        temp = res/diviseur
        somme += temp
        res = res - (temp*diviseur)
        diviseur = diviseur / 10
        */
    }
    printf("\n");
    mpz_out_str(stdout, 10, somme);

    mpz_clear(j);
    mpz_clear(res);
    return 0;
}
