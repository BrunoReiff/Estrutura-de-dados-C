#include <stdio.h>
#include <stdlib.h>

/*
Construa um programa que leia o n´umero de linhas e de colunas de uma matriz de n´umeros reais, 
aloque espac¸o dinamicamente para esta e a inicialize com valores fornecidos pelo usu´ ario. 
Ao final, o programa dever´ a retornar a matriz na sa´ ıda padr˜ ao com layout apropriado.
*/


float **aloca_matriz(int l, int c)
{
    float **p = (float **) malloc(l * sizeof(float *));
    if (*p == NULL)
    {
        exit(1);
    }
    for(int i = 0; i < l; i++)
    {
        p[i] = (float *) malloc(c * sizeof(float));
        if (p == NULL)
        {
            exit(1);
        }
    }
    
    return p;
}

void preenche_matriz(float **mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
    
}

void imprime(float **mat, int l, int c)
{
    printf("\nImprimindo matriz.....\n");
    for (int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("[%.2f]\t", mat[i][j]);  
        }
        printf("\n");
    }
    
}


int main()
{
    float **mat = NULL;
    int l , c;
    printf("Digite o numero de linhas: ");
    scanf("%d", &l);
    printf("Digite o numero de colunas: ");
    scanf("%d", &c);

    mat = aloca_matriz(l, c);
    preenche_matriz(mat, l, c);
    imprime(mat, l, c);

    return 0;
}