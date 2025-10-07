#include "lista_vertices.h"
#include <stdio.h>
#include <stdbool.h>

void FLVazia(TipoLista_Vertice *Lista)
{
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

bool vazia(TipoLista_Vertice Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void imprime(TipoLista_Vertice Lista)
{
    if(vazia(Lista))
    {
        printf("\nErro: Lista vazia!\n");
        return;
    }
    printf("\nImprimindo lista...\n[ ");
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo - 1; i++)
    {
        printf("(%.2f,%.2f) ", Lista.Ponto[i].x, Lista.Ponto[i].y);
    }
    printf("]\n");
}

void insere(TipoLista_Vertice *Lista, TipoPonto Ponto)
{
    if(Lista->Ultimo > MAXTAM)
    {
        printf("\nErro: Lista cheia!\n");
        return;
    }

    Lista->Ponto[Lista->Ultimo - 1] = Ponto;
    Lista->Ultimo++;
}

void retirar(TipoLista_Vertice *Lista, TipoApontador n, TipoPonto *Ponto)
{
    if(vazia(*Lista) || n > Lista->Ultimo)
    {
        printf("\nErro: posicao invalida!\n");
        return;
    }

    if(n < 3)
    {
        printf("\nErro: Um poligono necessariamente tem mais de 3 lados.\n");
        return;
    }

    *Ponto = Lista->Ponto[n];
    Lista->Ultimo--;

    for(int i = n; i < Lista->Ultimo; i++)
    {
        Lista->Ponto[n - 1] = Lista->Ponto[i];
    }
}

