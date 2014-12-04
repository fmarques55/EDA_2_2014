#include <stdio.h>
#include <stdlib.h>

int main()
{
	int vetorNumeros[3],aux,i,j;

	printf("Entre com o primeiro numero: ");
	scanf("%d", &vetorNumeros[0]);
	printf("Entre com o segundo numero: ");
	scanf("%d", &vetorNumeros[1]);
	printf("Entre com o terceiro numero: ");
	scanf("%d", &vetorNumeros[2]);
	
	for(j=0;j<2;j++)
	{
		for(i=0;i<2;i++)
		{
			if(vetorNumeros[i]>vetorNumeros[i+1])
			{
				aux=vetorNumeros[i];
				vetorNumeros[i]=vetorNumeros[i+1];
				vetorNumeros[i+1]=aux;
			
			}
		}
	}

	//Imprimindo o vetor
	for(i=0;i<3;i++)
	{
		printf("%d ", vetorNumeros[i]);
	}
	printf("\n");

	printf("A soma dos dois maiores (%d + %d) = %d\n", vetorNumeros[1],vetorNumeros[2], vetorNumeros[1]+vetorNumeros[2]);
	return 0;
	
}
	
