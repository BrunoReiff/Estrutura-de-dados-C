#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa que leia do usu´ario o tamanho de um vetor a ser lido e fac¸a a alocac¸˜ ao dinˆ amica de mem´ oria. 
Em seguida, leia do usu´ ario seus valores e imprima o vetor lido.
*/


int main()
{
    int *p, tam;

    printf("Qual o tamanho do array desejado? ");
    scanf("%d", &tam);

    p = (int *) malloc(tam * sizeof(int));
    if (p == NULL)
    {
        printf("Erro ao alocar memoria!!");
        exit(1);
    }

    for (int i = 0; i < tam; i++)
    {
        printf("Digite o valor %i do array: ", i + 1);
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < tam; i++)
    {
        printf("\nValor %i do array: %d", i + 1, p[i]);
    }
    

    free(p);
    return 0;
}