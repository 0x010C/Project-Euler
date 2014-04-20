/*

 */

#include <stdlib.h>
#include <stdio.h>

int nbWays(int n)
{
	switch(n)
	{
		case 1: //cas triviaux
			return 1;
			break;
		case 2: //cas triviaux
			return 2;
			break;
		case 5:
			return 1+(nbWays(2))+nbWays(1);
			break;
		case 10:
			return 1+(nbWays(5));
			break;
		case 20:
			return 1+(nbWays(10));
			break;
		case 50:
			return 1+(nbWays(20))+nbWays(10);
			break;
		case 100:
			return 1+(nbWays(50));
			break;
		case 200:
			return 1+(nbWays(100));
			break;
	}
}

int main()
{
	printf("%d\n", nbWays(200));
	return 0;
}
