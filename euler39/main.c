/*
Resolution : Par la force brut, on calcul le perimètre d'un grand nombre de triplet, on incremente le p correspondant si ≤ 1000
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i, j, k, iMax = 0, pMax = 0;
	int p[1001] = {0}; //pour avoir l'index qui correspond au perimetre réel, on aura 4 cases vides au début

	for(i=1;i<=998;i++)
	{
		for(j=1;i+j<=999;j++)
		{
			for(k=1;i+j+k<=1000;k++)
			{
				if((i*i)+(j*j) == (k*k))
					p[i+j+k]++;
			}
		}
	}

	for(i=0;i<=1000;i++)
	{
		if(p[i] > pMax)
		{
			pMax = p[i];
			iMax = i;
}
	}

	printf("\033[1mResultat : %d\033[0m\n", iMax);

	return 0;
}
