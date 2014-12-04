#include <stdio.h>
#include <stdlib.h>

int sum(int lastTherm)
{
	if(lastTherm==1)
	{
		return 1;
	}
	else
	{
		return lastTherm+sum(lastTherm-1);
	}

}

int main()
{
	int lastSeriesTherm,result;

	printf("Entre com o numero: ");
	scanf("%d", &lastSeriesTherm);
	
	result = sum(lastSeriesTherm);
	printf("Resultado do somatorio: %d\n", result );
	
	return 0;

	
}
