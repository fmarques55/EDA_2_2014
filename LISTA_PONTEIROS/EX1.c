#include <stdio.h>
#include <stdlib.h>

void impressaoValores(int *p)
{
	printf("Endereco de Memoria: %p \n", p);
	printf("Conteudo dentro da variavel que esta sendo apontada: %d\n\n\n\n", *p);
}
int main()
{
	/*Inicializacao das variaveis*/
	int *p,inteiro;

	//Colocando valores iniciais nas variaveis
	inteiro=10;
	p=&inteiro;

	printf("%d", *p);
	
	/*Em p++ temos o incremento do endereco, ou seja o ponteiro passa a apontar para a posicao de memoria imediatamente
	superior*/
	p++;
	impressaoValores(p);
	
	//Colocando valores iniciais nas variaveis
	inteiro=10;
	p=&inteiro;
	
	/*Em (*p)++ o que incrementa e o conteudo apontado por p*/
	(*p)++;
	impressaoValores(p);
	
	//Colocando valores iniciais nas variaveis
	inteiro=10;
	p=&inteiro;

	/*Em *(p++) o ponteiro p recebe o incremento e acessa o valor da proxima posicao*/
	*(p++);
	impressaoValores(p);
	
	return 0;


}
	
	
