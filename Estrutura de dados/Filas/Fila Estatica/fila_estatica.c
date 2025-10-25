#include "fila_estatica.h"

void FFVazia(TipoFila *Fila)
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}
int Vazia(TipoFila Fila)
{
    return (Fila.Frente == Fila.Tras);
}

void Enfileira (TipoItem x, TipoFila *Fila)
{
    if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
    {
        printf ( "Erro fila esta cheia\n");
        return;
    } else{
        Fila->Item [Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
    }
}
void Desenfileira (TipoFila *Fila, TipoItem *Item)
{
    if(Vazia(*Fila)){
        printf ( "Erro fila esta vazia \n" );
        return;
    } else
    {
        *Item = Fila->Item [Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
    }
}

void Imprime(TipoFila Fila)
{
    int i = Fila.Frente - 1;
    while(i != Fila.Tras - 1)
    {
        printf("%d\n", Fila.Item[i]);
        i++;
        if(i == MAXTAM)
        {
            i = 0;
        }
    }
}


void Inverte(TipoFila *Fila)
{
    TipoItem Item;

    if (Vazia(*Fila)){
        return;
    }

    Desenfileira(Fila, &Item);

    Inverte(Fila);

    Enfileira(Item, Fila);
}
