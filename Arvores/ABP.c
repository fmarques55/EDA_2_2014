#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *left;
	struct node *right;	
};

struct node *raiz;

void preOrdem(struct node *no)
{
	if(no!=NULL)
	{
		printf("%d - ", no->info);
		preOrdem(no->left);
		preOrdem(no->right);
	}
}

void posOrdem(struct node *no)
{
	if(no!=NULL)
	{
		posOrdem(no->left);
		posOrdem(no->right);
		printf("%d - ", no->info);
	}
}

void emOrdem(struct node *no)
{
	if(no!=NULL)
	{
		emOrdem(no->left);
		printf("%d - ", no->info);
		emOrdem(no->right);
	}
}
/*Metodo que funciona corretamente*/
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
/* METODO DANDO FALHA DE SEGMENTACAO
struct node *visita_arvore(struct node *ra, struct node *r, int valor)
{
	if(r==NULL)
	{
		r=malloc(sizeof(struct node));
		
		r->left=NULL;
		r->right=NULL;
		r->info=valor;
		
		if(ra==NULL)
		{
			return r;
		}
		if(valor< ra->info)
		{
			ra->left=r;
		}
		else
		{
			ra->right=r;
		}
	}
	if(valor< ra->info)
	{
		visita_arvore(r,r->left,valor);
	}
	else
	{
		visita_arvore(r,r->right,valor);
	}
}*/
void inserir()
{
	int valor;

	printf("Entre com o valor que deseja adicionar: ");
	scanf("%d", &valor);

	if(raiz==NULL)
	{
		raiz = visita_arvore(raiz,raiz,valor);
	}
	else
	{
		visita_arvore(raiz,raiz,valor);
	}
	
}
int main()
{

	char comando;
	
	do
	{
		printf("Entre com uma opcao: \n");
		printf("[A] - Adicionar\n");
		printf("[I] - Apresentar a arvore\n");
		printf("[*] - Sair\n");
		printf("> ");
		scanf("%c", &comando);
	if(comando=='A' || comando=='a')
	{
		inserir();
	}
	if(comando=='I' || comando=='i')
	{
		emOrdem(raiz);
	}

	}
	while(comando!='*');

	printf("\nPROGRAMA FINALIZADO!\n");

}	
