#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

#define INICIOARRANJO 1
#define MAXTAM 10

typedef int TipoApontador;
typedef int TipoChave;
typedef int Posicao;

typedef struct
{
    TipoChave chave;
} TipoItem;

typedef struct
{
    TipoItem Item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere_fim(TipoLista *Lista, TipoItem Item);

void Insere_enesimo(TipoLista *Lista, Posicao n, TipoItem Item);

void Retira_fim(TipoLista *Lista, TipoItem *Item);

void Retira_enesimo(TipoLista *Lista, Posicao n, TipoItem *Item);

void LocalizaItem(TipoLista Lista, TipoChave Chave);

void Combina(TipoLista Lista1, TipoLista Lista2, TipoLista *ListaCombinada);

void Particiona(TipoLista Lista, Posicao n, TipoLista *ListaParticionada1, TipoLista *ListaParticionada2);

void Copia(TipoLista ListaOrigem, TipoLista *ListaDestino);

void ordena_crescente(TipoLista *Lista);

void ordena_decrescente(TipoLista *Lista);

void inverte(TipoLista *Lista);

void verifica_ordenacao(TipoLista Lista);

void Imprime(TipoLista Lista);

#endif // LISTA_ESTATICA_H_INCLUDED
