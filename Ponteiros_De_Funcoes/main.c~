#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatematicaLib.h"

void MostraSerie(float *pserie, int pqtde)
{
    int pind;
//Mostrar Nova Série Gerada:
    system("cls");
    printf("#######################          SERIE (%d Termos)         ###################################", pqtde);
    printf("\n\n");
    for(pind=0; pind<pqtde; pind++)
        printf("%do. Termo: \t%.6f\n", pind+1, pserie[pind]);
    printf("\n\n##########################################################################################\n");
    system("pause");
}

char MontaTela(int *popers, int pqtde, float *pserie, int pqtde2)
{
    char popmenu;
    int pind;
//Gerar série inicial:
    GeraSerieAleatoria(pserie, pqtde2);
//Desmarcar todas estatisticas:
    for(pind=0; pind<pqtde; pind++)
        popers[pind] = -1;
    system("cls");
    printf("####################### ESTATISTICAS DE SERIES ###################################");
    printf("\n\n\n");
    printf("#######################          MENU          ###################################");
    printf("\n\n\n");
    printf("\n[G] - Gerar nova Serie");
    printf("\n[T] - Todas Estatisticas");
    printf("\n[S] - Soma");
    printf("\n[M] - Media");
    printf("\n[D] - Desvio Padrao");
    printf("\n[P] - Soma de Potencias");
    printf("\n[Q] - Soma dos Quadrados");
    printf("\n[Qualquer Outra Tecla] - Encerrar");
    printf("\nDigite a Opcao Desejada: ");
    popmenu = getch();

    switch (popmenu)
    {
    case 'G':
        GeraSerieAleatoria(pserie, pqtde2);
        MostraSerie(pserie, pqtde2);
        break;
    case 'T':
//Marcar todas estatisticas:
        for(pind=0; pind<pqtde; pind++)
            popers[pind] = pind;
        break;
    case 'S':
        popers[0] = 0;
        break;
    case 'M':
        popers[0] = 1;
        break;
    case 'D':
        popers[0] = 2;
        break;
    case 'P':
        popers[0] = 3;
        break;
    case 'Q':
        popers[0] = 4;
        break;
    default:
        system("cls");
        printf("####################### ESTATISTICAS DE SERIES ###################################");
        printf("\n\n\n");
        printf("Programa Encerrado...\n\n\n");
        popmenu = 'E'; //Encerrar
        break;
    }
    return (popmenu);
}

void CalculaEMostra(float (*pOperacoes[])(float *, int), char *pNomes[], int *pSelecionados, int pqtde, float *pserie, int pqtde2)
{
    int pp, pindoper, ptemcalculo = 0;
    float pvalor;

//Verificar se há pelo menos um valor a ser impresso:
    for(pp=0; pp<pqtde; pp++)
    {
        pindoper = pSelecionados[pp];
        if(pindoper>=0)
        {
            ptemcalculo = 1;
            break;
        }
    }
    if(ptemcalculo)
    {
//Cálculo e visualização de Estatísticas Selecionadas:
        system("cls");
        printf("\n\n####################### ESTATISTICAS ###################################");
        for(pp=0; pp<pqtde; pp++)
        {
            pindoper = pSelecionados[pp];
            if(pindoper>=0)
            {
                pvalor = pOperacoes[pindoper](pserie, pqtde2);
                printf("\n\n%s: \t%.6f\n", pNomes[pindoper], pvalor);
            }
        }
        printf("\n\n########################################################################\n");
        system("pause");
    }
}

int main()
{




    do
    {
        menu = MontaTela(Selecao, 5, Serie, 20);
        CalculaEMostra(Operacoes, Nomes, Selecao, 5, Serie, 20);
    }
    while(menu != 'E');

    return 0;
}
