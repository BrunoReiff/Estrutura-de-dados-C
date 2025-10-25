#include "pilha_dinamica.h"
#include <stdio.h>
#include <string.h>

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Vazia( TipoPilha Pilha)
{
    return (Pilha.Topo == Pilha.Fundo) ;
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{
    TipoApontador Aux;
    Aux = (TipoApontador) malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{
    TipoApontador q;
    if (Vazia(*Pilha))
    {
        printf("Erro Lista vazia!\n");
        return;
    }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free (q);
    Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{
    return (Pilha.Tamanho) ;
}

void inverte_palavra(char *palavra)
{
    int tam = strlen(palavra);
    char strInvertida[tam];
    TipoPilha Pilha;
    TipoItem Item;
    FPVazia(&Pilha);

    for(int i = 0; i < tam; i++)
    {
        Item.Chave = palavra[i];
        Empilha(Item, &Pilha);
    }

    int j = 0;
    for(int i = Tamanho(Pilha); i > 0; i--)
    {
        Desempilha(&Pilha, &Item);
        strInvertida[j] = Item.Chave;
        j++;
    }
    printf("-> %s\n", palavra);
    printf("-> %s\n", strInvertida);

    strcpy(palavra, strInvertida);

    return strInvertida;
}

int verf_palindromo(char *palavra)
{
    int tam = strlen(palavra);
    char strInvertida[tam];
    TipoPilha Pilha;
    TipoItem Item;
    FPVazia(&Pilha);

    for(int i = 0; i < tam; i++)
    {
        Item.Chave = palavra[i];
        Empilha(Item, &Pilha);
    }

    int j = 0;
    for(int i = Tamanho(Pilha); i > 0; i--)
    {
        Desempilha(&Pilha, &Item);
        strInvertida[j] = Item.Chave;
        j++;
    }
    printf("-> %s\n", palavra);
    printf("-> %s\n", strInvertida);

    if(strcmp(palavra, strInvertida) == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}

int verf_expressoes(TipoPilha *Pilha)
{
    TipoItem Item;
    int flag = 0;

    while(!Vazia(*Pilha))
    {
        Desempilha(Pilha, &Item);
        if(Item.Chave != '(' && Item.Chave != ')')
        {
            printf("\nSoh aceitamos parenteses!");
            return 0;
        }
        if(flag == 0 && Item.Chave == '(')
        {
            return 0;
        } else if(flag >= 0 && Item.Chave == ')')
        {
            flag++;
        } else if(flag > 0 && Item.Chave == '(')
        {
            flag--;
        }

    }
    if(flag == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}
