#include <stdlib.h>
#include <stdio.h>
int isPrime(int n)
{
	int i = 3;
	if(n%2 == 0)
		return 0;
	while(i <= n/2)
	{
		if(n%i == 0)
			return 0;
		i++;
	}
	return 1;
}


int isGoldbachNumber(int n)
{
	int i=2, j=0;
	while(i <= n)
	{
		if(isPrime(i))
		{
			j=0;
			while(i+(2*j*j) < n)
				j++;
			if(i+(2*j*j) == n)
			{
				printf("%d = %d + 2×%d²\n", n, i, j);
				return 1;
			}
		}
		i++;
	}

	return 0;
}

int main()
{
	int n=5;

	while(isGoldbachNumber(n))
		n += 2;

	printf("\033[1mReponse : %d\033[0m\n", n);

	return 0;
}
