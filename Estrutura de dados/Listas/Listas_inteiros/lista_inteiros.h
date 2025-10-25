#ifndef LISTA_INTEIROS_H_INCLUDED
#define LISTA_INTEIROS_H_INCLUDED

#define INICIOARRANJO 1
#define MAXTAM 10

typedef int TipoApontador;
typedef int TipoInteiro;

typedef struct
{
    TipoInteiro inteiro;
} TipoItem;

typedef struct
{
    TipoItem item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista_Inteiros;

void FLVazia(TipoLista_Inteiros *Lista);

void preenche(TipoLista_Inteiros *Lista);

void imprime(TipoLista_Inteiros Lista);

void imprime_recursivo(TipoLista_Inteiros Lista, TipoApontador Atual);

int qnt_pares(TipoLista_Inteiros Lista);

void geraLista_pares(TipoLista_Inteiros Lista, TipoLista_Inteiros *ListaGerada);

int calc_media(TipoLista_Inteiros Lista);

void ordena(TipoLista_Inteiros *Lista);

int verf_ordenacao(TipoLista_Inteiros Lista);

void inverte_gera(TipoLista_Inteiros *Lista, TipoLista_Inteiros *ListaInvertida);


#endif // LISTA_INTEIROS_H_INCLUDED
