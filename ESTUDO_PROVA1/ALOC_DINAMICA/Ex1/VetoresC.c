#include <stdio.h>
#include <stdlib.h>

int *CriaVetInt(int tam)
{
	int *vetor;
	
	vetor = malloc(sizeof(tam*int));

	return vetor;
}

float *CriaVetFloat(int tam)
{
	int *vetor;
	
	vetor = malloc(sizeof(tam*float));

	return vetor;
}
