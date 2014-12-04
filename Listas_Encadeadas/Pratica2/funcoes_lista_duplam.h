#include <stdlib.h>

/*-------------------------Estrutura do no da lista duplamente encadeada-----------------------------*/
struct nodeStructure
{
	int info; //Variavel do valor
	struct nodeStructure *prev; //Ponteiro para o anterior
	struct nodeStructure *next; //Ponteiro para o proximo
};
/*-----------------------------------------------------------------------------------------------------*/

//Definicao do tipo node
typedef struct nodeStructure node;

/*---------------------------Funcao atomica para alocacao de memoria-----------------------------------*/
node *newNodeAllocation()
{
	return malloc(sizeof(node)); 
}
/*-----------------------------------------------------------------------------------------------------*/

/*--------------------------------------Funcao de inclusao no final da lista---------------------------*/
node *includeInTail(node *tail, int infoToInclude)
{

	node *auxiliarPointer,*newNode;

	auxiliarPointer=tail;

	//Criacao e preenchimento do novo no
	newNode=newNodeAllocation();
	newNode->info=infoToInclude;
	newNode->prev=auxiliarPointer;
	newNode->next=NULL;

	auxiliarPointer->next=newNode;
	tail=newNode;

	//Retorno para atualizar o endereco da cauda
	return tail;
				
}

/*-----------------------------------------------------------------------------------------------------*/

/*----------Funcao para incluir no inicio da lista, tem como retorno o novo endereco da cabeca---------*/
node *includeInHead(node *head, int infoToInclude, node *tail, node *hiddenHead)
{
	node *newNode;

	newNode=newNodeAllocation();

	//Preenchimento do novo no
	newNode->next=head;
	newNode->prev=hiddenHead;
	newNode->info=infoToInclude;

	//O next da cabeca oculta apontando para o novo no criado
	hiddenHead->next=newNode;

	//Apontando a cabeca para o novo no criado 
	head=newNode;


	//Retorno para atualizar a cabeca da lista na main
	return head;
}

/*------------------------Funcao para impressao do menu -----------------------------------------------*/
void printMenu()
{
	printf("Entre com uma das opcoes abaixo:\n");
	printf("[1] - Adicionar elemento no final da lista\n");
	printf("[2] - Adicionar elemento no inicio da lista\n");
	printf("[3] - Imprimir lista\n" );
	printf("[4] - Remover elemento da lista\n");
	printf("[0] - Finalizar o programa\n");	
	printf("> ");
}
/*-----------------------------------------------------------------------------------------------------*/

/*------------------------------Funcao para impressao dos elementos da lista encadeada-----------------*/
void printList(node *head)
{
	node *auxiliarPointer;

	auxiliarPointer=head;
	
	while(auxiliarPointer->next!=NULL)
	{
		printf("%d ", auxiliarPointer->info);

		//Caminha para o proximo no
		auxiliarPointer=auxiliarPointer->next;	
	}

	//Impressao do ultimo valor da lista
	printf("%d\n\n", auxiliarPointer->info);
}
/*-----------------------------------------------------------------------------------------------------*/

/*--------------------Funcao para procurar um elemento e retornar sua posicao na lista-----------------*/
int searchElement(node *head, int element, int listSize)
{
	node *auxiliarPointer;
	int counter=1;

	auxiliarPointer=head;

	while(auxiliarPointer->next!=NULL)
	{
		if(auxiliarPointer->info==element)
		{
			break;
		}
		else
		{
			counter++;
			auxiliarPointer=auxiliarPointer->next;
		}

	}

	//Verificacao do valor do contador 
	if(counter>listSize)
	{
		counter = 0;
	}
	else
	{
		//Contador permanece o valor
	}
	return counter;
}
/*--------------------Funcao para encontrar o endereco de determinado no---------------------------------*/
node *getElementAddress(node *head, int element, node *tail)
{
	node *auxiliarPointer;
	auxiliarPointer=head;

	/*Anda ate o enderco de memoria do elemento informado, caso nao exista o elemento na lista 
	retorna NULL*/
	while(auxiliarPointer->next!=NULL)
	{
		if(auxiliarPointer->info==element)
		{
			break;
		}
		else
		{
			auxiliarPointer=auxiliarPointer->next;
		}

	}

	if(auxiliarPointer==tail)
	{
		if(auxiliarPointer->info!=element)
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
/*-----------------------------------------------------------------------------------------------------*/

/*-------------------Funcao para remover elemento no meio da lista-------------------------------------*/
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

/*-----------------------------------------------------------------------------------------------------*/

