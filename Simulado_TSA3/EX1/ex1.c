#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_ex1.h"

//Definicao do tipo node
typedef struct nodeStructure node;


int main()
{
	node *listHiddenHead; //Cabeca oculta da lista (apenas para a lista nunca ficar realmente vazia)
	listHiddenHead=newNodeAllocation();

	node *listHead; //Cabeca da lista
	listHead=listHiddenHead; //Lista inicia vazia, entao a cabeca aponta para a oculta

	int comando; //Variavel do comando do usuario
	int userInformedCode;
	char userInformedContactName[30]; //Variavel com nome informado pelo usuario

	do
	{

		printMenu();
		scanf("%d", &comando);

		switch(comando)
		{
			case 1: //Incluir contato
			{
				//Se a lista tiver vazia
				if(listHead==listHiddenHead)
				{
					node *newNode;

					newNode=newNodeAllocation();

					printf("Entre com o codigo do contato: ");
					scanf("%d", &userInformedCode);
					printf("Entre com o nome do contato: ");
					scanf("%s", userInformedContactName);

					//Preenchimento do novo no
					newNode->codigo=userInformedCode;
					strcpy(newNode->nome,userInformedContactName);
					newNode->prev=listHiddenHead;
					newNode->next=listHiddenHead;

					listHiddenHead->next=newNode;
					listHead=newNode;

				}
				//Se existir elemento na lista
				else
				{
					node *elementAddress;

					printf("Deseja adicionar depois de qual codigo? ");
					scanf("%d", &userInformedCode);

					elementAddress=getElementAddress(listHead);

					//O elemento informado existe na lista
					if(elementAddress!=NULL)
					{
						includeContact(elementAddress,userInformedCode,userInformedContactName);
						listHead=listHiddenHead->next;
					}
					else
					{
						printf("Codigo do contato nao existe na lista\n");
					}
				}
			}	

			case 2: //Excluir contato
			{
				
			}

		}
	}while(comando!=0);

	return 0;
}