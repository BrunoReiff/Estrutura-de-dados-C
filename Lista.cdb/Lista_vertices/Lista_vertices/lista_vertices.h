#ifndef LISTA_VERTICES_H_INCLUDED
#define LISTA_VERTICES_H_INCLUDED
#include <stdbool.h>

#define INICIOARRANJO 1
#define MAXTAM 10

typedef int TipoApontador;

typedef struct
{
   float x;
   float y;
} TipoPonto;

typedef struct
{
    TipoPonto Ponto[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista_Vertice;

void FLVazia(TipoLista_Vertice *Lista);

bool vazia(TipoLista_Vertice Lista);

void imprime(TipoLista_Vertice Lista);

void insere(TipoLista_Vertice *Lista, TipoPonto Ponto);

void retirar(TipoLista_Vertice *Lista, TipoApontador n, TipoPonto *Ponto);



#endif // LISTA_VERTICES_H_INCLUDED
