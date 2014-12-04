#include <stdio.h>
#include <stdlib.h>
#include "funcoes_tree.h"

typedef struct node node;

int main()
{

	node *raiz;

	printf("Entre com uma arvore em forma de string: ");
	scanf("%s", string);

	printf("\n\n%s\n\n", string);

	constructTree(raiz);

	printTree(raiz);

	return 0;
}