#include <stdio.h>
#include <stdlib.h>

int main()
{
	char comando,aux;
	float numerador,denominador=1,resultado;
	int cont;

	do
	{
		printf("Entre com o numerador: ");
		scanf("%f", &numerador);
		do
		{
			printf("Entre com o denominador \n(VALOR DEVE SER DIFERENTE DE ZERO): ");
			__fpurge(stdin);
			scanf("%f", &denominador);
			if(denominador==0)
			{
				printf("VALOR INVALIDO! TENTE NOVAMENTE!\n");
			}
		}while(denominador==0);
		
		resultado=numerador/denominador;
		printf("Resultado da divisao: %.1f\n", resultado);
		printf("PRESSIONE ENTER PARA CONTINUAR!\n");
		system("read aux");
		system("clear");		
		printf("Deseja fazer mais alguma operacao? (s/n): ");
		__fpurge(stdin);
		scanf("%c", &comando);
		cont++;
				
			
		
	}while(comando=='S' || comando == 's');

	printf("Foram realizadas %d operacoes\n", cont);
	return 0;
}
