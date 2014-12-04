#include <stdlib.h>
#include <stdio.h>

int main()
{
	int valor1,valor2,soma=0,maiorValor,menorValor,i;

	printf("Entre com o primeiro valor: ");
	scanf("%d", &valor1);
	printf("Entre com o segundo valor: ");
	scanf("%d", &valor2);
	
	if(valor1<valor2)
	{
		maiorValor=valor2;
		menorValor=valor1;
	}
	else
	{
		maiorValor=valor1;	
		menorValor=valor2;
	}
	
	for(i=menorValor;i<=maiorValor;i++)
	{
		soma=soma+i;		
	}
	
	printf("SOMA = %d\n", soma);	
	
	return 0;
	
	
}
