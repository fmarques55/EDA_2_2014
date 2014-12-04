#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char palavra[500];
	
	printf("Entre com uma palavra: ");
	scanf("%s", palavra);

	printf("A primeira letra da palavra: %c\n", palavra[0]);
	printf("A ultima letra da palavra: %c\n", palavra[strlen(palavra)-1]);
	printf("A palavra tem %d letras\n", strlen(palavra));
	
	
	return 0;
}
