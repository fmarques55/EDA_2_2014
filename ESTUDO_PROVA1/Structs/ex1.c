#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
    int codigo;
    char nome[30];
    int idade;
    float altura;
}contact;

void imprimeMenu()
{
    printf("Entre com uma opcao abaixo:\n");
    printf("[1] - Incluir contato\n");
    printf("[2] - Excluir contato\n");
    printf("[3] - Alterar contato\n");
    printf("[4] - Imprimir contatos\n");
    printf("[0] - Sair\n");
}
int main()
{
    contact CONTATOS[3];
    int comando,idade,codigo,i;
    char nome[30];
    float altura;


	for(i=0;i<3;i++)
	{
		CONTATOS[i].codigo=0;
	}

    do
    {
        imprimeMenu();
        printf("> ");
	__fpurge(stdin);
        scanf("%d", &comando);

        switch(comando)
        {
            case 1:
            {

                for(i=0;i<3;i++)
                {
                    if(CONTATOS[i].codigo==0)
                    {
                        codigo = i;
                        printf("Entre com o nome do contato: ");
			__fpurge(stdin);
                        scanf("%s", nome);
                        printf("Entre com a idade do contato: ");
			__fpurge(stdin);
                        scanf("%d", &idade);
                        printf("Entre com a altura do contato: ");
			__fpurge(stdin);
                        scanf("%f", &altura);
                        CONTATOS[i].codigo=codigo;
                        strcpy(CONTATOS[i].nome,nome);
                        CONTATOS[i].idade=idade;
                        CONTATOS[i].altura=altura;
                    }
                    else
                    {
                        //Fazer nada
                    }

                }
            }
		break;
            case 2:
            {
                printf("Entre com o codigo do contato que deseja excluir: ");
                scanf("%d", &codigo);
                for(i=0;i<3;i++)
                {
                    	if(codigo==i)
                    	{
                        	CONTATOS[i].codigo=0;
                        	strcpy(CONTATOS[i].nome,"");
                        	CONTATOS[i].idade=0;
                        	CONTATOS[i].altura=0;
                    	}
			else
			{
				//Fazer Nada
			}
                }
		printf("Contato excluido!\n");
            }
	    break;
            case 3:
            {
                printf("Entre com o codigo do contato que deseja alterar:");
                scanf("%d", &codigo);

                for(i=0;i<3;i++)
                {
                    if(codigo==CONTATOS[i].codigo)
                    {
                        printf("Entre com o nome: ");
                        scanf("%s", nome);
                        printf("Entre com a idade: ");
                        scanf("%d", &idade);
                        printf("Entre com a altura: ");
                        scanf("%f", &altura);

                    }
                }
            }
	    break;
            case 4:
            {
                for(i=0;i<3;i++)
                {
                    printf("Codigo: %d \t Nome: %s \t Idade: %d \t Altura: %.2f \n",CONTATOS[i].codigo,
                    CONTATOS[i].nome, CONTATOS[i].idade, CONTATOS[i].altura);
                    printf("##################################################\n");
                }
            }
        }
    }while(comando!=0);

    return 0;
}
