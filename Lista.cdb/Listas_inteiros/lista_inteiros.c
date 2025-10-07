#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_inteiros.h"


void FLVazia(TipoLista_Inteiros *Lista)
{
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

void preenche(TipoLista_Inteiros *Lista)
{
    srand(time(NULL));
    for(int i = Lista->Primeiro - 1; i < MAXTAM; i++)
    {
        Lista->item[i].inteiro = rand()% 100;
        Lista->Ultimo++;
    }
}

void imprime(TipoLista_Inteiros Lista)
{
    printf("\nImprimindo Lista...\n[");
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo - 1; i++)
    {
        printf("%d ", Lista.item[i].inteiro);
    }
    printf("]\n");
}

int qnt_pares(TipoLista_Inteiros Lista)
{
    int qnt = 0;

    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo; i++)
    {
        if(Lista.item[i].inteiro%2 == 0)
        {
            qnt++;
        }
    }
    return qnt;
}

void geraLista_pares(TipoLista_Inteiros Lista, TipoLista_Inteiros *ListaGerada)
{
    FLVazia(ListaGerada);
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo; i++)
    {
        if(Lista.item[i].inteiro%2 == 0)
        {
            ListaGerada->item[ListaGerada->Ultimo - 1] = Lista.item[i];
            ListaGerada->Ultimo++;
        }
    }
}

int calc_media(TipoLista_Inteiros Lista)
{
    int media = 0;
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo; i++)
    {
        media += Lista.item[i].inteiro;
    }
    media /= Lista.Ultimo - 1;

    return media;
}

void ordena(TipoLista_Inteiros *Lista)
{
    TipoItem aux;
    for(int i = Lista->Primeiro - 1; i < Lista->Ultimo - 1; i++)
    {
        for(int j = Lista->Primeiro - 1; j < Lista->Ultimo - 1; j++)
        {
            if(Lista->item[i].inteiro < Lista->item[j].inteiro)
            {
                aux = Lista->item[i];
                Lista->item[i] = Lista->item[j];
                Lista->item[j] = aux;
            }
        }
    }
}

int verf_ordenacao(TipoLista_Inteiros Lista)
{
    TipoLista_Inteiros ListaOrdenada;
    ListaOrdenada = Lista;
    ordena(&ListaOrdenada);
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo - 1; i++)
    {
        if(Lista.item[i].inteiro != ListaOrdenada.item[i].inteiro)
        {
            return 0;
        }
    }
    inverte(&Lista, &ListaOrdenada);
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo - 1; i++)
    {
        if(Lista.item[i].inteiro != ListaOrdenada.item[i].inteiro)
        {
            return 0;
        }
    }
    return 1;
}

void inverte(TipoLista_Inteiros *Lista, TipoLista_Inteiros *ListaInvertida)
{
    FLVazia(ListaInvertida);
    for(int i = Lista->Ultimo - 2; i > Lista->Primeiro - 2; i --)
    {
        ListaInvertida->item[ListaInvertida->Ultimo - 1] = Lista->item[i];
        ListaInvertida->Ultimo++;
    }
}
