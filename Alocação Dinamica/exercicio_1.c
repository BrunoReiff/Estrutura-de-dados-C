#include <stdio.h>
#include <stdlib.h>

/*
1. Crie um programa que: 
(a) Aloque dinamicamente um array de 5 n´umeros inteiros, 
(b) Pec¸a para o usu´ ario digitar os 5 n´umeros no espac¸o alocado, 
(c) Mostre na tela os 5 n´umeros, 
(d) Libere a mem´ oria alocada.
*/

int main()
{
    int *dim_array;

    dim_array = (int *) malloc(5 * sizeof(int));
    if (dim_array == NULL)
    {
        printf("Falha na alocacao de memoria!");
        exit(1);
    }
    

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o valor %i do array: ", i + 1);
        scanf("%d", &dim_array[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nValor %i do array: %d", i + 1, dim_array[i]);
    }
    
    free(dim_array);

    return 0;
}