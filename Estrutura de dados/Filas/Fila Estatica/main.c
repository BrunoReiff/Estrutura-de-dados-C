#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"


int main()
{
    TipoFila MF;
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

    Desenfileira(&MF, &MI);
    Desenfileira(&MF, &MI);

    MI.Chave = 1;
    Enfileira(MI, &MF);
    MI.Chave = 2;
    Enfileira(MI, &MF);


    Imprime(MF);

    Inverte(&MF);
    printf("\nImprimindo fila invertida\n");
    Imprime(MF);



    return 0;
}
