#include <stdio.h>
#include <stdlib.h>
#include "VetoresC.c"

int main()
{
	int *vetorInteiro,i,num=0;
	float *vetorFlutuante;
	
	
	vetorInteiro = CriaVetInt(5);
	vetorFlutuante = CriaVetFloat(5);

	for(i=0;i<5;i++)
	{
		vetorInteiro[i]=num;
		num++;
	}
	num=0;
	for(i=0;i<5;i++)
	{
		vetorFlutuante[i]=num;
		num++;
	}


	for(i=0;i<5;i++)
	{
		printf("%d ", vetorInteiro[i]);
		
	}
	printf("\n");
	
	for(i=0;i<5;i++)
	{
		printf("%.2f ", vetorFlutuante[i]);
		
	}
		printf("\n");
	return 0;	
}
