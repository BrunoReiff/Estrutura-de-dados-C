#include "fila_dinamica.h"
#include <stdio.h>

void FFVazia( TipoFila *Fila)
{
    Fila->Frente = (TipoApontador) malloc( sizeof(TipoCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}
int Vazia( TipoFila Fila )
{
    return (Fila.Frente == Fila.Tras);
}
void Enfileira (TipoItem x, TipoFila *Fila)
{
    Fila->Tras->Prox = (TipoApontador) malloc( sizeof(TipoCelula ));
    Fila->Tras = Fila->Tras->Prox ;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
    TipoApontador q;
    if(Vazia(*Fila))
    {
        printf("Erro: fila esta vazia\n");
        return ;
    }
    q = Fila->Frente->Prox;
    *Item = q->Item;
    Fila->Frente->Prox = q->Prox;
    if (Fila->Frente->Prox == NULL)
        Fila->Tras = Fila->Frente;
    free (q);
}

int tamanho(TipoFila Fila)
{
    int i = 0;
    TipoApontador aux = Fila.Frente->Prox;
    while(aux != NULL)
    {
        i++;
        aux = aux->Prox;
    }
    return i;
}

void inverte(TipoFila *FilaSrc, TipoFila *FilaDest)
{
    FFVazia(FilaDest);
    int tam = tamanho(*FilaSrc);
    TipoItem *aux = malloc(sizeof(TipoItem) * tam);
    if(aux == NULL) return;

    int i = 0;

    printf("\n-> ");
    while(!Vazia(*FilaSrc))
    {
        Desenfileira(FilaSrc, &aux[i]);
        printf("%d ", aux[i].Chave);
        i++;
    }
    printf("\n-> ");
    int j = i;
    for(j = i - 1; j >= 0; j--)
    {
        printf("%d ", aux[j].Chave);
        Enfileira(aux[j], FilaDest);
    }

    free(aux);
}

void concatena(TipoFila *Fila1, TipoFila *Fila2)
{

    Fila1->Tras->Prox = Fila2->Frente->Prox;
    Fila1->Tras = Fila2->Tras;
    Fila1->Tras->Prox = NULL;
    Fila2->Frente->Prox = NULL;
    Fila2->Tras = Fila2->Frente;
}

void imprime(TipoFila Fila)
{
    if(Vazia(Fila))
    {
        printf("\nErro: Fila esta vazia!\n");
        return;
    }
    TipoApontador aux = Fila.Frente->Prox;
    printf("\nImprimindo lista...\n[ ");
    while(aux != NULL)
    {
        printf("%d ", aux->Item.Chave);
        aux = aux->Prox;
    }
    printf("]\n");
}
