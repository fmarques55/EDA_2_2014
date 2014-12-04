#include <stdio.h>
#include <stdlib.h>
#include "funcoes_pilha.h"

typedef struct nodeStructure node;

 void printMenu()
 {
 	printf("Entre com uma das opcoes abaixo:\n");
 	printf("[1] - Empilhar elemento\n");
 	printf("[2] - Desempilhar\n" );
 	printf("[3] - Esvaziar pilha\n" );
 	printf("[0] - Finalizar o programa\n");
 	printf("> ");
 }
int main()
{
	node *listHiddenHead;
	node *topo;

	listHiddenHead=newElementAllocation();
	topo=listHiddenHead;

	int comando; //Variavel do comando do usuario no menu
	int valueToAdd; //Variavel com o valor informado pelo usuario
	
	node *getValue;

	do
	{
		printMenu(); //Funcao para imprimir o menu de opcoes
		scanf("%d", &comando);

		switch(comando)
		{
			case 1: //Empilhar
			{
				printf("Entre com o valor que deseja empilhar:\n");
				scanf("%d", &valueToAdd);

				topo=empilha(topo, valueToAdd,listHiddenHead);
			}
			break;

			case 2: //Desempilhar
			{
				getValue = desempilha(topo, listHiddenHead);
				topo=listHiddenHead->next;
				
				if(getValue!=NULL)
				{
					printf("%d\n", getValue->info);
				}
				else
				{
					printf("Pilha vazia\n");
				}
			}
			break;

			case 3: //Esvaziar pilha
			{
				while(getValue!=NULL)
				{
					getValue=desempilha(topo,listHiddenHead);
					free(getValue);
				}
			}


		}
	}while(comando!=0);
}