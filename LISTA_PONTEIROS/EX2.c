#include <stdio.h>
#include <stdlib.h>

int main()
{
	int y,*p,x;
	
	//Atribuicao do valor 0 a variavel y
	y=0;
	//p recebe o endereco da variavel y
	p=&y;
	//x recebe o conteudo da variavel que e apontada por p (logo x = y)
	x = *p;
	//x recebe o valor 4
	x=4;
	//o conteudo da variavel apontada por p recebe um incremento (logo y = 1)
	(*p)++;
	//x recebe um decremento
	x--;
	//a variavel apontado por p recebe x+1 (logo y que era 1 recebe 3+1=4)
	(*p) += x;
	
	printf("y= %d\n",y);
	return 0;
}
