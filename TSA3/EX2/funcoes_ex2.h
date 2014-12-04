#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente
{
	char senha[6];
	char tipoAtendimento;
	struct cliente *next;
};

typedef struct cliente Cliente;

Cliente *alocarNovoCliente()
{
	Cliente *novoCliente;

	novoCliente=malloc(sizeof(Cliente));

	return novoCliente;
}

void printMenu()
{
	printf("Entre com uma das opcoes abaixo:\n");
	printf("[1] - Enfileirar novo cliente\n");
	printf("[2] - Desinfileirar\n");
	printf("[3] - Esvaziar fila\n");
	printf("[0] - Finalizar Programa\n");
	printf("> ");
}

/*--------------------------------------Funcao de inclusao no final da lista---------------------------*/
Cliente *enfileirarCliente(Cliente *inicioFila,Cliente *finalFila, char *senha, char tipoAtendimento)
{

	Cliente *auxiliarPointer,*newNode;	

	auxiliarPointer=finalFila;

	//Criacao e preenchimento do novo no
	newNode=alocarNovoCliente();
	//strcpy(senha,newNode->senha);
	strcpy(newNode->senha,senha);
	newNode->tipoAtendimento=tipoAtendimento;
	newNode->next=inicioFila;

	auxiliarPointer->next=newNode;
	finalFila=newNode;

	//Retorno para atualizar o endereco da cauda
	return finalFila;
				
}

/*-----------------------------------------------------------------------------------------------------*/