#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arrayValores[3],i,j,aux;

	//Preenchimento do array
	for(i=0;i<3;i++)
	{
		printf("Entre com o valor %d: ",i);
		scanf("%d", &arrayValores[i]);
	}

	//Ordenacao do vetor
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arrayValores[j]>arrayValores[j+1])
			{
				aux=arrayValores[j];
				arrayValores[j]=arrayValores[j+1];
				arrayValores[j+1]=aux;
			}
			else
			{
				//Fazer nada
			}
		}
	}
	
	printf("Soma dos dois maiores = %d\n", arrayValores[1]+arrayValores[2]);
	
	
	
	

	return 0;	

}
