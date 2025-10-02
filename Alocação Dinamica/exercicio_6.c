#include <stdio.h>
#include <stdlib.h>

/*
Fac¸a um programa que simule a mem´ oria de um computador: 
o usu´ ario ir´ a especificar o tamanho da mem´ oria, ou seja, quantos bytes ser˜ ao alocados do tipo inteiro. 
Para tanto, a mem´ oria solicitada deve ser um valor m´ultiplo do tamanho do tipo inteiro. 
Em seguida, o usu´ ario ter´ a 2 opc¸˜ oes: inserir um valor em uma determinada posic¸˜ ao ou consultar o valor contido em uma determinada posic¸˜ ao. 
A mem´ oria deve iniciar com todos os dados zerados.
*/

void inserir(int *p, int tam)
{
    int n = 0, x = 0;

    printf("Deseja inserir um numero em qual posicao (0 - %d): ", tam);
    scanf("%d", &n);
    while (1==1)
    {
        if (n > tam || n < 0)
        {
            printf("O numero deve ser entre 0 - %d.\n", tam);
            printf("Digite novamente: ");
            scanf("%d", &n);
        } else{
            break;
        } 
    }
    printf("Deseja inserir qual valor? ");
    scanf("%d", &x);
    p[n] = x;

}

void consultar(int *p, int tam)
{
    int n = 0;

    printf("Deseja consultar qual posicao (0 - %d): ", tam);
    scanf("%d", &n);
    while (1==1)
    {
        if (n > tam || n < 0)
        {
            printf("O numero deve ser entre 0 - %d.\n", tam);
            printf("Digite novamente: ");
            scanf("%d", &n);
        } else{
            break;
        } 
    }
    printf("A posicao %d contem o valor %d.\n", n, p[n]);
}


int main()
{
    int *p = NULL, tam = 0, x = 0;
    printf("Digite o tamanha da 'memoria', que seja multipla de 4, desejada: ");
    scanf("%d", &tam);
    while (1==1)
    {
        if (tam%4 == 0)
        {
            break;
        } else{
            printf("O numero deve ser multiplo de 4.\n");
            printf("Digite novamente: ");
            scanf("%d", &tam);
        } 
    }
    
    p = (int *) calloc(tam, sizeof(int));

    while (1==1)
    {
        printf("1 - inserir um valor.\n");
        printf("2 - consultar um valor.\n");
        printf("3 - sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            inserir(p, tam);
            break;
        case 2: 
            consultar(p, tam);
            break;
        case 3:
            break;
        default:
        printf("Digite uma opcao valida!!\n");
            break;
        }
        if (x == 3)
        {
            break;
        }
    }
    
    
    free(p);


    return 0;
}