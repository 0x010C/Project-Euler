/*
   Probleme 17 : Le but est de compter le nombre de lettre dans les chiffres de 1 à 1000 écrit en lettres (en anglais et sans compter espaces et tirets)
Resolution : L'idee est de ne pas compter réellement les lettres, mais associer à chaque chiffre le nombre de lettres correspondantes à l'aide de "switch"
 */

#include <stdlib.h>
#include <stdio.h>

int comptage(int n)
{
	int nbCaracteres = 0;
	switch(n/1000)
	{
		case 1:
			nbCaracteres += 3+8;//one + thousand
			break;
	}
	n%=1000;
	switch(n/100)
	{
		case 1:
			nbCaracteres += 3+7; //one + hundred
			break;
		case 2:
			nbCaracteres += 3+7; //two + hundred
			break;
		case 3:
			nbCaracteres += 5+7; //etc
			break;
		case 4:
			nbCaracteres += 4+7;
			break;
		case 5:
			nbCaracteres += 4+7;
			break;
		case 6:
			nbCaracteres += 3+7;
			break;
		case 7:
			nbCaracteres += 5+7;
			break;
		case 8:
			nbCaracteres += 5+7;
			break;
		case 9:
			nbCaracteres += 4+7;
			break;
	}
	if(n/100 != 0 && n%100 != 0)
		nbCaracteres += 3; //and
	n%=100;

	switch(n/10)
	{
		case 1:
			switch(n)
			{
				case 10:
					nbCaracteres += 3; //ten
					break;
				case 11:
					nbCaracteres += 6; //eleven
					break;
				case 12:
					nbCaracteres += 6; //twelve
					break;
				case 13:
					nbCaracteres += 8; //thirteen
					break;
				case 14:
					nbCaracteres += 8; //fourteen
					break;
				case 15:
					nbCaracteres += 7; //fifteen
					break;
				case 16:
					nbCaracteres += 7; //sixteen
					break;
				case 17:
					nbCaracteres += 9; //seventeen
					break;
				case 18:
					nbCaracteres += 8; //eighteen
					break;
				case 19:
					nbCaracteres += 8; //nineteen
					break;
			}
			break;
		case 2:
			nbCaracteres += 6; //twenty
			break;
		case 3:
			nbCaracteres += 6; //thirty
			break;
		case 4:
			nbCaracteres += 5; //forty
			break;
		case 5:
			nbCaracteres += 5; //fifty
			break;
		case 6:
			nbCaracteres += 5; //sixty
			break;
		case 7:
			nbCaracteres += 7; //seventy
			break;
		case 8:
			nbCaracteres += 6; //eighty
			break;
		case 9:
			nbCaracteres += 6; //ninety
			break;
	}
	if(n/10 == 1)
		return nbCaracteres;

	n%=10;
	switch(n)
	{
		case 1:
			nbCaracteres += 3; //one
			break;
		case 2:
			nbCaracteres += 3; //two
			break;
		case 3:
			nbCaracteres += 5; //three
			break;
		case 4:
			nbCaracteres += 4; //four
			break;
		case 5:
			nbCaracteres += 4; //five
			break;
		case 6:
			nbCaracteres += 3; //six
			break;
		case 7:
			nbCaracteres += 5; //seven
			break;
		case 8:
			nbCaracteres += 5; //eight
			break;
		case 9:
			nbCaracteres += 4; //nine
			break;
	}

	return nbCaracteres;
}
int main()
{
	int n = 1;
	long nbCaracteresTotal = 0;

	for(n=1;n<=1000;n++)
		nbCaracteresTotal += comptage(n);

	printf("\033[1mResultat : %ld\033[0m\n", nbCaracteresTotal);

	return 0;
}
