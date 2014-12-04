#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <funcoes_abp.h>

struct node
{
	char c;
	struct node *left;
	struct node *right;
};

//Variavel global para a raiz
struct node *raiz=NULL;

char stringAuxiliar[20];
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
		stringAuxiliar[i]=no->c;
		i++;
		//printf("%d - ", no->info);
		emOrdem(no->right);
	}
}

int main()
{
	char string[20];
	int x;

	printf("Entre com uma string: ");
	gets(string);

	printf("String informada: %s\n", string);
	/*Criando a arvore com os caracteres da string*/
	for(x=0;x<strlen(string);x++)
	{
		inserir(string[x]);
	}
	/*inserir(string[0]);
	printf("Primeiro caracter add: %c\n", raiz->c);

	inserir(string[1]);
	printf("Segundo caracter add: %c\n", raiz->left->c);*/

	emOrdem(raiz);
	stringAuxiliar[strlen(string)]='\0';
	printf("Caracteres ordenados: %s\n", stringAuxiliar);

	
	return 0;
}