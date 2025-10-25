#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

int main()
{
    TipoFila MF, MF2;
    TipoItem MI;

    FFVazia(&MF);

    MI.Chave = 1;
    Enfileira(MI, &MF);
    MI.Chave = 2;
    Enfileira(MI, &MF);
    MI.Chave = 3;
    Enfileira(MI, &MF);
    MI.Chave = 4;
    Enfileira(MI, &MF);

    inverte(&MF, &MF2);

    MI.Chave = 1;
    Enfileira(MI, &MF);
    MI.Chave = 2;
    Enfileira(MI, &MF);
    MI.Chave = 3;
    Enfileira(MI, &MF);
    MI.Chave = 4;
    Enfileira(MI, &MF);

    imprime(MF);
    imprime(MF2);

    concatena(&MF, &MF2);

    imprime(MF);
    imprime(MF2);

    return 0;
}
