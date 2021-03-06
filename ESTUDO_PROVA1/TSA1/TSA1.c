#include <stdio.h>
#include <stdlib.h>

struct funcionario
{
	int codigo;
	float salarioBase;
	float valorVendas;
	float comissao;
	float salarioFinal;	
};

int main()
{
	/*-----------------------Declaracao das variaveis--------------------------------------------------------------*/
	FILE *readArchive,*writeArchive;
	char archiveName[50],auxiliarCharacter;
	int numberOfEmployees=0,i,j,codigo=0;
	float comissao=0,valorVendas=0;
	float salarioBase=0,salarioFinal=0,mediaVendas=0;
	struct funcionario *employeeStructArray,auxiliarStruct;
	/*------------------------------------------------------------------------------------------------------------*/
	
	//Para abrir qualquer arquivo informado pelo usuario
	/*printf("Entre com o nome do arquivo que deseja abrir: ");
	scanf("%s", archiveName);
	readArchive = fopen(archiveName, "r");	*/
	
	//Para abrir o arquivo MovimentoVendas direto
	readArchive = fopen("MovimentoVendas", "r");

	//Fluxo principal, o arquivo foi encontrado
	if(readArchive!=NULL)
	{

		/*---------------------------------Contando o numero de empregados------------------------------------*/	
		while(auxiliarCharacter!=EOF)
		{
			auxiliarCharacter=fgetc(readArchive);
			if(auxiliarCharacter=='\n')
			{
				numberOfEmployees++;
			}
		
		}	
		/*----------------------------------------------------------------------------------------------------*/
		fclose(readArchive);
		// Refazendo a leitura do arquivo informado pelo usuario
		//readArchive = fopen(archiveName, "r");
		
		//Refazendo a leitura do arquivo MovimentoVendas
		readArchive = fopen("MovimentoVendas", "r");
		
		//Instancia do vetor de structs com o conhecimento do numero 
		employeeStructArray = malloc(numberOfEmployees * sizeof(struct funcionario));
	
		i=0;
		//Jogando as informacoes do arquivos nas structs
		while(fscanf(readArchive, "%d %f %f\n", &codigo, &salarioBase, &valorVendas)!=EOF)
		{
			employeeStructArray[i].codigo=codigo;
			employeeStructArray[i].salarioBase=salarioBase;			
			employeeStructArray[i].valorVendas=valorVendas;
			i++;
		}
		fclose(readArchive);
	
		//Impressao da struct
		/*for(i=0;i<numberOfEmployees;i++)
		{
			printf("%d  - %f - %f\n", employeeStructArray[i].codigo, employeeStructArray[i].salarioBase, 				employeeStructArray[i].valorVendas);
		}*/
		
		/*--------------------------------Calculando media de vendas----------------------------------------*/
		for(i=0;i<numberOfEmployees;i++)
		{
			mediaVendas=mediaVendas+employeeStructArray[i].valorVendas;
		}
		mediaVendas=mediaVendas/(float)numberOfEmployees;
		/*--------------------------------------------------------------------------------------------------*/

		//Calculando a comissao de cada vendedor
		for(i=0;i<numberOfEmployees;i++)
		{
			if(employeeStructArray[i].valorVendas<mediaVendas)
			{
				employeeStructArray[i].comissao=employeeStructArray[i].valorVendas*0.03;
			}
			if(employeeStructArray[i].valorVendas>mediaVendas)
			{
				employeeStructArray[i].comissao=employeeStructArray[i].valorVendas*0.05;
			}
			
		}
		
		//Calculando o salario final de cada vendedor
		for(i=0;i<numberOfEmployees;i++)
		{
			employeeStructArray[i].salarioFinal=employeeStructArray[i].salarioBase+employeeStructArray[i].comissao;
		}
		
		/*-------------Ordenacao da Struct por "codigo" utilizando algoritmo Bubblesort------------------------*/
		for(i=0;i<numberOfEmployees;i++)
		{
			for(j=0;j<numberOfEmployees-1;j++)
			{
				if(employeeStructArray[j].codigo>employeeStructArray[j+1].codigo)
				{
					//Copiando dados da struct [j] para a struct auxiliar
					auxiliarStruct.codigo = employeeStructArray[j].codigo;
					auxiliarStruct.salarioBase = employeeStructArray[j].salarioBase;
					auxiliarStruct.valorVendas = employeeStructArray[j].valorVendas;
					auxiliarStruct.comissao = employeeStructArray[j].comissao;
					auxiliarStruct.salarioFinal = employeeStructArray[j].salarioFinal;	
					
					//Copiando dados da struct [j+1] para a struct [j]
					employeeStructArray[j].codigo = employeeStructArray[j+1].codigo;
					employeeStructArray[j].salarioBase = employeeStructArray[j+1].salarioBase;
					employeeStructArray[j].valorVendas = employeeStructArray[j+1].valorVendas;
					employeeStructArray[j].comissao = employeeStructArray[j+1].comissao;
					employeeStructArray[j].salarioFinal = employeeStructArray[j+1].salarioFinal;

					//Copiando dados da struct auxiliar para a struct [j+1]	
					employeeStructArray[j+1].codigo = auxiliarStruct.codigo;
					employeeStructArray[j+1].salarioBase = auxiliarStruct.salarioBase;
					employeeStructArray[j+1].valorVendas = auxiliarStruct.valorVendas;
					employeeStructArray[j+1].comissao = auxiliarStruct.comissao;
					employeeStructArray[j+1].salarioFinal = auxiliarStruct.salarioFinal;
				}
				else
				{
					//Fazer nada
				}
			}
		}
		/*---------------------------------------------------------------------------------------------------*/


		/*----------------------Escrita do arquivo de saida--------------------------------------------------*/
		writeArchive=fopen("Receita", "w");
		
		for(i=0;i<numberOfEmployees;i++)
		{
			fprintf(writeArchive,"%d %.1f %.1f %.1f %.1f\n",employeeStructArray[i].codigo,
			employeeStructArray[i].salarioBase,employeeStructArray[i].valorVendas,
			employeeStructArray[i].comissao,employeeStructArray[i].salarioFinal);
		}
		fclose(writeArchive);
		printf("\nArquivo de saida criado com sucesso!\n");
		/*---------------------------------------------------------------------------------------------------*/
	}
	//Fluxo alternativo, o arquivo nao foi encontrado
	else
	{
		printf("Nao foi possivel abrir o arquivo.\n");
	}
	return 0;
}
