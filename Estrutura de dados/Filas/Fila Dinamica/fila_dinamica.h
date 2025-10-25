#ifndef FILA_DINAMICA_H_INCLUDED
#define FILA_DINAMICA_H_INCLUDED

typedef struct TipoCelula *TipoApontador;
typedef int TipoChave;
typedef struct TipoItem
{
    TipoChave Chave;
} TipoItem;

typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila
{
    TipoApontador Frente, Tras;
} TipoFila ;

void FFVazia( TipoFila *Fila);
int Vazia(TipoFila Fila );
void Enfileira (TipoItem x, TipoFila *Fila);
void Desenfileira (TipoFila *Fila, TipoItem *Item);
int tamanho(TipoFila Fila);
void inverte(TipoFila *FilaSrc, TipoFila *FilaDest);
void concatena(TipoFila *Fila1, TipoFila *Fila2);
void imprime(TipoFila Fila);


#endif // FILA_DINAMICA_H_INCLUDED
