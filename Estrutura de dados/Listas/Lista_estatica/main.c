#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

int main()
{
    TipoLista ML;
    TipoItem item;
    FLVazia(&ML);

    item.chave = 1;
    Insere_fim(&ML ,item);
    item.chave = 2;
    Insere_fim(&ML ,item);
    item.chave = 3;
    Insere_fim(&ML ,item);
    item.chave = 4;
    Insere_fim(&ML ,item);
    item.chave = 5;
    Insere_fim(&ML ,item);
    item.chave = 6;
    Insere_fim(&ML ,item);
    item.chave = 7;
    Insere_fim(&ML ,item);
    Imprime(ML);

    inverte(&ML);
    Imprime(ML);



    return 0;
}
