#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1,num2,cont,final,soma;

	printf("Entre com o primeiro numero: ");
	scanf("%d", &num1);
	printf("Entre com o segundo numero: ");
	scanf("%d", &num2);
	
	if(num1<num2)
	{
		cont = num1;
		final=num2;
	}	
	else
	{
		cont= num2;
		final=num1;
	}
	
	soma=0;
	while(cont!=final)
	{
		soma=soma+cont;
		cont++;
	}
	if(cont==final)
	{
		soma=soma+cont;
	}
	printf("SOMA=[%d]\n", soma);
	return 0;
}
