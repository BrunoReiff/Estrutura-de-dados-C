#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_dinamica.h"

int main()
{
    TipoPilha MP;
    TipoItem MI;
    FPVazia(&MP);

    MI.Chave = '(';
    Empilha(MI, &MP);
    MI.Chave = '(';
    Empilha(MI, &MP);
    MI.Chave = ')';
    Empilha(MI, &MP);
    MI.Chave = ')';
    Empilha(MI, &MP);
    MI.Chave = ')';
    Empilha(MI, &MP);

    if(verf_expressoes(&MP))
    {
        printf("\nEh uma expressao bem formada!\n");
    } else
    {
        printf("\nNao eh uma expressao bem formada!\n");
    }

    return 0;
}
