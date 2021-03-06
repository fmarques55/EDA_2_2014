#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*FELIPE SAMPAIO MARQUES SOUZA
MATRICULA: 12/0044934
*/

void inverter(char str[], int indice, int tamanho)
{
	char tmp;

	tmp = str[indice];
	str[indice] = str[tamanho - indice];
	str[tamanho - indice] = tmp;
	
	if(indice == tamanho/2)
	{
		return;
	}
	else
	{
		inverter(str, indice+1, tamanho);
	}
}

int verifStringsIguais(char *string1, char *string2)
{
	
	if(*string1=='\0' && *string2=='\0')
	{
		return 1;
	}
	else
	{
		if(*string1==*string2)
		{
			verifStringsIguais((string1+1),(string2+1));
		
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	char palavra1[100],palavraInvertida[100];
	int tamanho;

	printf("Entre com uma palavra:");
	scanf("%s", palavra1);

	tamanho=strlen(palavra1);

	strcpy(palavraInvertida,palavra1);

	inverter(palavraInvertida, 0, tamanho-1);
	
	if(verifStringsIguais(palavra1,palavraInvertida)==1)
	{
		printf("%s e um palindromo\n", palavra1);
	}
	else
	{
		printf("%s nao e um palindromo\n", palavra1);
	}
	
	return 0;
	
}
