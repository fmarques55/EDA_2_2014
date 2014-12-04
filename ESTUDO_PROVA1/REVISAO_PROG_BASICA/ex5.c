#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array[10],value,i;

	//Preenchimento do array
	for(i=0;i<10;i++)
	{
		printf("Entre com o valor para a posicao %d: ",i);
		scanf("%d", &array[i]);
	}
	
	printf("Entre com um valor para ser pesquisado: ");
	scanf("%d", &value);

	printf("Indices do array que aparecem o valor informado: \n");
	for(i=0;i<10;i++)
	{
		if(value==array[i])
		{
			printf("%d ", i);		
		}
	}
	printf("\n");
	return 0;
	
}
