#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 6

/*
Escreva um programa que leia primeiro os 6 n´umeros gerados pela loteria e depois os 6 n´umeros do seu bilhete. 
O programa ent˜ ao compara quantos n´umeros o jogador acertou. 
Emseguida, ele aloca espac¸o para um vetor de tamanho igual a quantidade de n´umeros corretos e guarda os n´umeros corretos nesse vetor. 
Finalmente, o programa exibe os n´umeros sorteados e os seus n´umeros corretos.
*/

void imprime(int *p)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}


void ler_bilhete(int *p)
{
    int flag = 0;
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o valor %d (0-20): ", i + 1);
        scanf("%d", &p[i]);
        flag = 0;
        while (flag == 0)
        {
            flag = 1;
            for (int j = 0; j < i; j++)
            {
                if (p[i] == p[j] || p[i] < 0 || p[i] > 20)
                {
                    flag = 0;
                    printf("O numero deve ser diferente e entre 0 e 20.\nDigite outro numero: ");
                    scanf("%d", &p[i]);
                    break;
                }
            }
        }   
    }
}

void gera_loteria(int *loteria)
{
    int flag = 0;
    for (int i = 0; i < tam; i++)
    {
        flag = 0;
        while (flag == 0)
        {
            flag = 1;
            loteria[i] = rand()%21;
            for(int j = 0; j < i; j++)
            {
                if (loteria[i] == loteria[j])
                {
                    flag = 0;
                    break;
                }  
            }
        } 
    }
    
}


int  *compara(int *loteria, int *bilhete, int *acertos)
{
    int *vet_acertos = NULL;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (loteria[i] == bilhete[j])
            {
                *acertos += 1;
                int *temp = realloc(vet_acertos, (*acertos) * sizeof(int));
                if (temp == NULL) {
                    printf("Erro ao realocar memoria!\n");
                    free(vet_acertos); 
                    exit(1);
                }
                vet_acertos = temp;
                vet_acertos[*acertos - 1] = loteria[i];
                break;
            }
        }
        
    } 
    return vet_acertos;
}

int main()
{
    srand(time(NULL));
    int loteria[tam] = {}, bilhete[tam] = {}, *vet_acertos = NULL, acertos = 0;

    gera_loteria(loteria);
    
    ler_bilhete(bilhete);

    vet_acertos = compara(loteria, bilhete, &acertos);

    printf("Os numeros da loteria sao: ");
    imprime(loteria);

    printf("\nOs numeros de acertos sao: %d", acertos);
    printf("\nOs numeros acertados foram: ");
    for (int i = 0; i < acertos; i++)
    {
        printf("%d ", vet_acertos[i]);
    }

    return 0;
}