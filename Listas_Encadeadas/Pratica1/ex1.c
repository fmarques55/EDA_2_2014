#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

typedef struct nodeStructure node; //Definicao do tipo node


int main()
{
	node *listHiddenHead; //Endereco da cabeca da lista
	node *listTail; //Endereco da cauda da lista
	node *listHead;

	listHiddenHead=newNodeAllocation(); //Criacao do no oculto da cabeca
	listHead=listHiddenHead; //O no da cabeca aponta para o oculto pois a lista so tem 1 elemento
	listTail=listHiddenHead;//O no da cauda aponta para a cabeca oculta porque a lista so tem 1 elemento
	
	int userCommand; //Variavel para receber comando do usuario
	int valueToAdd; //Variavel do valor informado pelo usuario a ser adicionado


	do
	{
		printMenu();
		scanf("%d", &userCommand);

		switch(userCommand)
		{
			case 1: 
			{
				printf("Entre com o valor que deseja adicionar: ");
				scanf("%d",&valueToAdd);

				//Se a lista estiver vazia
				if(listHead==listHiddenHead)
				{
					//Criacao do novo no e aponta o next do no oculto para o no criado
					listHead=newNodeAllocation();
					listHead->info=valueToAdd;
					listHiddenHead->next=listHead;
					listTail=listHead;

				}
				//Se existir algum elemento na lista
				else
				{
					listTail=includeInTail(listTail,valueToAdd);
				}

			}
			break;
			case 2: 
			{
				printf("Entre com o valor que deseja adicionar: ");
				scanf("%d",&valueToAdd);

				//Se a lista estiver vazia
				if(listHead==listHiddenHead)
				{
					listHead=newNodeAllocation();
					listHead->info=valueToAdd;
					listHiddenHead->next=listHead;
					listTail=listHead;
				}
				//Se exister elemento na lista
				else
				{
					listHead=includeInHead(listHead, valueToAdd, listTail,listHiddenHead);
				}

			}
			break;
			case 3: 
			{
				if(listHead==listHiddenHead)
				{
					printf("A lista esta vazia!\n");
				}
				else
				{
					printList(listHead);
				}	
				
			}
			break;

			case 4: 
			{
				int elemento;
				printf("\nEntre com o elemento que deseja remover: ");
				scanf("%d", &elemento);

				node *elementAddress;

				elementAddress=getElementAddress(listHead,elemento,listTail);

				if(elementAddress!=NULL)
				{
					//Remocao de chave
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

	}while(userCommand!=0);
		
	printf("Programa Finalizado\n");
	return 0;
}
