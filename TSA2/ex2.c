#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*FELIPE SAMPAIO MARQUES SOUZA
MATRICULA: 12/0044934
*/

double eqRecorrencia(double n)
{
	if(n<=1)
	{
		return 1;
	}
	else
	{		
		return eqRecorrencia( (n/2) ) + pow(n,(0.5)) ;
	}
}


int main()
{
	double numero;
	double resultado;
	

	printf("Entre com um valor para n: ");
	scanf("%lf", &numero);	

	resultado = eqRecorrencia(numero);

	printf("Resultado: %.2lf", resultado);
	return 0;


}
