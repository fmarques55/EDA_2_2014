#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcularSoma(int numTermos, int soma)
{
	int termoAtual;
	
	if(termoAtual!=numTermos)
	{
		soma=( ( (pow( termoAtual,2 )+1 ) / (termoAtual+3) );
		
		soma=soma+calcularSoma(termoAtual+1,soma);
	}
	else
	{
		return soma;
	}
	
}
int main()
{
	
}
