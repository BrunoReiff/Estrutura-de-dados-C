#include <stdio.h>
#include <stdlib.h>
#include "lista_duplaencadeada.h"

int main()
{
    TipoLista ML;
    TipoItem MI;

    FLVazia(&ML);

    MI.Chave = 1;
    Insere_fim(&ML, MI);
    MI.Chave = 2;
    Insere_fim(&ML, MI);
    MI.Chave = 3;
    Insere_fim(&ML, MI);


    Imprime(ML);
    ImprimeInvertido(ML);

    MI.Chave = 10;
    Insere_enesimo(&ML, MI, 4);

    Imprime(ML);
    ImprimeInvertido(ML);

    Retira(&ML, &MI, 4);
    printf("\nItem retirado: %d", MI.Chave);

    Imprime(ML);
    ImprimeInvertido(ML);

    return 0;
}
