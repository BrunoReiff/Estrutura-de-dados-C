#include <stdio.h>
#include <stdlib.h>
#include "lista_inteiros.h"

/*
11. Considere uma lista contendo n´umeros inteiros positivos. Fac¸a uma func¸˜ ao que retorne quantos n´umeros pares existem na lista.
12. Considere uma lista contendo n´umeros inteiros positivos. Fac¸a uma func¸˜ ao que retorne uma nova lista contendo apenas os n´umeros pares da lista.
13. Considere uma lista contendo n´umeros inteiros positivos. Fac¸a uma func¸˜ ao que retorne a m´ edia da lista.
*/
int main()
{
    TipoLista_Inteiros ML, ListaPares, ListaInvertida;
    FLVazia(&ML);

    preenche(&ML);
    imprime(ML);

    //printf("Qnt de par: %d\n",qnt_pares(ML));

    //geraLista_pares(ML, &ListaPares);
    //imprime(ListaPares);

    //printf("\nMedia da Lista: %d\n", calc_media(ML));

    ordena(&ML);
    imprime(ML);

    inverte(&ML, &ListaInvertida);
    printf("\nImprimindo Lista Recursivamente...\n");
    imprime_recursivo(ListaInvertida, ListaInvertida.Primeiro - 1);

    if(verf_ordenacao(ListaInvertida))
    {
        printf("\nA lista esta ordenada!\n");
    } else {
        printf("\nA lista nao esta ordenada!\n");
    }

    return 0;
}
