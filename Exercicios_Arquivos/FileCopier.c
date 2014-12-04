#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *readArchive,*writeArchive;
	char character;

	readArchive = fopen("texto", "r");
	writeArchive = fopen("saida.txt", "w");

	if(readArchive==NULL)
	{
		printf("O arquivo nao foi aberto!\n");
	}
	else
	{
		printf("Arquivo aberto com sucesso!\n");
		do
		{
			character= fgetc(readArchive);
			if(character==EOF)
			{
				break;
			}
			fputc(character,writeArchive);
			
		}while(character!=EOF);
	
			fclose(readArchive);
			fclose(writeArchive);
	}
	return 0;
	
}
