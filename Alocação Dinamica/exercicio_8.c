#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa para armazenar em mem´ oria um vetor de dados contendo 1500 valores do tipo int, 
usando a func¸˜ ao de alocac¸˜ ao dinˆ amica de mem´ oria CALLOC: 
(a) Fac¸a um loop e verifique se o vetor cont´ em realmente os 1500 valores inicializados com zero (conte os 1500 zeros do vetor). 
(b) Atribua para cada elemento do vetor o valor do seu ´ ındice junto a este vetor. 
(c) Exibir na tela os 10 primeiros e os 10 ´ultimos elementos do vetor.
*/

int main()
{
    int *vet;
    vet = (int *) calloc(1500, sizeof(int));

    for (int i = 0; i < 1500; i++)
    {
        if (vet[i] != 0)
        {
            printf("Break!!!");
            break;
        } else{
            vet[i] = i;
        }
    }
    printf("10 primeiros elementos sao: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d - %d\n", i, vet[i]);
    }
    printf("\n10 ultimos elementos sao: \n");
    for (int i = 1500 - 1; i > 1500 - 11; i--)
    {
        printf("%d - %d\n", i, vet[i]);
    }
    
    free(vet);

    return 0;
}