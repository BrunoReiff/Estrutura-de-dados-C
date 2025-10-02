#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Fac¸a um programa que receba do usu´ ario o tamanho de uma string e chame uma func¸˜ ao para alocar dinamicamente essa string. 
Em seguida, o usu´ ario dever´ a informar o conte´udo dessa string. O programa imprime a string sem suas vogais.
*/

void aloc_dim_string(char **p, int tam)
{
    *p = (char *) calloc(tam, sizeof(char));
    if (*p == NULL)
    {
        printf("Erro ao alocar memoria!!");
        exit(1);
    }
}

void imprime(char *p)
{
    while (*p != '\0')
    {
        if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'i' && *p != 'u' &&
            *p != 'A' && *p != 'E' && *p != 'I' && *p != 'O' && *p != 'U')
        {
            printf("%c", *p);
        }
        p++;
    }
}

int main()
{
    char *p = NULL;
    int tam;
    printf("Digite o tamanho da string: ");
    scanf("%d", &tam);
    getchar();

    aloc_dim_string(&p,tam);

    printf("Digite o conteudo da string com ateh %d de tamanho: ", tam);
    fgets(p, tam, stdin);

    p[strcspn(p, "\n")] = '\0';

    printf("String sem as vogais: ");
    imprime(p);

    free(p);

    return 0;
}