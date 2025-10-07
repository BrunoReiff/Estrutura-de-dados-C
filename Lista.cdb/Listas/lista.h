#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define INICIOARRANJO 1
#define MAXTAM 10

typedef int TipoApontador;
typedef int TipoChave;

typedef struct
{
    TipoChave chave;
} TipoItem;

typedef struct
{
    TipoItem item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(TipoItem x, TipoLista *Lista);

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);

void Retira_n_elementos(TipoLista *Lista, int n);

void Imprime(TipoLista Lista);

void Localiza(TipoLista Lista, TipoApontador n);

void Concatena(TipoLista *Lista1, TipoLista *Lista2, TipoLista *ListaResultado);

void Copia(TipoLista *ListaOrigem, TipoLista *ListaDest);

void Ordena(TipoLista *Lista);

void pesquisa_item(TipoLista Lista, TipoChave x);

void particiona(TipoLista *Lista, TipoApontador n, TipoLista *ListaParticionada);

void Troca(TipoLista *Lista1, TipoApontador x, TipoApontador y);


#endif // LISTA_H_INCLUDED

