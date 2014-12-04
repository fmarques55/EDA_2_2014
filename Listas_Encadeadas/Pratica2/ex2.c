#include <stdio.h>
#include <stdlib.h>
#include "funcoes_lista_duplam.h"

typedef struct nodeStructure node;//Definicao do tipo da struct


int main()
{
	node *listHiddenHead;
	node *listHead;
	node *listTail;

	listHiddenHead=newNodeAllocation();
	listHead=listHiddenHead;
	listTail=listHead;

	int comando;//Variavel para verificar o comando do usuario
	int valueToAdd;//Valor a ser inserido pelo usuario
	int valueToRemove; //Valor que o usuario deseja remover da lista

	do
	{
		printMenu();//Imprimir menu de opcoes para o usuario
		scanf("%d", &comando);

		switch(comando)
		{
			case 1: 
			{
				printf("Entre com o numero que deseja inserir:");
				scanf("%d", &valueToAdd);

				//Se a lista estiver vazia
				if(listHead==listHiddenHead)
				{
					listHead=newNodeAllocation();
					listHead->info=valueToAdd;
					listHead->prev=listHiddenHead;
					listHead->next=NULL;

					listTail=listHead;
				}
				//Se ja existir elemento na lista
				else
				{
					listTail=includeInTail(listTail,valueToAdd);
				}
				
			}
			break;

			case 2:
			{
				printf("Entre com o numero que deseja inserir:");
				scanf("%d", &valueToAdd);

				//Se a lista estiver vazia
				if(listHead==listHiddenHead)
				{
					listHead=newNodeAllocation(); //Criando novo no
					
					/*Preenchimento do novo no*/
					listHead->info=valueToAdd;
					listHead->prev=listHiddenHead;
					listHead->next=NULL;
					/*------------------------*/

					listHiddenHead->next=listHead;
					listTail=listHead;
				}
				//Se existir elemento na lista
				else
				{
					listHead=includeInHead(listHead, valueToAdd, listTail, listHiddenHead);
				}
			}
			break;

			case 3:
			{
				if(listHiddenHead==listHead)
				{
					printf("Lista vazia\n");
				}
				else
				{
					printList(listHead);
				}
				
			}
			break;

			case 4:
			{
				printf("Entre com o elemento que deseja remover: ");
				scanf("%d", &valueToRemove);

				node *elementAddress;

				//Pegando endereco do no que sera removido
				elementAddress=getElementAddress(listHead,valueToRemove,listTail);

				if(elementAddress!=NULL)
				{
					//Se o elemento a ser removido esta no meio da lista
					if(elementAddress!=listHead && elementAddress != listTail)
					{
						removeElementKey(listHead,elementAddress);
					}
				
					else
					{
						//Remocao de cabeca
						if(elementAddress==listHead)
						{
							listHiddenHead->next=elementAddress->next;
							listHead=elementAddress->next;
							free(elementAddress);
							elementAddress=NULL;

							//Caso a cabeca seja o unico no existente
							if(listHiddenHead->next==NULL)
							{
								listHead=listHiddenHead;
								listTail=listHiddenHead;
							}
							else
							{
								//Segue o programa
							}
						}
						//Remocao da cauda
						else
						{
							node *auxiliarPointer,*elementToRemove;

							auxiliarPointer=listHead;
							elementToRemove=listTail;

							//Andando ate o penultimo no
							while(auxiliarPointer->next!=elementToRemove)
							{
								auxiliarPointer=auxiliarPointer->next;
							}

							auxiliarPointer->next=NULL;
							listTail=auxiliarPointer;
							free(elementToRemove);
							elementToRemove=NULL;

						}
					}
				}
				else
				{
					printf("O elemento nao existe na lista\n");
				}


			}
		}

	}while(comando!=0);
}