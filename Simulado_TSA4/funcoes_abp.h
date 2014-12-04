#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linha *visita_arvore(struct linha *ra, struct node *r, char c)
{

	if(r==NULL)
	{
		r=malloc(sizeof(struct linha));
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
void emOrdem(struct linha *no)
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