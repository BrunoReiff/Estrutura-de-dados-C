#include "pilha_estatica.h"

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = 0;
}

int Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == 0);
}

void Empilha(TipoPilha *Pilha, TipoItem Item)
{
    if(Pilha->Topo == MAXTAM)
    {
        printf("\nErro: Pilha esta cheia!\n");
        return;
    }
    Pilha->Topo++;
    Pilha->Item[Pilha->Topo - 1] = Item;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{
    if(Vazia(*Pilha))
    {
        printf("\nErro: Pilha esta vazia!\n");
        return;
    }
    Pilha->Topo--;
    *Item = Pilha->Item[Pilha->Topo];
}

int Tamanho(TipoPilha Pilha)
{
    return Pilha.Topo;
}

int Cheia(TipoPilha Pilha)
{
    return (Pilha.Topo == MAXTAM);
}

int verf_expressoes(TipoPilha *Pilha)
{
    TipoItem aux;
    int flag = 0;

    while(!Vazia(*Pilha))
    {
        Desempilha(Pilha, &aux);
        if(aux.Chave != ')' || aux.Chave != '(')
        {
            printf("\nErro: A pilha soh deve conter parenteses!\n");
            return 0;
        }
        if(aux.Chave == ')')
        {
            flag++;
        } else if(aux.Chave == '(' && flag == 0)
        {
            return 0;
        } else if(aux.Chave == '(' && flag > 0)
        {
            flag--;
        }
    }
    if(flag > 0)
    {
        return 0;
    }
}

int verf_palindromo(char *palavra)
{
    TipoPilha Pilha;
    TipoItem Item;
    char strInvertida[strlen(palavra)];

    FPVazia(&Pilha);

    for(int i = 0; i < strlen(palavra); i++)
    {
        Item.Chave = palavra[i];
        Empilha(&Pilha, Item);
    }
    imprime(Pilha);
    int j = 0;
    for(int i = Pilha.Topo - 1; i >= 0; i--)
    {
        Desempilha(&Pilha, &Item);
        strInvertida[j] = Item.Chave;
        j++;
    }
    printf("-> %s\n", palavra);
    printf("-> %s\n", strInvertida);

    if(strcmp(palavra, strInvertida) == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}


void imprime(TipoPilha Pilha)
{
    if(Vazia(Pilha))
    {
        printf("\nErro: Pilha esta vazia!\n");
        return;
    }
    printf("\nImprimindo pilha...\n[ ");
    for(int i = Pilha.Topo - 1; i >= 0; i--)
    {
        printf("%c ", Pilha.Item[i].Chave);
    }
    printf("]\n");
}

