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

	node *listTail;
	listTail=listHiddenHead;

	int comando; //Variavel do comando do usuario
	int userInformedCode;
	char userInformedContactName[30]; //Variavel com nome informado pelo usuario
	char userInformedPhone[11]; //Variavel com o telefone informado pelo usuario

	do
	{

		printMenu();
		scanf("%d", &comando);

		switch(comando)
		{
			case 1: //Incluir contato
			{
				printf("Entre com o codigo do contato: ");
				scanf("%d", &userInformedCode);
				printf("Entre com o nome do contato: ");
				__fpurge(stdin);//Comando para limpar buffer do linux
				scanf("%s", userInformedContactName);
				printf("Entre com o telefone do contato: ");
				__fpurge(stdin);//Comando para limpar buffer do linux
				scanf("%s", userInformedPhone);

				//Se a lista tiver vazia
				if(listHead==listHiddenHead)
				{
					node *newNode;

					newNode=newNodeAllocation();

					//Preenchimento do novo no
					newNode->codigo=userInformedCode;
					strcpy(newNode->nome,userInformedContactName);
					strcpy(newNode->telefone,userInformedPhone);
					newNode->prev=listHiddenHead;
					newNode->next=listHiddenHead;

					listHiddenHead->next=newNode;
					listHead=newNode;
					listTail=newNode;


				}
				//Se existir elemento na lista
				else
				{
					node *elementAddress;
					int aposCodigo;

					printf("Apos qual codigo do contato deseja inserir? ");
					scanf("%d", &aposCodigo);

					if(listHead!=listTail)
					{
						

						elementAddress=getElementAddress(listHead,listTail,aposCodigo);

						//O elemento informado existe na lista
						if(elementAddress!=NULL)
						{
							includeContact(elementAddress,userInformedCode,userInformedContactName,
								userInformedPhone);
							
							listHead=listHiddenHead->next;
						}
						else
						{
							printf("Codigo do contato nao existe na lista\n");
						}
					}
					else
					{
						node *novoNo;

						novoNo=newNodeAllocation();

						//Preenchimento do novo no
						novoNo->codigo=userInformedCode;
						strcpy(novoNo->nome,userInformedContactName);
						strcpy(novoNo->telefone,userInformedPhone);
						novoNo->next=listHiddenHead;
						novoNo->prev=elementAddress;

						elementAddress->next=novoNo;


					}
				}
			}	
			break;
			case 2: //Excluir contato
			{
				printf("Entre com o codigo do contato que deseja remover: \n");
				scanf("%d", &userInformedCode);

				node *elementAddress;
				if(elementAddress==listHead)
				{

				}

			}
			break;

			case 3: //Imprimir a lista
			{
				printList(listHead,listTail);
			}

		}
	}while(comando!=0);

	return 0;
}