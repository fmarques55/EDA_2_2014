#include <stdio.h>
#include <stdlib.h>

void imprimeMenu()
{
	printf("Entre com o que deseja fazer:\n");
	printf("[1]. Inserir um valor em determinada posicao.\n");
	printf("[2]. Excluir elemento de determinada posicao.\n");
	printf("[3]. Verificar posicao de determinado valor.\n");
	printf("[0]. SAIR.\n");
	printf("> ");
}
int main()
{	
	int userOption,position,value,array[5];

	imprimeMenu();
	scanf("%d", &userOption);

	do
	{
		switch(userOption)
		{
			case 1: 
			{
				printf("Entre com a posicao: ");
				scanf("%d", position);
				printf("Entre com o valor que deseja inserir: ");
				scanf("%d", &value);
			
				array[position]=value;
			}
			case 2:
			{
				printf("Entre com a posicao: ");
				scanf("%d", &position);
				array[position]=-1;
			
				//Ordenacao do array
			}
			case 3:
			{
				printf("Entre com o valor que deseja pesquisar.");
				scanf("%d", &value);
			
				printf("Posicoes que ocorrem o valor informado: ");
				for(i=0;i<5;i++)
				{
					if(value==array[i])
					{
						printf("%d ");
					}
					
				}
				printf("\n");
			}
		}while(userOption!=0);
		return 0;
	}

}
