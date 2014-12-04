#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_ex2.h"

typedef struct cliente Cliente;

int main()
{
	Cliente *inicioFila;

	inicioFila=alocarNovoCliente();

	Cliente *primeiroFila;
	primeiroFila=inicioFila;

	Cliente *finalFila;
	finalFila=inicioFila;

	int comando; //Variavel para o comando do usuario
	char senhaNovoCliente[6];
	char tipoAtendimentoNovoCliente;

	do
	{
		printMenu();
		__fpurge(stdin);
		scanf("%d", &comando);

		switch(comando)
		{
			case 1: //Enfileirar novo cliente
			{

				printf("Entre com a senha do cliente: ");
				scanf("%s", senhaNovoCliente);
				__fpurge(stdin); //Comando Linux para limpar buffer 
				printf("Entre com o tipo de atendimento 'P' (Pagamento)\t 'S' (Saque) \t'D'  (Deposito): ");
				scanf("%c", &tipoAtendimentoNovoCliente);

				//Se a fila tiver vazia
				if(primeiroFila==inicioFila)
				{
					Cliente *novoCliente;

					//Preenchendo
					strcpy(novoCliente->senha,senhaNovoCliente);
					novoCliente->tipoAtendimento=tipoAtendimentoNovoCliente;
					novoCliente->next=inicioFila;

					inicioFila->next=novoCliente;
					primeiroFila=novoCliente;
					finalFila=novoCliente;
				}
				//Se existir cliente na fila
				else
				{
					finalFila=enfileirarCliente(inicioFila,finalFila,senhaNovoCliente,tipoAtendimentoNovoCliente);
				}
				

			}
			break;

			case 2: //Desinfileirar
			{
				if(inicioFila!=finalFila)
				{


				//Pegar informacao do primeiro da fila
				printf("\nSenha do cliente: %s\n", primeiroFila->senha);
				printf("Tipo de atendimento: %c\n", primeiroFila->tipoAtendimento);
				
				//Andar a fila
				inicioFila->next=primeiroFila->next;
				primeiroFila=inicioFila->next;
				}
				else
				{
					printf("A fila esta vazia\n");
				}
			}
			break;

			case 3: //Esvaziar Fila
			{
				inicioFila->next=NULL;

				primeiroFila=inicioFila;
				finalFila=inicioFila;

			}
			break;
		}
	}while(comando!=0);

	return 0;

}