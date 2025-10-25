#ifndef FILA_ESTATICA_H_INCLUDED
#define FILA_ESTATICA_H_INCLUDED

#define MAXTAM 5

typedef int TipoApontador;
typedef int TipoChave;

typedef struct
{
    TipoChave Chave;
} TipoItem;
typedef struct
{
    TipoItem Item[MAXTAM];
    TipoApontador Frente, Tras;
} TipoFila ;

void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira (TipoItem x, TipoFila *Fila);
void Desenfileira (TipoFila *Fila, TipoItem *Item);
void Imprime(TipoFila Fila);
void Inverte(TipoFila *Fila);



#endif // FILA_ESTATICA_H_INCLUDED
