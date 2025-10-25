#include "lista_estatica.h"
#include <stdio.h>

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoLista *Lista, TipoItem Item)
{
    if(Lista->Ultimo == MAXTAM)
    {
        printf("Erro: A lista esta cheia!\n");
        return;
    }
    Lista->Item[Lista->Ultimo - 1] = Item;
    Lista->Ultimo++;
}

void Insere_enesimo(TipoLista *Lista, Posicao n, TipoItem Item)
{
    if(n > Lista->Ultimo || n < Lista->Primeiro)
    {
        printf("Erro: Posicao invalida!\n");
        return;
    }
    for(int i = Lista->Ultimo - 1; i > n - 1; i--)
    {
        Lista->Item[i] = Lista->Item[i - 1];
    }
    Lista->Item[n - 1] = Item;
    Lista->Ultimo++;
}

void Retira_fim(TipoLista *Lista, TipoItem *Item)
{
    if(Vazia(*Lista))
    {
        printf("Erro: A lista esta vazia!\n");
        return;
    }
    Lista->Ultimo--;
}

void Retira_enesimo(TipoLista *Lista, Posicao n, TipoItem *Item)
{
    if(n > Lista->Ultimo - 1 || n < Lista->Primeiro - 1 || Vazia(*Lista))
    {
        printf("Erro: Posicao invalida!\n");
        return;
    }
    for(int i = n - 1; i < Lista->Ultimo - 2; i++)
    {
        Lista->Item[i] = Lista->Item[i + 1];
    }
    Lista->Ultimo--;
    *Item = Lista->Item[n - 1];
}

void LocalizaItem(TipoLista Lista, TipoChave Chave)
{
    if(Vazia(Lista))
    {
        printf("Erro: A lista esta vazia!\n");
        return;
    }
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo - 1; i++)
    {
        if(Lista.Item[i].chave == Chave)
        {
            printf("\nItem encontrado na posicao %d!\n", i + 1);
            return;
        }
    }
    printf("\nItem nao encontrado!\n");
}

void Combina(TipoLista Lista1, TipoLista Lista2, TipoLista *ListaCombinada)
{
    FLVazia(ListaCombinada);
    if(Vazia(Lista1) || Vazia(Lista2))
    {
        printf("\nErro: Nao eh possivel combinar listas vazias!\n");
        return;
    }
    for(int i = Lista1.Primeiro - 1; i < Lista1.Ultimo - 1; i++)
    {
        ListaCombinada->Item[ListaCombinada->Ultimo - 1] = Lista1.Item[i];
        ListaCombinada->Ultimo++;
    }
    for(int j = Lista2.Primeiro - 1; j < Lista2.Ultimo - 1; j++)
    {
        ListaCombinada->Item[ListaCombinada->Ultimo - 1] = Lista2.Item[j];
        ListaCombinada->Ultimo++;
    }
}

void Particiona(TipoLista Lista, Posicao n, TipoLista *ListaParticionada1, TipoLista *ListaParticionada2)
{
    FLVazia(ListaParticionada1);
    FLVazia(ListaParticionada2);
    if(Vazia(Lista))
    {
        printf("\nErro: Nao eh possivel particionar lista vazia!\n");
        return;
    }
    for(int i = Lista.Primeiro - 1; i < n - 1; i++)
    {
        ListaParticionada1->Item[ListaParticionada1->Ultimo - 1] = Lista.Item[i];
        ListaParticionada1->Ultimo++;
    }
    for(int j = n - 1; j < Lista.Ultimo -1; j++)
    {
        ListaParticionada2->Item[ListaParticionada2->Ultimo - 1] = Lista.Item[j];
        ListaParticionada2->Ultimo++;
    }
}

void Copia(TipoLista ListaOrigem, TipoLista *ListaDestino)
{
    FLVazia(ListaDestino);
    if(Vazia(ListaOrigem))
    {
        printf("Erro: A lista origem esta vazia!\n");
        return;
    }
    for(int i = ListaOrigem.Primeiro - 1; i < ListaOrigem.Ultimo - 1; i++)
    {
        ListaDestino->Item[ListaDestino->Ultimo - 1] = ListaOrigem.Item[i];
        ListaDestino->Ultimo++;
    }
}

void ordena_crescente(TipoLista *Lista)
{
    TipoItem aux;
    if(Vazia(*Lista))
    {
        printf("Erro: A lista esta vazia!\n");
        return;
    }

    for(int i = Lista->Primeiro - 1; i < Lista->Ultimo - 1; i++)
    {
        for(int j = Lista->Primeiro - 1; j < Lista->Ultimo - 1; j++)
        {
            if(Lista->Item[i].chave < Lista->Item[j].chave)
            {
                aux = Lista->Item[i];
                Lista->Item[i] = Lista->Item[j];
                Lista->Item[j] = aux;
            }
        }
    }
}

void ordena_decrescente(TipoLista *Lista)
{
    TipoItem aux;
    if(Vazia(*Lista))
    {
        printf("Erro: A lista esta vazia!\n");
        return;
    }

    for(int i = Lista->Primeiro - 1; i < Lista->Ultimo - 1; i++)
    {
        for(int j = Lista->Primeiro - 1; j < Lista->Ultimo - 1; j++)
        {
            if(Lista->Item[i].chave > Lista->Item[j].chave)
            {
                aux = Lista->Item[i];
                Lista->Item[i] = Lista->Item[j];
                Lista->Item[j] = aux;
            }
        }
    }
}

void verifica_ordenacao(TipoLista Lista)
{
    int crescente = 1, decrescente = 1;
    if(Vazia(Lista))
    {
        printf("Erro: A lista esta vazia!\n");
        return;
    }
    for(int i = Lista.Primeiro; i < Lista.Ultimo - 1; i++)
    {
        if(Lista.Item[i - 1].chave > Lista.Item[i].chave)
        {
            crescente = 0;
        }
    }
    for(int i = Lista.Primeiro; i < Lista.Ultimo - 1; i++)
    {
        if(Lista.Item[i - 1].chave < Lista.Item[i].chave)
        {
            decrescente = 0;
        }
    }
    if(crescente == 1)
    {
        printf("\nLista ordenada de forma crescente!\n");
    } else if(decrescente == 1){
        printf("\nLista ordenada de forma decrescente!\n");
    } else {
        printf("\nLista nao esta ordenada!\n");
    }
}


void inverte(TipoLista *Lista)
{
    int aux;
    TipoApontador Inicio, Fim;
    Inicio = Lista->Primeiro - 1;
    Fim = Lista->Ultimo - 2;

    while(Inicio < Fim)
    {
        aux = Lista->Item[Fim].chave;
        Lista->Item[Fim].chave = Lista->Item[Inicio].chave;
        Lista->Item[Inicio].chave = aux;
        Inicio++;
        Fim--;
    }
}

void Imprime(TipoLista Lista)
{
    printf("\nImprimindo lista...\n[ ");
    for(int i = Lista.Primeiro - 1; i < Lista.Ultimo - 1; i++)
    {
        printf("%d ", Lista.Item[i].chave);
    }
    printf("]\n");
}
