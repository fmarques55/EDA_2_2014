#include <stdio.h>
#include <stdlib.h>

/*--------------Declaracao da struct---------------------------------------------*/
struct nodeStructure
{
	int codigo;
	char nome[30];
	char telefone[11];
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
	printf("[0] - Finalizar programa\n");
	printf("> ");
}

/*--------------------Funcao para encontrar o endereco de determinado no---------------------------------*/
node *getElementAddress(node *head, node *tail,int informedCode)
{
	node *auxiliarPointer;
	auxiliarPointer=head;

	/*Anda ate o enderco de memoria do elemento informado, caso nao exista o elemento na lista 
	retorna NULL*/
	while(auxiliarPointer!=tail)
	{
		//Se o nome procurado for igual o que estiver no no
		if(informedCode==auxiliarPointer->codigo)
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
		//Se o ultimo no nao for o procurado
		if(auxiliarPointer->codigo!=informedCode)
		{
			//O ponteiro auxiliar deve apontar para nulo, pois o elemento nao existe nao lista
			auxiliarPointer=NULL;			
		}
		//Se o ultimo no for o procurado
		else
		{
			//O ponteiro auxiliar permanece apontando para o endereco do ultimo no
		}

	}

	return auxiliarPointer;
}

void includeContact(node *elementAddress, int informedCode, char *informedName, char *informedPhone)
{
	node *newNode;

	//Criacao do novo no
	newNode=newNodeAllocation();

	//Preenchimento do novo no
	newNode->codigo=informedCode;
	strcpy(newNode->nome,informedName);
	strcpy(newNode->telefone,informedPhone);
	newNode->prev=elementAddress;
	newNode->next=elementAddress->next;

	elementAddress->next=newNode;

}
void removeElementKey(node *head, node *elementToRemoveAddress)
{
	node *auxiliarPointer;
	
	auxiliarPointer=head;

	//Andando ate o elemento anterior ao que sera removido
	while(auxiliarPointer->next!=elementToRemoveAddress)
	{
		auxiliarPointer=auxiliarPointer->next;
	}

	auxiliarPointer->next=elementToRemoveAddress->next;
	node *auxiliarPointer2;
	auxiliarPointer2=elementToRemoveAddress->next;

	auxiliarPointer2->prev=auxiliarPointer;

	free(elementToRemoveAddress);
	elementToRemoveAddress=NULL;

}

void printList(node *head, node *tail)
{
	node *auxiliarPointer;

	auxiliarPointer=head;
	while(auxiliarPointer!=tail)
	{
		//Impressao da struct
		printf("##############################################\n");
		printf("Codigo: %d\n", auxiliarPointer->codigo);
		printf("Nome: %s\n", auxiliarPointer->nome);
		printf("Telefone: %s\n", auxiliarPointer->telefone);
		printf("##############################################\n");

		auxiliarPointer=auxiliarPointer->next;
	}

	//Impressao do ultimo elemento da lista
	printf("##############################################\n");
	printf("Codigo: %d\n", auxiliarPointer->codigo);
	printf("Nome: %s\n", auxiliarPointer->nome);
	printf("Telefone: %s\n", auxiliarPointer->telefone);
	printf("##############################################\n");

	
}
