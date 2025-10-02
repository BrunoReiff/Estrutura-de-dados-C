#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa que leia uma quantidade qualquer de n´umeros armazenando-os na mem´ oria e pare a leitura quando o usu´ ario entrar um n´umero negativo. 
Em seguida, imprima o vetor lido. Use a func¸˜ ao REALLOC.
*/

int *vetor_dinamico(int *p, int qnt)
{
    int *p1 = (int *) realloc(p, qnt * sizeof(int));

    return p1; 
}

int main()
{
    int *vet = NULL, num = 0, qnt = 0;
    while (1 == 1)
    {

        printf("Digite um numero: ");
        scanf("%d", &num);
        if (num < 0)
        {
            break;
        }

        qnt++;    
        int *temp = vetor_dinamico(vet, qnt);
        if(temp == NULL)
        {
            printf("Falha ao alocar memoria!");
            free(vet);
            exit(1);
        }

        vet = temp;

        vet[qnt - 1] = num;
    }

    printf("Vetor gerado: ");
    for (int i = 0; i < qnt; i++)
    {
        printf("%d ", vet[i]);
    }
    
    free(vet);

    return 0;
}