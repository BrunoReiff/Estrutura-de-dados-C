#include "lista_duplaencadeada.h"
#include <stdio.h>
#include <stdlib.h>

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->Primeiro->Ant = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere_fim(TipoLista *Lista, TipoItem Item)
{
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo->Prox->Ant = Lista->Ultimo;
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = Item;
    Lista->Ultimo->Prox = NULL;
}

void Insere_enesimo(TipoLista *Lista, TipoItem Item, Posicao n)
{
    if(n <= 0)
    {
        printf("Erro: Posicao invalida!\n");
        return;
    }

    TipoApontador Anterior, Atual = Lista->Primeiro;
    int i = 0;
    while(Atual!= NULL && i != n)
    {
        Anterior = Atual;
        Atual = Atual->Prox;
        i++;
    }
    if(i < n || Anterior == NULL)
    {
        printf("Erro: Posicao invalida!\n");
        return;
    }

    TipoApontador aux = (TipoApontador) malloc(sizeof(TipoCelula));
    aux->Item = Item;
    aux->Ant = Anterior;
    aux->Prox = Atual;
    Anterior->Prox = aux;
    if(Atual == NULL)
    {
        Lista->Ultimo = aux;
    } else
    {
        Atual->Ant = aux;
    }
}

void Retira(TipoLista *Lista, TipoItem *Item, Posicao n)
{
    if(n <= 0)
    {
        printf("Erro: Posicao invalida!\n");
        return;
    }

    TipoApontador Anterior, Atual = Lista->Primeiro;
    int i = 0;
    while(Atual!= NULL && i != n)
    {
        Anterior = Atual;
        Atual = Atual->Prox;
        i++;
    }
    if(i < n || Atual == NULL)
    {
        printf("Erro: Posicao invalida!\n");
        return;
    }

    if(Atual->Prox == NULL)
    {
        printf("\nDEGUB: ANTERIOR = %d", Atual->Item.Chave);
        Anterior->Prox = NULL;
        Lista->Ultimo = Anterior;
        *Item = Atual->Item;
        free(Atual);
    } else
    {
        Atual->Prox->Ant = Anterior;
        Anterior->Prox = Atual->Prox;
        *Item = Atual->Item;
        free(Atual);
    }
}


void Imprime(TipoLista Lista)
{
    if(Vazia(Lista))
    {
        printf("Erro: Lista vazia!\n");
        return;
    }
    printf("\nImprimindo lista...\n[ ");
    TipoApontador aux = Lista.Primeiro->Prox;
    while(aux != NULL)
    {
        printf("%d ", aux->Item.Chave);
        aux = aux->Prox;
    }
    printf("]\n");
}

void ImprimeInvertido(TipoLista Lista)
{
    if(Vazia(Lista))
    {
        printf("Erro: Lista vazia!\n");
        return;
    }
    printf("\nImprimindo lista...\n[ ");
    TipoApontador aux = Lista.Ultimo;
    while(aux != Lista.Primeiro)
    {
        printf("%d ", aux->Item.Chave);
        aux = aux->Ant;
    }
    printf("]\n");
}
