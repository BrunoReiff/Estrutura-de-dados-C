#ifndef LISTA_DUPLAENCADEADA_H_INCLUDED
#define LISTA_DUPLAENCADEADA_H_INCLUDED

typedef  int  TipoChave;
typedef int Posicao;
typedef  struct
{
    TipoChave Chave;
}  TipoItem;
typedef  struct  TipoCelula *TipoApontador;
typedef  struct TipoCelula{
    TipoItem  Item;
    TipoApontador  Prox,Ant;
}  TipoCelula;
typedef  struct
{
    TipoApontador  Primeiro,  Ultimo;
}  TipoLista ;

void FLVazia(TipoLista  *Lista );
int  Vazia(TipoLista Lista);
void Insere_fim(TipoLista *Lista, TipoItem Item);
void Insere_enesimo(TipoLista *Lista, TipoItem Item, Posicao n);
void Retira(TipoLista *Lista, TipoItem *Item, Posicao n);
void Imprime(TipoLista Lista);
void ImprimeInvertido(TipoLista Lista);

#endif // LISTA_DUPLAENCADEADA_H_INCLUDED
