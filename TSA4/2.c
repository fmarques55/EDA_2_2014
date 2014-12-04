#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme
{
	char codigo[30];
	char titulo[50];
	char midia[20];
	float preco;
	char genero[20];
};

typedef struct filme FILME;
struct node
{
	char codigo[30];
	int linha;
	struct node *left;
	struct node *right;
};

struct node *raiz; //Variavel global que aponta para a raiz da arvore

int main()
{
	FILE *readArchive; //Ponteiros para arquivo de entrada e de saida
	FILME *arrayFilmes;
	int numberOfLines=0;
	char auxiliarCharacter;
	char archiveName[20];

	/*Definicao do nome do arquivo de entrada*/
	printf("Entre com o nome do arquivo de entrada: ");
	scanf("%s", archiveName);

	
	//Abertura do arquivo de entrada
	readArchive=fopen(archiveName, "r");

	//Fluxo principal: O arquivo de entrada existe no diretorio
	if(readArchive!=NULL)
	{	
		/*---------------------------------Contando o numero de dados---------------------------------*/	
		while(auxiliarCharacter!=EOF)
		{
			auxiliarCharacter=fgetc(readArchive);
			if(auxiliarCharacter=='\n')
			{
				numberOfLines++;
			}
		}
		fclose(readArchive);	//Fechamento do arquivo 
		/*--------------------------------------------------------------------------------------------*/
		
		//Criacao de um array de caracteres
		arrayFilmes=malloc(numberOfLines*sizeof(FILME));

		//Reabertura do arquivo de entrada
		readArchive=fopen(archiveName, "r");

		/*Declaracao de variaveis auxiliares para preencher o array de filmes*/
		char aCode[30];
		char aTitle[50];
		char aMidia[20];
		float aPrice;
		char aGender[20];
		int x;
		/*-------------------------------------------------------------------*/


		
		while( fscanf(readArchive,"%s %s %s %f %s\n", aCode ,aTitle, aMidia, &aPrice, aGender) 
		!= EOF )
		{
			/*-------Preenchendo array de vendedores com os dados do arquivo de entrada-------*/
			for(x=0;x<numberOfLines;x++)
			{
				strcpy(arrayFilmes[x].codigo, aCode);
				strcpy(arrayFilmes[x].titulo, aTitle);
				strcpy(arrayFilmes[x].midia, aMidia);
				arrayFilmes[x].preco = aPrice;
				strcpy(arrayFilmes[x].genero, aGender);
			}
			/*--------------------------------------------------------------------------------*/	
		}
		//Fechamento do arquivo de entrada
		fclose(readArchive);

		/*Imprimir array de struct*/
		for(x=0;x<numberOfLines;x++)
		{
			printf("#################\n");
			printf("Codigo do filme: %s\n", arrayFilmes[x].codigo );
			printf("Titulo do filme: %s\n", arrayFilmes[x].titulo );
			printf("Tipo de midia: %s\n", arrayFilmes[x].midia );
			printf("Preco: %.2f\n", arrayFilmes[x].preco );
			printf("Genero: %s\n", arrayFilmes[x].genero );
		}
		
		
		char movieCode[30];

		printf("Entre com o codigo do filme que deseja realizar a busca: ");
		scanf("%s", movieCode);

		for(x=0;x<numberOfLines;x++)
		{
			//Se o codigo informado for encontrado
			if(strcmp(arrayFilmes[x].codigo,movieCode)==0)
			{
				printf("#################\n");
				printf("Codigo do filme: %s\n", arrayFilmes[x].codigo );
				printf("Titulo do filme: %s\n", arrayFilmes[x].titulo );
				printf("Tipo de midia: %s\n", arrayFilmes[x].midia );
				printf("Preco: %.2f\n", arrayFilmes[x].preco );
				printf("Genero: %s\n", arrayFilmes[x].genero );
				break;
			}
			else
			{
				printf("O filme nao foi encontrado\n");
			}
		}
		
	}
	else
	{
		printf("O arquivo nao foi encontrado no diretorio\n");
	}


	return 0;
}