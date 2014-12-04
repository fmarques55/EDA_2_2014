#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int exponential(int e)
{
	if(e==1)
	{
		return 2;
	}
	else
	{
		return 2*exponential(e-1);
	}
}

int main()
{
	
	//Declaracao das variaveis
	int exponent,result;
		

	printf("Entre com o valor que deseja elevar o numero 2: ");
	scanf("%d", &exponent);

	result = exponential(exponent);
	
	printf("2^%d = %d\n", exponent, result);

	return 0;
}
