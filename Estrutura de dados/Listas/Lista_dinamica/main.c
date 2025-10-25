#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

int main()
{
    TipoLista ML, ListaInvertida, ML2;
    TipoItem Item;
    FLVazia(&ML);

    Item.Chave = 1;
    insere_fim(&ML, Item);
    Item.Chave = 2;
    insere_fim(&ML, Item);
    Item.Chave = 3;
    insere_fim(&ML, Item);
    Item.Chave = 4;
    insere_fim(&ML, Item);

    imprime(ML);

    FLVazia(&ML2);

    Item.Chave = 1;
    insere_fim(&ML2, Item);
    Item.Chave = 2;
    insere_fim(&ML2, Item);
    Item.Chave = 3;
    insere_fim(&ML2, Item);
    Item.Chave = 4;
    insere_fim(&ML2, Item);

    printf("\nImprimindo recursivamente...\n");
    imprime_rec(ML2.Primeiro->Prox);

    if(verf_identidade(ML.Primeiro->Prox, ML2.Primeiro->Prox))
    {
        printf("\nML e ML2 sao iguais!\n");
    } else {
        printf("\nML e ML2 nao sao iguais!\n");
    }



    return 0;
}
