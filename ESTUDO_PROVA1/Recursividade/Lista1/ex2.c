#include <stdio.h>
#include <stdlib.h>

int searchForCharacter(char *string, char characterToSearch, char *firstCharacterAddress)
{
	
	if(*string=='\0')
	{
		return (-1);
	}
	else
	{
		if(*string==characterToSearch)
		{
			return string-(firstCharacterAddress-1);
		}
		else
		{
			searchForCharacter((string+1),characterToSearch,firstCharacterAddress);
		}
	}
}
int main()
{
	char string[20],characterToSearch;
	int resultado;	
	
	printf("Entre com a string: ");
	scanf("%s", string);

	printf("Entre com o caracter que deseja adicionar");
	__fpurge(stdin);
	scanf("%c", &characterToSearch);

	resultado = searchForCharacter(string, characterToSearch, string);
	
	printf("Posicao do caractere: %d\n\n", resultado);

	return 0;
}
