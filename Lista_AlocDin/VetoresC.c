#include <stdio.h>
#include <stdlib.h>

int *CriaVetInt(int quant)
{
	int *pointer;
	
	pointer = malloc(quant*sizeof(int));

	return pointer;
}

float *CriaVetFloat(int quant)
{
	float *pointer;
	
	pointer = malloc(quant*sizeof(float));
	
	return pointer;
}

