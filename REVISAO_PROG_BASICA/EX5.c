#include <stdio.h>
#include <stdlib.h>



int main()
{
	int array[10],numero,i;

	//PREENCHENDO O VETOR	
	for(i=0;i<10;i++)
	{
		printf("Entre com um numero para a posicao [%d]: ",i );
		scanf("%d", &array[i]);
	}

	printf("Entre com um numero a ser pesquisado: ");
	scanf("%d", &numero);

	printf("Posicoes do vetor ocupado pelo numero informado: ");
	//PERCORRENDO O VETOR
	for(i=0;i<10;i++)
	{
		if(numero==array[i])
		{
			printf("%d ", i);
		}
		else
		{
			
		}
	}
	printf("\n");
	return 0;
	
	
}
