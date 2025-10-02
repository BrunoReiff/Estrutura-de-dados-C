#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa que leia do usu´ ario o tamanho de um vetor a ser lido e fac¸a a alocac¸˜ ao dinˆ amica de mem´ oria. 
Em seguida, leia do usu´ ario seus valores e mostre quantos dos n´umeros s˜ ao pares e quantos s˜ ao ´ ımpares.
*/

int main()
{
    int *p, tam, par = 0, impar = 0;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tam);

    p = (int *) malloc(tam * sizeof(int));
    if (p == NULL)
    {
        printf("Erro ao alocar memoria!!");
        exit(1);
    }

    for(int i = 0; i < tam; i++)
    {
        printf("Digite o valor %i do array: ", i + 1);
        scanf("%d", &p[i]);

        if(p[i]%2 == 0)
            par++;
        else
            impar++;
    }


    printf("A quantidade de numeros pares digitados sao: %d\n", par);
    printf("A quantidade de numeros impares digitados sao: %d\n", impar);

    free(p);

    return 0;
}