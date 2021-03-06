#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesProg2.h"

void printMenu()
{
	printf("Escolha uma opcao: \n");
	printf("[1] - Adicionar caracter\n");
	printf("[2] - Remover caracter\n");
	printf("[3] - Imprimir String\n");
	printf("[0] - Finalizar Aplicacao\n");
	printf("> ");
}

int main()
{
	char characterArray[50];
	char userCommand,userInformedChar;
	int i;


	puts(characterArray);
	do
	{
		printMenu();
		__fpurge(stdin);
		scanf("%c", &userCommand);
		
		switch(userCommand)
		{
			case '1': 
				printf("Entre com o caracter que deseja adicionar: ");
				__fpurge(stdin);				
				scanf("%c", &userInformedChar);
				AddCharacterToString(userInformedChar, characterArray);

			break;
			
			case '2': 
				printf("Entre com o caracter que deseja remover: ");
				__fpurge(stdin);
				scanf("%c", &userInformedChar);
				DeleteCharactersInString(userInformedChar, characterArray);
			
			break;
			
			case '3': 
				
				for(i=0;i<strlen(characterArray);i++)
				{
					printf("%c", characterArray[i]);
				}

			
			break;
		}
	}
	while(userCommand != '0');
	

	return 0;
		
}
