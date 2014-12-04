#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void includeCharacter(char characterToInclude, char *string)
{
	int i;
	char ch;

	// Andar ate o '\0'
	i=0;
	ch=string[i];
	while(ch!='\0')
	{
		i++;
		ch=string[i];
	}
	
	// Substituir o valor do '\0' pelo caracter a ser incluido
	
	string[i]=characterToInclude;
	string[i+1]='\0';
	
}

void excludeCharacter(char characterToExclude, char *string)
{
	int i;
	char ch;

	
	//Andar ate o caracter desejado
	i=0;
	ch=string[i];
	while(ch!=characterToExclude)
	{
		i++;
		ch=string[i]
	}
	
	while(string[i+1]!='\0')
	{
		string[i]=string[i+1];
		i++;
	}
	string[i]='\0';
}
