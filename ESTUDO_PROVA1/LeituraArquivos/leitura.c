#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *readArchive;
	int valor1,valor2;

	readArchive = fopen("popov", "r");
	
	while(fscanf(readArchive, "%d %d\n", &valor1, &valor2)!=EOF)
	{
		printf("%d - %d\n", valor1, valor2);
	}
	
	fclose(readArchive);
		
}
