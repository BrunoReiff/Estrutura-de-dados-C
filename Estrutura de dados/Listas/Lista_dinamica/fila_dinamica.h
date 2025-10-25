#ifndef FILA_DINAMICA_H_INCLUDED
#define FILA_DINAMICA_H_INCLUDED
#include <stdbool.h>

typedef int TipoChave;
typedef int Posicao;

typedef struct{
    TipoChave Chave;
} TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct{
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void insere_fim(TipoLista *Lista, TipoItem Item);

void insere_enesimo(TipoLista *Lista, Posicao n, TipoItem);

void retira(TipoLista *Lista, Posicao n, TipoItem *Item);

void inverte(TipoLista *Lista, TipoLista *ListaInvertida);

int tamanho_rec(TipoLista Lista, TipoApontador Primeiro);

bool verf_identidade(TipoApontador Primeiro, TipoApontador Primeiro2);

void imprime(TipoLista Lista);

void imprime_rec(TipoApontador Atual);

#endif // FILA_DINAMICA_H_INCLUDED
