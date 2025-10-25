#include "fila_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void insere_fim(TipoLista *Lista, TipoItem Item)
{
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = Item;
    Lista->Ultimo->Prox = NULL;
}

void insere_enesimo(TipoLista *Lista, Posicao n, TipoItem Item)
{
    TipoApontador Anterior, Atual = Lista->Primeiro;
    int i = 0;
    while(i != n && Atual != NULL)
    {
        i++;
        Anterior = Atual;
        Atual = Atual->Prox;
    }
    if(n < 1)
    {
        printf("\nErro: Posicao invalida!\n");
        return;
    }
    TipoApontador aux = (TipoApontador) malloc(sizeof(TipoCelula));
    aux->Item = Item;
    Anterior->Prox = aux;
    aux->Prox = Atual;
    if(aux->Prox == NULL)
    {
        Lista->Ultimo = aux;
    }
}

void retira(TipoLista *Lista, Posicao n, TipoItem *Item)
{
    if(Vazia(*Lista))
    {
        printf("\nErro: Lista esta vazia!\n");
        return;
    }
    TipoApontador Anterior, Atual = Lista->Primeiro;
    int i = 0;
    while(i != n && Atual != NULL)
    {
        i++;
        Anterior = Atual;
        Atual = Atual->Prox;
    }
    if(Atual == NULL || n < 1)
    {
        printf("\nErro: Posicao invalida!\n");
        return;
    }
    if(Atual->Prox == NULL)
    {
        Anterior->Prox = NULL;
        Lista->Ultimo = Anterior;
        free(Atual);
        return;
    }
    Anterior->Prox = Atual->Prox;
    free(Atual);
}

void inverte(TipoLista *Lista, TipoLista *ListaInvertida)
{
    if(Vazia(*Lista))
    {
        printf("\nErro: Lista esta vazia!\n");
        return;
    }

    FLVazia(ListaInvertida);
    TipoApontador Atual;

    Atual = Lista->Primeiro->Prox;
    while(Atual != NULL)
    {
        insere_enesimo(ListaInvertida, 1, Atual->Item);
        Atual = Atual->Prox;
    }
}

int tamanho_rec(TipoLista Lista, TipoApontador Primeiro)
{
    if(Vazia(Lista))
    {
        printf("\nErro: Lista esta vazia!\n");
        return;
    }

    if(Primeiro->Prox == NULL)
    {
        return;
    } else
    {
        return 1 + tamanho_rec(Lista, Primeiro->Prox);
    }
}

bool verf_identidade(TipoApontador Primeiro1, TipoApontador Primeiro2)
{
    if(Primeiro1 == NULL && Primeiro2 == NULL)
    {
        return true;
    }

    if(Primeiro1->Item.Chave != Primeiro1->Item.Chave)
    {
        return false;
    }

    return verf_identidade(Primeiro1->Prox, Primeiro2->Prox);

}


void imprime(TipoLista Lista)
{
    if(Vazia(Lista))
    {
        printf("\nErro: Lista esta vazia!\n");
        return;
    }
    TipoApontador aux = Lista.Primeiro->Prox;
    printf("\nImprimindo lista...\n[ ");
    while(aux != NULL)
    {
        printf("%d ", aux->Item.Chave);
        aux = aux->Prox;
    }
    printf("]\n");
}

void imprime_rec(TipoApontador Atual)
{
    if(Atual->Prox == NULL)
    {
        printf("%d\n", Atual->Item.Chave);
        return;
    } else
    {
        printf("%d\n", Atual->Item.Chave);
        return imprime_rec(Atual->Prox);
    }
}
