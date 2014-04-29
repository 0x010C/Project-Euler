#include <stdlib.h>
#include <stdio.h>

#define LMOT 5
#define LCRYPT 1201

int find(char* mot, char* chaine)
{
int i=0, j=0;
	for(i=0;i<LCRYPT;i++)
	{
		j=0;
		while(i<LCRYPT && j<LMOT && chaine[i] == mot[j])
		{
			i++;
			j++;
		}
		if(j == LMOT)
			return 1;
	}
	return 0;
}

char* decrypt(char* crypt, char* clef)
{
	int i=0, j=0;
	char *chaine;
	chaine = (char*) malloc(sizeof(char) * LCRYPT);

	for(i=0,j=0;i<LCRYPT;i++,j++)
	{
		if(j>2)
			j = 0;
		chaine[i] = crypt[i] ^ clef[j];
	}

	return chaine;
}

int main()
{
	int i=0;
	long somme=0;
	char crypt[LCRYPT];
	char *uncrypted = NULL;
	char mot[] = " the ";
	char clef[3] = "aaa";
	FILE *fichier = NULL;

	fichier = fopen("cipher", "r");

	for(i=0;i<LCRYPT;i++)
		fscanf(fichier,"%d,", &crypt[i]);

	for(clef[0]='a';clef[0]<='z';clef[0]++)
	{
		for(clef[1]='a';clef[1]<='z';clef[1]++)
		{
			for(clef[2]='a';clef[2]<='z';clef[2]++)
			{
				if(find(mot, decrypt(crypt, clef)))
				{
					uncrypted = decrypt(crypt, clef);
					printf("Clef : %s\n%s\n", clef, uncrypted);
					for(i=0;i<LCRYPT;i++)
						somme += uncrypted[i];
					printf("\033[1mResultat : %ld\033[0m\n", somme);
				}
			}
		}
	}

	return 0;
}
