#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct linha
{
	char fraseNormal[200];
	char fraseOrdenada[200];
};
struct node
{
	char c;
	struct node *left;
	struct node *right;
};

struct node *raiz; //Variavel global da raiz da ABP
char auxiliarString[200];
int i=0;

struct node *visita_arvore(struct node *ra, struct node *r, char c)
{

	if(r==NULL)
	{
		r=malloc(sizeof(struct node));
		r->left=NULL;
		r->right= NULL;
		r->c=c;

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
		visita_arvore(r, r->left, c);
	}
	else
	{
		visita_arvore(r,r->right, c);
	}
}
void inserir(char c)
{

	if(raiz==NULL)
	{
		raiz = visita_arvore(raiz,raiz,c);
	}
	else
	{
		visita_arvore(raiz,raiz,c);
	}
	
}

void emOrdem(struct node *no)
{
	if(no!=NULL)
	{
		emOrdem(no->left);
		auxiliarString[i]=no->c;
		i++;
		emOrdem(no->right);
	}
}

int main()
{
	FILE *readArchive,*writeArchive; //Ponteiros para arquivo de entrada e de saida
	struct linha *ArrayStructs;
	int j=0;

	/*Abertura do arquivo de entrada*/
	readArchive=fopen("entrada", "r");

	//Fluxo principal: Arquivo de entrada existe no diretorio
	if(readArchive!=NULL)
	{
		char auxiliarCharacter;
		int numberOfStrings=0;
		/*---------------------------------Contando o numero de strings---------------------------------*/	
		while(auxiliarCharacter!=EOF)
		{
			auxiliarCharacter=fgetc(readArchive);
			if(auxiliarCharacter=='\n')
			{
				numberOfStrings++;
			}
		
		}	
		/*--------------------------------------------------------------------------------------------*/

		fclose(readArchive);
		//Instancia do array de structs sendo cada estrutura referente a uma frase
		ArrayStructs=malloc(numberOfStrings*sizeof(struct linha));

		/*----Abrindo o arquivo de entrada novamente para copiar os dados para as structs-------------*/
		readArchive=fopen("entrada", "r");

		int x=0;
		
		while(fgets(auxiliarString,sizeof(auxiliarString),readArchive)!=NULL)
		//while(fscanf(readArchive, "%s\n", auxiliarString)!=EOF)
		{
			strcpy((ArrayStructs[x].fraseNormal), auxiliarString);
			x++;
		}
		fclose(readArchive);
		/*--------------------------------------------------------------------------------------------*/

		/*-----------------------------------Ordenando as frases usando uma ABP-----------------------*/
		for(x=0;x<numberOfStrings;x++)
		{
			//Criando a ABP
			for(j=0;j<strlen(ArrayStructs[x].fraseNormal);j++)
			{
				inserir(ArrayStructs[x].fraseNormal[j]);
			}

			//Preenchendo ordenadamente uma string auxiliar
			emOrdem(raiz);
			int tamanhoFrase;
			tamanhoFrase=strlen(ArrayStructs[x].fraseNormal);
			auxiliarString[tamanhoFrase]='\0';

			//Copiando a string ordenada para a struct referente
			strcpy(ArrayStructs[x].fraseOrdenada,auxiliarString);

			//Renova	ndo a ABP
			raiz=NULL;
			i=0;

		}

		/*--------------------------------------------------------------------------------------------*/

		//Imprimindo structs
		for(x=0;x<numberOfStrings;x++)
		{
			printf("%s ", ArrayStructs[x].fraseOrdenada);
		}

		/*--------------------------Preenchendo o arquivo de saida------------------------------------*/
		writeArchive=fopen("saida", "w");

		for(x=0;x<numberOfStrings;x++)
		{
			fprintf(writeArchive, "%s", ArrayStructs[x].fraseOrdenada);
		}

		//Fechando arquivo de saida
		fclose(writeArchive);

	}
	//Fluxo alternativo: Arquivo de entrada nao existe
	else
	{
		printf("Arquivo nao foi encontrado\n");
	}


	return 0;
}