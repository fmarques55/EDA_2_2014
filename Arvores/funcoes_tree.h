#include <stdlib.h>
#include <stdio.h>

/*Global variables*/
char string[30];
int i=0;
/*---------------*/

struct node
{
	char info;
	struct node *left;
	struct node *right;
};

typedef struct node node;

char getNextChar()
{
	char nextChar;

	nextChar=string[i];
	i++;

	return nextChar;
}

node *newNodeAllocation()
{
	node *newNode;

	newNode= malloc(sizeof(node));

	return newNode;
}

void constructTree(node *No)
{
	char info;

	info = getNextChar();
	if(info!='\0')
	{
		if(info !='.')
		{
			No = newNodeAllocation();
			No->info = info;
			constructTree(No->left);
			constructTree(No->right);
		}
		else
		{
			No=NULL;
		}
	}
	else
	{
		//Parar construcao da arvore
	}
}

void printTree(node *No)
{
	if(No != NULL)
	{
		printf("%c ", No->info);
		printTree(No->left);
		printTree(No->right);

	}
}
