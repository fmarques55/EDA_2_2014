#include <stdio.h>
#include <stdlib.h>

float calcularMediaVendas(struct vendedor *ARRAY, int numFuncionarios)
{
	int i;
	float mediaVendas=0;
	
	for(i=0;i<numFuncionarios;i++)
	{
		mediaVendas=mediaVendas+ARRAY[i]->vendas;
	}

	return mediaVendas;
}
