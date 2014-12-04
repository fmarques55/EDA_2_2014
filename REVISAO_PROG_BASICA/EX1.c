#include <stdio.h>
#include <stdlib.h>

float transformarParaCelsius(float fahrenheit)
{
	float celsius;

	celsius=((fahrenheit-32)*5)/9;
			
	return celsius;
}


int main()
{
	float celsius,fahrenheit;
	
	printf("Entre com a temperatura");
	scanf("%f", &fahrenheit);

	celsius=transformarParaCelsius(fahrenheit);
	
	printf("A temperatura informada em Celsius: %.2f graus\n", celsius);

	
	
} 
