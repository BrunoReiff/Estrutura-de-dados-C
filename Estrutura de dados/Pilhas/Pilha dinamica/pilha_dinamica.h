#ifndef PILHA_DINAMICA_H_INCLUDED
#define PILHA_DINAMICA_H_INCLUDED

typedef char TipoChave;
typedef struct
{
    TipoChave Chave;
} TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct
{
    TipoApontador Fundo, Topo;
    int Tamanho;
} TipoPilha ;

void FPVazia(TipoPilha *Pilha);
int Vazia( TipoPilha Pilha);
void Empilha(TipoItem x, TipoPilha *Pilha);
void Desempilha(TipoPilha *Pilha, TipoItem *Item);
int Tamanho(TipoPilha Pilha);

void inverte_palavra(char *palavra);
int verf_palindromo(char *palavra);
int verf_expressoes(TipoPilha *Pilha);




#endif // PILHA_DINAMICA_H_INCLUDED
