#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------------------*/
struct vendedor
{
	unsigned int codigo;
	float salarioBase;
	float vendas;
	float comissao;
	float salarioFinal;	
};
/*--------------------------------------------------------------------------------------------------------*/

int main()
{
	/*---------------------------------Declaracao das Variaveis---------------------------------------*/
	FILE *readArchive;
	FILE *writeArchive;
	char readArchiveName[50],ch;
	int codigoFuncionario;
	float salarioBaseFuncionario,vendasFuncionario,mediaDeVendas;
	int i,numFuncionarios=0;
	struct vendedor *ARRAY_DE_FUNCIONARIOS;
	struct vendedor STRUCT_DE_COPIA;
	/*-----------------------------------------------------------------------------------------------*/

	printf("Entre com o nome do arquivo que deseja fazer leitura.\n");
	scanf("%s", readArchiveName);

	//Abertura do arquivo de entrada
	readArchive = fopen("MovimentoVendas", "r");

	if(readArchive==NULL)
	{
		printf("O arquivo nao foi aberto!\n");
	}
	else
	{
		printf("Arquivo aberto com sucesso!");

		/*------------------------Leitura do numero de funcionarios------------------------------*/
			while( (ch=fgetc(readArchive))!= EOF )
			{
				if(ch == '\n')
				{
					numFuncionarios++;
				}
			}
		/*---------------------------------------------------------------------------------------*/



		//Instancia do array de vendedores por alocacao dinamica de memoria
		malloc( numFuncionarios*sizeof(struct vendedor) );
		

		while( fscanf(readArchive,"%d %f %f\n", codigoFuncionario, salarioBaseFuncionario, vendasFuncionario) 
		!= EOF )
		{
			/*-------Preenchendo array de vendedores com os dados do arquivo de entrada-------*/
			for(i=0;i<numFuncionarios;i++)
			{
				ARRAY_DE_FUNCIONARIOS[i].codigo = codigoFuncionario;
				ARRAY_DE_FUNCIONARIOS[i].salarioBase = salarioBaseFuncionario;
				ARRAY_DE_FUNCIONARIOS[i].vendas = vendasFuncionario;
			}
			/*--------------------------------------------------------------------------------*/	
		}
		
		//Determinacao da media das vendas
		for(i=0;i<numFuncionarios;i++)
		{
			mediaDeVendas=mediaDeVendas+ARRAY_DE_FUNCIONARIOS[i].vendas;
		}
		/*---------------------------------------------------------------------------------------*/	
			
		/*-----------------Determinando comissao de cada funcionario-----------------------------*/
		for(i=0;i<numFuncionarios;i++)
		{
			if(ARRAY_DE_FUNCIONARIOS[i].vendas<mediaDeVendas)
			{
				ARRAY_DE_FUNCIONARIOS[i].comissao=0.03*ARRAY_DE_FUNCIONARIOS[i].vendas;
			}
			else
			{
				ARRAY_DE_FUNCIONARIOS[i].comissao=0.05*ARRAY_DE_FUNCIONARIOS[i].vendas;
			}
		}	
		/*---------------------------------------------------------------------------------------*/
		
		/*----------------Determinando salario final de cada funcionario-------------------------*/
		for(i=0;i<numFuncionarios;i++)
		{
			ARRAY_DE_FUNCIONARIOS[i].salarioFinal=ARRAY_DE_FUNCIONARIOS[i].salarioBase+
				ARRAY_DE_FUNCIONARIOS[i].comissao;
		}
			
		/*---------------------------------------------------------------------------------------*/
		
		//Abertura do arquivo de saida
		writeArchive = fopen("FolhaPagamento","w");
		
		/*-----------Preenchimento do arquivo de saida------------------------------------------*/
		for(i=0;i<numFuncionarios;i++)
		{
			ARRAY_DE_FUNCIONARIOS[i].codigo=STRUCT_DE_COPIA.codigo;
			ARRAY_DE_FUNCIONARIOS[i].salarioBase=STRUCT_DE_COPIA.salarioBase;
			ARRAY_DE_FUNCIONARIOS[i].vendas=STRUCT_DE_COPIA.vendas;
			ARRAY_DE_FUNCIONARIOS[i].comissao=STRUCT_DE_COPIA.comissao;
			ARRAY_DE_FUNCIONARIOS[i].salarioFinal=STRUCT_DE_COPIA.salarioFinal;

			fprintf(writeArchive,"%d %f %f %f %f\n", STRUCT_DE_COPIA.codigo,STRUCT_DE_COPIA.salarioBase
				,STRUCT_DE_COPIA.vendas,STRUCT_DE_COPIA.comissao,STRUCT_DE_COPIA.salarioFinal );
		}
		/*-------------------------------------------------------------------------------------*/

		fclose(readArchive);
		fclose(writeArchive);
		
		return 0;
		
	}
	
	
}
