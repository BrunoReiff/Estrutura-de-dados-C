#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
     TipoLista Lista1, Lista2, ListaConcatenada, ListaCopiada, ListaParticionada;
    TipoItem Item1, Item2;

    FLVazia(&Lista1);
    FLVazia(&Lista2);
    FLVazia(&ListaConcatenada);

    Item1.chave = 10;
    Insere(Item1, &Lista1);
    Item1.chave = 18;
    Insere(Item1, &Lista1);
    Item1.chave = 16;
    Insere(Item1, &Lista1);
    Item1.chave = 11;
    Insere(Item1, &Lista1);
    Item1.chave = 10;
    Insere(Item1, &Lista1);
    Item1.chave = 18;
    Insere(Item1, &Lista1);
    Item1.chave = 16;
    Insere(Item1, &Lista1);
    Item1.chave = 11;
    Insere(Item1, &Lista1);

    Item2.chave = 11;
    Insere(Item2, &Lista2);

    if (Vazia(ListaConcatenada))
    {
        printf("Lista3 esta vazia!\n");
    } else {
        printf("Lista3 nao esta vazia!\n");
    }

    Concatena(&Lista1, &Lista2, &ListaConcatenada);

    if (Vazia(ListaConcatenada))
    {
        printf("Lista3 esta vazia!\n");
    } else {
        printf("Lista3 nao esta vazia!\n");
    }
    printf("Lista Concatenada:\n");
    Imprime(ListaConcatenada);

    Copia(&Lista1, &ListaCopiada);
    printf("Lista Copiada:\n");
    Imprime(ListaCopiada);


    printf("\nImprimindo lista1...\n");
    Imprime(Lista1);
    printf("\nOrdenando lista1...\n");
    Ordena(&Lista1);
    Imprime(Lista1);

    printf("Pesquisando Item...\n");
    pesquisa_item(Lista1, 16);

    printf("\nImprimindo lista1...\n");
    Imprime(Lista1);
    printf("\nParticionando lista1...\n");
    particiona(&Lista1, 5, &ListaParticionada);
    printf("\nImprimindo lista1...\n");
    Imprime(Lista1);
    printf("\nImprimindo listaParticionada...\n");
    Imprime(ListaParticionada);

    Concatena(&Lista1, &ListaParticionada, &ListaConcatenada);
    printf("\nImprimindo listaConcatenada...\n");
    Ordena(&ListaConcatenada);
    Imprime(ListaConcatenada);
    printf("Retirando 5 elementos da listaConcatenada...\n");
    Retira_n_elementos(&ListaConcatenada, 5);
    printf("\nImprimindo listaConcatenada...\n");
    Imprime(ListaConcatenada);

    printf("\nImprimindo lista1...\n");
    Imprime(Lista1);
    Troca(&Lista1, 1, 4);
    printf("\nImprimindo lista1...\n");
    Imprime(Lista1);

    return 0;
}
