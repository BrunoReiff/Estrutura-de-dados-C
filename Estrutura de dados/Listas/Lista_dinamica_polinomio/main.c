#include <stdio.h>
#include <stdlib.h>
#include "polinomio_dinamico.h"

int main()
{
    TipoLista ML;
    TipoElemento ME;
    FLVazia(&ML);

    ME.Coeficiente = 2;
    ME.Potencia = 3;
    Insere(&ML, ME);
    ME.Coeficiente = 4;
    ME.Potencia = 2;
    Insere(&ML, ME);
    ME.Coeficiente = 6;
    ME.Potencia = 2;
    Insere(&ML, ME);
    ME.Coeficiente = 8;
    ME.Potencia = 2;
    Insere(&ML, ME);

    imprime(ML);

    ME.Coeficiente = 5;
    ME.Potencia = 2;
    int q = Tamanho(ML);
    printf("Tamanho: %d",q);

    Insere_posicaoN(&ML, ME, 6);
    printf("\nInserindo na posicao\n");
    imprime(ML);

    Retira(&ML, 2, &ME);
    printf("\nRetirando na posicao\n");
    imprime_recursiva(ML.Primeiro->Prox);



    return 0;
}
