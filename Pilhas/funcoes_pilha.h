#include <stdio.h>
#include <stdlib.h>

struct nodeStructure
{
	int info;
	struct nodeStructure *next;
};

typedef struct nodeStructure node;

node *newElementAllocation()
{
	node *newNode;

	newNode=malloc(sizeof(node));

	return newNode;
}

node *empilha(node *pilha, int element, node *hiddenHead)
{
	node *newNode;

	newNode=newElementAllocation();

	if(pilha!=hiddenHead)
	{
		//Preenchimento do novo elemento
		newNode->info=element;
		newNode->next=pilha;
	}	
	else
	{
		//Preenchimento do novo elemento
		newNode->info=element;
		newNode->next=NULL;
	}

	hiddenHead->next=newNode;
	//Retorno do novo 
	return newNode;

}

node *desempilha(node *pilha, node *hiddenHead)
{
	hiddenHead->next=pilha->next;
	return pilha;
}
	
