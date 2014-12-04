#include <stdio.h>
#include <stdlib.h>

int calculateMDC(int n1, int n2)
{
	if(n2==0)
	{
		return n1;
	}
	else
	{
		return calculateMDC(n2,n1%n2);
	}
}
int main()
{
	int number1,number2,result;

	scanf("%d %d", &number1, &number2);
	
	result = calculateMDC(number1,number2);
		
	printf("(%d,%d) = %d\n",number1,number2,result);

	return 0;
}
