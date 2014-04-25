#include <stdlib.h>
#include <stdio.h>

unsigned long long pow10(int p) //10^p
{
	int i=0;
	unsigned long long produit = 1;
	for(i=0;i<p;i++)
		produit *= 10;
	return produit;
}

int countDigit(unsigned long long n)
{
	int nb=0;

	while(n != 0)
	{
		n /= 10;
		nb++;
	}

	return nb;
}

unsigned long long reverse(unsigned long long n)
{
	int j;
	int nbDigit = countDigit(n);
	unsigned long long reverseNumber = 0;

	for(j=nbDigit-1;j>=0;j--)
	{
		reverseNumber += (n%10)*pow10(j);
		n /= 10;
	}

	return reverseNumber;
}

int isPalindrome(unsigned long long n)
{
	if(n == reverse(n))
		return 1;
	else
		return 0;
	/*
	//Version sans la fonction reverse
	int nbDigit = countDigit(n);
	int i, j;
	for(i=1,j=nbDigit;i<j;i++,j--)
	{
	if((n%pow10(i))/pow10(i-1) != (n%pow10(j))/pow10(j-1))
	return 0;
	}
	return 1;
	 */
}

int isLychrel(unsigned long long n, int degre)
{
	if(isPalindrome(n))
		return 0;
	if(degre >= 50)
		return 1;
	return isLychrel(n+reverse(n), degre+1);
}

int main()
{
	unsigned long long nbLychrel = 0;
	int i;
	for(i=1;i<=10000;i++)
		nbLychrel += isLychrel(i+reverse(i),1);

	printf("\033[1mResultat : %lld\033[0m\n", nbLychrel);

	return 0;
}
