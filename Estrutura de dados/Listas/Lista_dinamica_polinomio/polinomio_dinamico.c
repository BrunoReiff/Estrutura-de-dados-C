#include <stdlib.h>
#include <stdio.h>
#include "polinomio_dinamico.h"

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoPolinomio));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Ultimo->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

int Tamanho(TipoLista Lista)
{
    int qnt;
    TipoApontador aux;
    aux = Lista.Primeiro->Prox;
    while(aux != NULL)
    {
        qnt++;
        aux = aux->Prox;
    }
    return qnt;
}

void Insere(TipoLista *Lista, TipoElemento Elemento)
{
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoPolinomio));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Elemento = Elemento;
    Lista->Ultimo->Prox = NULL;
}

void Insere_posicaoN(TipoLista *Lista, TipoElemento Elemento, PosicaoLista n)
{
    int i;
    TipoApontador aux, novo;
    if(Vazia(*Lista))
    {
        printf("\nErro: posicao invalida!\n");
        return;
    }
    if(n == 1)
    {
        novo = (TipoApontador) malloc(sizeof(TipoPolinomio));
        novo->Elemento = Elemento;
        novo->Prox = Lista->Primeiro->Prox;
        Lista->Primeiro = novo;
    }

    aux = Lista->Primeiro;
    while(aux != NULL)
    {
        if(n == i + 1)
        {
            break;
        }
        i++;
        aux = aux->Prox;
    }
    if(aux == NULL)
    {
        printf("\nErro: posicao invalida!\n");
        return;
    }
    novo = (TipoApontador) malloc(sizeof(TipoPolinomio));
    novo->Elemento = Elemento;
    novo->Prox = aux->Prox;
    aux->Prox = novo;
}

void Retira(TipoLista *Lista, PosicaoLista n, TipoElemento *Elemento)
{
    TipoApontador pAnterior, pAtual;
    int i = 0;

    if(n == 1)
    {
        pAtual = Lista->Primeiro;
        *Elemento = Lista->Primeiro->Elemento;

        Lista->Primeiro = pAtual->Prox;
        if(Lista->Primeiro == NULL)
        {
            Lista->Ultimo == NULL;
        }
        free(pAtual);
        return;
    }

    pAnterior = Lista->Primeiro;
    pAtual = Lista->Primeiro->Prox;
    i = 1;
    while(pAtual != NULL && i < n)
    {
        pAnterior = pAtual;
        pAtual = pAtual->Prox;
        i++;
    }

    if(pAtual == NULL)
    {
        printf("Erro: Posicao %d nao existe na lista.\n", n);
        return;
    }

    *Elemento = pAtual->Elemento;
    pAnterior->Prox = pAtual->Prox;

    if(pAnterior == NULL)
    {
        Lista->Ultimo == pAnterior;
    }
    free(pAtual);
}

void imprime(TipoLista Lista)
{
    TipoApontador aux;
    aux = Lista.Primeiro->Prox;
    while(aux != NULL)
    {
        printf("Coeficiente: %d\n", aux->Elemento.Coeficiente);
        printf("Potencia: %d\n", aux->Elemento.Potencia);
        aux = aux->Prox;
    }
}

void imprime_recursiva(TipoApontador atual)
{
    if(atual == NULL)
    {
        return;
    }
    printf("Coeficiente: %d\n", atual->Elemento.Coeficiente);
    printf("Potencia: %d\n", atual->Elemento.Potencia);
    return imprime_recursiva(atual->Prox);
}
