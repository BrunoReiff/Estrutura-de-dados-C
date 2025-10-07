#include <stdio.h>
#include "lista.h"

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo > MAXTAM)
    {
        printf("Lista esta cheia!!\n");
    } else {
        Lista->item[Lista->Ultimo - 1] = x;
    }
    Lista->Ultimo++;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{
    int aux;
    if (Vazia(*Lista) || p>= Lista->Ultimo)
    {
        printf("Erro: Posicao nao existe!\n");
        return;
    }

    *Item = Lista->item[p - 1];
    Lista->Ultimo--;
    for (aux = p; aux < Lista->Ultimo; aux++)
    {
        Lista->item[aux - 1] = Lista->item[aux];
    }
}

void Retira_n_elementos(TipoLista *Lista, int n)
{
    int aux;
    if (Vazia(*Lista))
    {
        printf("Erro: Lista vazia!\n");
        return;
    }

    for(aux = n; aux < Lista->Ultimo; aux++)
    {
        Lista->item[aux - n] = Lista->item[aux];
    }
    Lista->Ultimo -= n;
}

void Imprime(TipoLista Lista)
{
    int aux;
    for(aux = Lista.Primeiro - 1; aux <= (Lista.Ultimo - 2); aux++)
    {
        printf("%d\n", Lista.item[aux].chave);
    }
}

void Localiza(TipoLista Lista, TipoApontador n)
{
    if(n >= Lista.Ultimo || Vazia(Lista)){
        printf("Posicao nao existe!!\n");
    }else {
        printf("Posicao %d da lista contem: \n");
        printf("Chave: %d", Lista.item[n].chave);
    }
}

void Concatena(TipoLista *Lista1, TipoLista *Lista2, TipoLista *ListaResultado)
{
    int i, j;
    if(Vazia(*Lista1) || Vazia(*Lista2))
    {
        printf("Nao eh permitido concatenar listas vazias!!");
        return;
    }

    for(i = Lista1->Primeiro - 1; i < Lista1->Ultimo - 1; i++)
    {
        if (ListaResultado->Ultimo == MAXTAM)
        {
            printf("A lista esta cheia!");
            return;
        }
        ListaResultado->item[ListaResultado->Ultimo - 1] = Lista1->item[i];
        ListaResultado->Ultimo++;
    }

    for(j = Lista2->Primeiro - 1; j < Lista2->Ultimo - 1; j++)
    {
        if (ListaResultado->Ultimo == MAXTAM)
        {
            printf("A lista esta cheia!");
            return;
        }
        ListaResultado->item[ListaResultado->Ultimo - 1] = Lista2->item[j];
        ListaResultado->Ultimo++;
    }
}

void Copia(TipoLista *ListaOrigem, TipoLista *ListaDest)
{
    FLVazia(ListaDest);
    for(int i = ListaOrigem->Primeiro - 1; i < ListaOrigem->Ultimo - 1; i++)
    {
        ListaDest->item[ListaDest->Ultimo - 1] = ListaOrigem->item[i];
        ListaDest->Ultimo++;
    }
}

void Ordena(TipoLista *Lista)
{
    TipoItem aux;
    for(int i = Lista->Primeiro - 1; i < Lista->Ultimo - 1; i++)
    {
        for(int j = Lista->Primeiro - 1; j < Lista->Ultimo - 1; j++)
        {
            if (Lista->item[i].chave < Lista->item[j].chave)
            {
                aux = Lista->item[i];
                Lista->item[i] = Lista->item[j];
                Lista->item[j] = aux;
            }
        }
    }
}

void pesquisa_item(TipoLista Lista, TipoChave x)
{
    if (Vazia(Lista))
    {
        printf("\nErro: A lista esta vazia!\n");
    }

    for (int i = Lista.Primeiro - 1; i < Lista.Ultimo - 1; i++)
    {
        if (x == Lista.item[i].chave)
        {
            printf("O TipoChave '%d' esta na posicao %d da lista!\n", x, i + 1);
        }
    }
}

void particiona(TipoLista *Lista, TipoApontador n, TipoLista *ListaParticionada)
{
    if (Vazia(*Lista))
    {
        printf("\nErro: Lista vazia!\n");
        return;
    }
    FLVazia(ListaParticionada);

    int InicioCorte = n - 1;

    for(int i = InicioCorte; i < Lista->Ultimo - 1; i++)
    {
        ListaParticionada->item[ListaParticionada->Ultimo - 1] = Lista->item[i];
        ListaParticionada->Ultimo++;
    }

    Lista->Ultimo = InicioCorte + 1;
}

void Troca(TipoLista *Lista1, TipoApontador x, TipoApontador y)
{
    x--;
    y--;
    TipoItem aux = Lista1->item[x];
    Lista1->item[x] = Lista1->item[y];
    Lista1->item[y] = aux;
}
