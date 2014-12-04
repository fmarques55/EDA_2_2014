#include <stdio.h>
#include <stdlib.h>

struct numero
{
	int info;
	struct numero *next;
};

typedef struct numero Numero;

void alterarNumeros(Numero *number)
{
	number->info=10;

}

int main()
{
	Numero *n1,*n2;

	n1=malloc(sizeof(Numero));
	n2=malloc(sizeof(Numero));

	n1->info=1;
	n2->info=55;

	printf("Primeiros valores: %d e %d\n", n1->info, n2->info);

	n1->next=n2;
	n2->next=NULL;

	alterarNumeros(n1);
	
	printf("Valores Novos: %d e %d\n", n1->info, n2->info);

	return 0;
}