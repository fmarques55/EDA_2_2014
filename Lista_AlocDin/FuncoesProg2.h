#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddCharacterToString(char c, char *string)
{
	int i;	
	
	for(i=0;i<strlen(string);i++)
	{
		
		if(string[i]=='\0')
		{
			string[i]=c;
			string[i+1]='\0';
		}
		else
		{
			//Just go to the next character
		}
	}
	
}

void DeleteCharactersInString(char c,char *string)
{
	int i;
	
	for(i=0;i<strlen(string);i++)
	{
		if(string[i]==c)
		{
			string[i]='0';
		}
		else
		{
			//Justo go to the next character
		}
	}
}

