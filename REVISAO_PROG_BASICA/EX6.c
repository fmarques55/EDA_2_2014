#include <stdio.h>
#include <stdlib.h>


int main()
{
	int vetor[5],numero,posicao,j,i;
	char comando;

	//INICIALIZANDO O VETOR COMO VAZIO
	for(i=0;i<4;i++)
	{
		vetor[i]=-1;
	}

	do
	{
		printf("\nEntre com uma das opcoes abaixo: \n");
		printf("[I] - Incluir um elemento em uma posicao\n");
		printf("[E] - Excluir um elemento de determinada posicao\n");
		printf("[B] - Buscar determinado valor no vetor\n");		
		printf("[*] - Para finalizar o programa\n");	
		printf("> ");
		scanf("%c", &comando);

		switch(comando)
		{
			case 'i':
			case 'I':
			printf("Entre com a posicao que deseja adicionar: ");
			__fpurge(stdin);
			scanf("%d",&posicao);
			printf("Entre com o numero que deseja adicionar");
			__fpurge(stdin);
			scanf("%d", &numero);
			
			vetor[posicao]=numero;
			//IMPRIMINDO O VETOR
			for(i=0;i<4;i++)
			{
				printf("%d ", vetor[i]);
			}
			printf("\n\n\n");
			break;

			case 'e':
			case 'E':
			printf("Entre com a posicao que deseja remover: ");
			__fpurge(stdin);
			scanf("%d", &posicao);
			
			vetor[posicao]=-1;
			printf("\n\n\n");
			
			//COLOCANDO OS ESPACOS VAZIOS A DIREITA
			for(j=0;j<4;j++)
			{
				for(i=0;i<3;i++)
				{
					if(vetor[i]==-1)
					{
						int aux;
					
						aux=vetor[i];
						vetor[i]=vetor[i+1];
						vetor[i+1]=aux;
					}
				}
			}
			
			//IMPRIMINDO O VETOR
			for(i=0;i<4;i++)
			{
				printf("%d ", vetor[i]);
			}
			printf("\n\n\n");
			break;
				 
		}
		

	}while(comando!='*');

	return 0;
}
