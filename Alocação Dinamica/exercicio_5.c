#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa que leia um n´umero N e: 
-Crie dinamicamente e leia um vetor de inteiro de N posic¸˜ oes; 
-Leia um n´umero inteiro X e conte e mostre os m´ultiplos desse n´umero que existem no vetor.
*/

void aloc_dim_array(int **p, int tam)
{
    *p = (int *) malloc(tam * sizeof(int));
    if(*p == NULL)
    {
        printf("Erro na alocacao de memoria!!");
        exit(1);
    }
}

void ler_array(int *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o valor %i do array: ", i + 1);
        scanf("%d", &p[i]);
    }
}

void multiplos(int *p, int tam, int x)
{
    for (int i = 0; i < tam; i++)
    {
        if (p[i]%x == 0)
        {
            printf("O numero %d eh multiplo de %d\n", p[i], x);
        }  
    }
}

int main()
{
    int *p = NULL, tam, x;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tam);

    aloc_dim_array(&p, tam); 
    ler_array(p, tam);

    printf("Digite um numero: ");
    scanf("%d", &x);
    multiplos(p, tam, x);

    free(p);

    return 0;
}