#include <stdio.h>
#include <stdlib.h>

int transformToCelsius(float fahrenheit)
{
	float celsius;
	
	celsius = fahrenheit - 32;
	celsius = 5*celsius;
	celsius = celsius/9;

	return celsius;
}

int main()
{
	float fahrenheit, celsius;
	
	printf("Entre com a temperatura em graus fahrenheit: ");
	scanf("%f", &fahrenheit);

	celsius = transformToCelsius(fahrenheit);

	printf("Temperatura informada em celsius: %.1f\n", celsius);

	return 0;	
}

