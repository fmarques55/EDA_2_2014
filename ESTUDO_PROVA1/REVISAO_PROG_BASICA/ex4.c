#include <stdio.h>
#include <stdlib.h>

int main()
{
	float numerador, denominador;
	char comando;

	do
	{
		
		printf("Entre com o numerador: ");
		scanf("%f", &numerador);
		do
		{
			printf("Entre com denominador: ");
			scanf("%f", &denominador);
		}while(denominador==0);
	
		printf("Valor da divisao: %.1f\n",numerador/denominador );

		printf("Deseja outro calculo [s/n]? ");
		scanf("%c", &comando);
	}while(comando=='S' || comando== 's');
	return 0;	
	
}
