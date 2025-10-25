#ifndef PILHA_ESTATICA_H_INCLUDED
#define PILHA_ESTATICA_H_INCLUDED

#define MAXTAM 10

typedef int TipoApontador;
typedef char TipoChave;
typedef struct{
    TipoChave Chave;
} TipoItem;

typedef struct{
    TipoItem Item [MAXTAM];
    TipoApontador Topo;
} TipoPilha;

void FPVazia(TipoPilha *Pilha);

int Vazia(TipoPilha Pilha);

void Empilha(TipoPilha *Pilha, TipoItem Item);

void Desempilha(TipoPilha *Pilha, TipoItem *Item);

int Tamanho(TipoPilha Pilha);

int Cheia(TipoPilha Pilha);

void imprime(TipoPilha Pilha);

int verf_expressoes(TipoPilha *Pilha);

int verf_palindromo(char *palavra);

#endif // PILHA_ESTATICA_H_INCLUDED
