#include <stdio.h>
#include <stdlib.h>

/*--------------Declaracao da struct---------------------------------------------*/
struct nodeStructure
{
	int codigo;
	char nome[30];
	struct nodeStructure *prev;
	struct nodeStructure *next;
};
/*-------------------------------------------------------------------------------*/

//Definicao do tipo node
typedef struct nodeStructure node;

/*--------------------------Funcao atomica para criacao de novo no---------------*/

node *newNodeAllocation()
{
	node *newNode;

	newNode= malloc(sizeof(node));

	return newNode;
}

/*-------------------------------------------------------------------------------*/

void printMenu()
{
	printf("Entre com uma das opcoes abaixo:\n");
	printf("[1] - Incluir contato\n");
	printf("[2] - Excluir contato\n");
	printf("[3] - Listar contatos\n");
	printf("[0 - Finalizar programa\n");
	printf("> ");
}

/*--------------------Funcao para encontrar o endereco de determinado no---------------------------------*/
node *getElementAddress(node *head, char *nomeProcurado, node *tail)
{
	node *auxiliarPointer;
	auxiliarPointer=head;

	/*Anda ate o enderco de memoria do elemento informado, caso nao exista o elemento na lista 
	retorna NULL*/
	while(auxiliarPointer!=tail)
	{
		//Se o nome procurado for igual o que estiver no no
		if(strcmp(auxiliarPointer->nome,nomeProcurado)==0)
		{
			break;
		}
		//O nome procurado e diferente do que esta no no
		else
		{
			auxiliarPointer=auxiliarPointer->next;
		}

	}

	if(auxiliarPointer==tail)
	{
		if(strcmp(auxiliarPointer->nome,nomeProcurado)!=0)
		{
			//O ponteiro auxiliar deve apontar para nulo, pois o elemento nao existe nao lista
			auxiliarPointer=NULL;			
		}
		else
		{
			//O ponteiro auxiliar permanece apontando para o endereco do ultimo no
		}

	}

	return auxiliarPointer;
}

void *includeContact(node *elementAddress, int informedCode, char *informedName)
{
	node *newNode;

	//Criacao do novo no
	newNode=newNodeAllocation();

	//Preenchimento do novo no
	newNode->codigo=informedCode;
	strcpy(newNode->nome,informedName);
	newNode->prev=elementAddress;
	newNode->next=elementAddress->next;

}