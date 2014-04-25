#include <stdlib.h>
#include <stdio.h>

void romainToArabe(char romain[], int *arabe, int convert[])
{
	int i = 0;
	while(romain[i+1] != '\0')
	{
		if(convert[romain[i+1]-'A'] > convert[romain[i]-'A'])
			*arabe -= convert[romain[i]-'A'];
		else
			*arabe += convert[romain[i]-'A'];
		i++;
	}
	*arabe += convert[romain[i]-'A'];
}

void convert(int *valeur, char romain[], int multiple, char unite, char cinq, char dix, int *i)
{
	if(*valeur >= 9*multiple)
	{
		*valeur -= 5*multiple;
		convert(valeur, romain, multiple, unite, dix, ' ', i);
	}
	else
	{
		if(*valeur >= 5*multiple)
		{
			romain[*i] = cinq;
			(*i)++;
			*valeur -= 5*multiple;
		}
		else if(*valeur >= 4*multiple)
		{
			romain[*i] = unite;
			romain[*i+1] = cinq;
			(*i) += 2;
			*valeur -= 4*multiple;
		}
		while(*valeur >= multiple)
		{
			romain[*i] = unite;
			(*i)++;
			*valeur -= multiple;
		}
	}
}


void arabeToRomain(int arabe, char romain[])
{
	int i = 0;
	while(arabe > 1000)
	{
		romain[i] = 'M';
		arabe -= 1000;
		i++;
	}
	convert(&arabe, romain, 100, 'C', 'D', 'M', &i);
	convert(&arabe, romain, 10, 'X', 'L', 'C', &i);
	convert(&arabe, romain, 1, 'I', 'V', 'X', &i);
	romain[i+1] = '\0';
}

int nbCaractere(char *tab)
{
	int i=0;
	while(tab[i] != '\0')
		i++;
	return i;
}

void cleanTable(char *tab)
{
	int i=0;
	while(tab[i] != '\0')
	{
		tab[i] = 0;
		i++;
	}
}

int main()
{
	int convert[26] = {0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10,0,0};
	char romain[20] = "";
	int arabe = 0, somme = 0;

	FILE *fichier = NULL;
	fichier = fopen("roman", "r");

	fscanf(fichier, "%s", romain);
	while(romain[0] != '%')
	{
		somme += nbCaractere(romain);
		arabe = 0;
		printf("%s\t", romain);
		romainToArabe(romain, &arabe, convert);
		printf("%d\t", arabe);
		cleanTable(romain);
		arabeToRomain(arabe, romain);
		printf("%s\n", romain);
		somme -= nbCaractere(romain);
		fscanf(fichier, "%s", romain);
	}
	printf("\033[1mResultat : %d\033[0m\n", somme);

	return 0;
}
