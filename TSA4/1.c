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
	int linha;
};

typedef struct filme FILME;
struct node
{
	char c;
	int linha;
	struct node *left;
	struct node *right;
};

struct node *raiz; //Variavel global que aponta para a raiz da arvore

int *arrayLinhas;
int i=0;

struct node *visita_arvore(struct node *ra, struct node *r, char c, int linha)
{

	if(r==NULL)
	{
		r=malloc(sizeof(struct node));
		r->left=NULL;
		r->right= NULL;
		r->c=c;
		r->linha=linha;

		if(ra ==NULL)
		{
			return r;
		}
		if(c < ra->c)
		{
			ra->left=r;
		}
		else
		{
			ra->right=r;
		}
		return r;
	}
	if(c < r->c)
	{
		visita_arvore(r, r->left, c, linha);
	}
	else
	{
		visita_arvore(r,r->right, c, linha);
	}
}

void inserir(char c, int linha)
{

	if(raiz==NULL)
	{
		raiz = visita_arvore(raiz,raiz,c, linha);
	}
	else
	{
		visita_arvore(raiz,raiz,c, linha);
	}
	
}

void emOrdem(struct node *no)
{
	if(no!=NULL)
	{
		emOrdem(no->left);
		arrayLinhas[i]=no->linha;
		i++;
		emOrdem(no->right);
	}
}
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

		while( fscanf(readArchive,"%s %s %s %f %s\n", aCode, aTitle, aMidia, &aPrice, aGender) 
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
				arrayFilmes[x].linha=(x+1);
			}
			/*--------------------------------------------------------------------------------*/	
		}
		//Fechamento do arquivo de entrada
		fclose(readArchive);

		//Imprimir array de struct
		/*
		for(x=0;x<numberOfLines;x++)
		{
			printf("#################\n");
			printf("Codigo do filme: %s\n", arrayFilmes[x].codigo );
			printf("Titulo do filme: %s\n", arrayFilmes[x].titulo );
			printf("Tipo de midia: %s\n", arrayFilmes[x].midia );
			printf("Preco: %.2f\n", arrayFilmes[x].preco );
			printf("Genero: %s\n", arrayFilmes[x].genero );
		}
		*/
		
		for(x=0;x<numberOfLines;x++)
		{
			//Criando a ABP
			inserir(arrayFilmes[x].codigo[0],arrayFilmes[x].linha);

			//arrayLinhas=malloc(numberOfLines*sizeof(int));

			emOrdem(raiz); //Ordem das linhas ordenada
		}

		printf("Linhas ordenadas por ordem do codigo: ");
		for(x=0;x<numberOfLines;x++)
		{
			printf("%d ", arrayLinhas[x]);
		}
		printf("\n");



	}
	else
	{
		printf("O arquivo nao foi encontrado no diretorio\n");
	}


	return 0;
}