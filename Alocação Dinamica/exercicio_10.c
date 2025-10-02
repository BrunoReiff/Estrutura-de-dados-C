#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Fac¸a um programa que pergunte ao usu´ ario quantos valores ele deseja armazenar em um vetor de double, 
depois use a func¸˜ ao MALLOC para reservar (alocar) o espac¸o de mem´ oria de acordo com o especificado pelo usu´ ario. 
Esse vetor deve ter um tamanho maior ou igual a 10 elementos. 
Use este vetor dinˆ amico como um vetor comum, atribuindo aos 10 primeiros elementos do vetor valores aleat´ orios (usando a func¸˜ ao rand) entre 0 e 100. 
Exiba na tela os valores armazenados nos 10 primeiros elementos do vetor.
*/

void aloca(double **p, int tam)
{
    *p = (double *) malloc(tam * sizeof(double));

}

void preenche(double *vet)
{
    for (int i = 0; i < 10; i++)
    {
        vet[i] = rand()%101;
    }
    
}

void imprime(double *vet)
{
    printf("\nImprimindo vetor...\n(");
    for (int i = 0; i < 10; i++)
    {
        printf("%lf ", vet[i]);
    }
    printf(")");
}

int main()
{
    srand(time(NULL));

    double *vet = NULL;
    int tam;

    while (1==1)
    {
        printf("Digite o tamnho do vetor: ");
        scanf("%d", &tam);
        if (tam < 10)
        {
            printf("\nO tamanho deve ser maior que 10.\n");
        } else {
            break;
        }
        
    }

    aloca(&vet, tam);

    preenche(vet);
    imprime(vet);

    free(vet);

    return 0;
}