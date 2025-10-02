#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimens˜ oes definidas pelo usu´ ario e a leia. 
Em seguida, implemente uma func¸˜ ao que receba um valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso n˜ ao esteja na matriz.
*/

int **aloca_matriz(int l, int c)
{
    int **mat = (int **) malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++)
    {
        mat[i] = (int *) malloc(c * sizeof(int));
        for (int j = 0; j < c; j++)
        {
            mat[i][j] = rand()%21;
        }
        
    }
    return mat;
}

void imprime_mat(int **mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
}

int procura(int **mat, int l, int c, int chave)
{
    for (int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j ++)
        {
            if (mat[i][j] == chave)
            {
                return 1;
            }
            
        }
    }
    return 0;
}

int main()
{
    srand(time(NULL));

    int **mat = NULL, l, c, valor;

    printf("Digite o numero de linhas: ");
    scanf("%d", &l);
    printf("Digite o numero de colunas: ");
    scanf("%d", &c);

    mat = aloca_matriz(l, c);
    imprime_mat(mat, l, c);

    printf("Digite um valor (0-20): ");
    scanf("%d", &valor);
    if (procura(mat, l, c, valor) == 1)
    {
        printf("O valor esta na matriz.");
    } else{
        printf("O valor nao esta na matriz.");
    }
    
    free(mat);

    return 0;
}