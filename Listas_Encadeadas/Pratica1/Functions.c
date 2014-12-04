#include <stdio.h>

/*Funcao para incluir no final da lista
Parametros:
head: endereco da cabeca da lista
infoToInclude: inteiro que sera incluido no novo no*/
void includeInTail(struct nodeStructure *head, int infoToInclude)
{
	struct nodeStructure *auxiliarPointer;

	auxiliarPointer=head;

	//Andando ate o ultimo no da lista
	while(auxiliarPointer->next!=NULL)
	{
		auxiliarPointer=auxiliarPointer->next;	
	}

	struct nodeStructure *newNode; //Ponteiro para o novo no
	newNode=newNodeAllocation();

	auxiliarPointer->next=newNode;

	//Prenchendo o ultimo no
	newNode->info=infoToInclude;
	newNode->next=NULL;
			
	
}
/*Funcao para incluir no inicio da lista, tem como retorno o novo endereco da cabeca
Parametros:
head: endereco da cabeca da lista
infoToInclude: inteiro que sera adicionado no novo no
*/
struct nodeStructure *includeInHead(struct nodeStructure *head, int infoToInclude)
{
	struct nodeStructure *auxiliarPointer;

	auxiliarPointer=head;

	struct nodeStructure *newNode;

	newNode=newNodeAllocation();

	//Preenchimento do novo no
	newNode->next=auxiliarPointer;
	newNode->info=infoToInclude;

	head=newNode;

	return head;
}

//Funcao atomica para alocacao de memoria de um novo no para a lista
node newNodeAllocation()
{
	return malloc(sizeof(struct nodeStructure)); 
}

void printMenu()
{
	printf("Entre com uma das opcoes abaixo:\n");
	printf("[1] - Adicionar elemento no inicio da lista\n");
	printf("[2] - Adicionar elemento no final da lista\n");
	//printf("[3] - Remover elemento da lista\n", );
	printf("[0] - Finalizar o programa\n");	
	printf("> ");
}