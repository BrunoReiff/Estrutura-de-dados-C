#ifndef POLINOMIO_DINAMICO_H_INCLUDED
#define POLINOMIO_DINAMICO_H_INCLUDED

typedef int TipoPotencia;
typedef int TipoCoeficiente;
typedef int PosicaoLista;
typedef struct{
    TipoCoeficiente Coeficiente;
    TipoPotencia Potencia;
} TipoElemento;

typedef struct TipoPolinomio *TipoApontador;
typedef struct TipoPolinomio{
    TipoElemento Elemento;
    TipoApontador Prox;
} TipoPolinomio;

typedef struct{
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(TipoLista *Lista, TipoElemento Elemento);

void Insere_posicaoN(TipoLista *Lista, TipoElemento Elemento, PosicaoLista n);

void Retira(TipoLista *Lista, PosicaoLista n, TipoElemento *Elemento);

void Retira_potenciaX(TipoLista *Lista, TipoPotencia x, TipoElemento *Elemento);

void Retira_recursiva(TipoLista *Lista, PosicaoLista n, TipoElemento *Elemento);

void imprime(TipoLista Lista);

void imprime_recursiva(TipoApontador atual);

int Tamanho(TipoLista Lista);

void Calc_lstPolinomio(TipoLista Lista);

#endif // POLINOMIO_DINAMICO_H_INCLUDED
