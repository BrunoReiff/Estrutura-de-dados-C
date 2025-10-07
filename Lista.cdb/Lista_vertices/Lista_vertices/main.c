#include <stdio.h>
#include <stdlib.h>
#include "lista_vertices.h"

/*
Um pol´ ıgono geom´ etrico pode ser considerado como uma lista de v´ ertices.
Para dese nhar tal pol´ ıgono, basta trac¸ar uma reta ligando v´ ertices adjacentes.
Projete um TAD para armazenar esse pol´ ıgono (defina as operac¸˜ oes necess´ arias).
Considere a necessidade de desenhar um pol´ ıgono, eliminar arestas e incluir novas arestas.

vi = (xi, yi)
*/

int main()
{
    TipoLista_Vertice ML;
    FLVazia(&ML);

    TipoPonto MP;

    MP.x = 1.1;
    MP.y = 1.1;
    insere(&ML, MP);
    MP.x = 2.1;
    MP.y = 2.1;
    insere(&ML, MP);
    MP.x = 3.1;
    MP.y = 3.1;
    insere(&ML, MP);

    imprime(ML);

    retirar(&ML, 2, &MP);
    imprime(ML);


    return 0;
}
