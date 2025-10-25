#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_estatica.h"


int main()
{
    TipoPilha MP;
    TipoItem MI;

    FPVazia(&MP);

    char str[10];
    strcpy(str, "arara");
    printf("\n%s\n", str);

    if(verf_palindromo(str))
    {
        printf("\nPALINDROMO!\n");
    } else
    {
        printf("\nNAO PALINDROMO");
    }


    return 0;
}
