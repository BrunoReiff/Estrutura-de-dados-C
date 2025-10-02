#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Considere um cadastro de produtos de um estoque, com as seguintes informac¸˜ oes para cada produto: 
-C´ odigo de identificac¸˜ ao do produto: representado por um valor inteiro 
-Nome do produto: com at´ e 50 caracteres 
-Quantidade dispon´ ıvel no estoque: representado por um n´umero inteiro 
-Prec¸o de venda: representado por um valor real 
(a) Defina uma estrutura, denominada produto, que tenha os campos apropriados para guardar as informac¸˜ oes de um produto 
(b) Crie um conjunto de N produtos (N ´ e um valor fornecido pelo usu´ ario) e pec¸a ao usu´ ario para entrar com as informac¸˜ oes de cada produto 
(c) Encontre o produto com o maior prec¸o de venda 
(d) Encontre o produto com a maior quantidade dispon´ ıvel no estoque
*/

typedef struct 
{
    int codigo;
    char nome[50];
    int qnt_disponivel;
    float preco;
} produto;

void aloca_vetor(produto **p, int qnt)
{
    *p = (produto *) malloc(qnt * sizeof(produto));
    if (*p == NULL)
    {
        exit(1);
    }
    
}

void cadastra_produtos(produto *p, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("\n----------- Produto %i -----------\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &p[i].codigo);
        getchar();
        printf("Nome: ");
        fgets(p[i].nome, 50, stdin);
        printf("Quantidade disponivel: ");
        scanf("%d", &p[i].qnt_disponivel);
        printf("Preco: ");
        scanf("%f", &p[i].preco);
        printf("------------------------------------\n");
    }
    
}

void imprime_produtos(produto *p, int qnt)
{
    printf("\nImprimindo produtos...\n");
    for (int i = 0; i < qnt; i++)
    {
        printf("\n----------- Produto %i -----------\n", i + 1);
        printf("Codigo: %d\n", p[i].codigo);
        printf("Nome: %s", p[i].nome);
        printf("Quantidade disponivel: %d\n", p[i].qnt_disponivel);
        printf("Preco: %f\n", p[i].preco);
        printf("------------------------------------\n");
    }
}

int maior_preco(produto *p, int qnt)
{
    float maior;
    for (int i = 0; i < qnt; i++)
    {
        if (i == 0)
        {
            maior = p[i].preco;
        } else if(p[i].preco > maior)
        {
            maior = p[i].preco;
        }  
    }
    
    return maior;
}

void maior_qnt(produto *p, int qnt, char *produto_qnt)
{
    int maior;
    for (int i = 0; i < qnt; i++)
    {
        if (i == 0)
        {
            maior = p[i].qnt_disponivel;
            strcpy(produto_qnt, p[i].nome);
        } else if(p[i].qnt_disponivel > maior)
        {
            maior = p[i].qnt_disponivel;
            strcpy(produto_qnt, p[i].nome);
        }  
    }
}

int main()
{
    int qnt;
    produto *p = NULL;
    char produto_mais_qnt[50];

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &qnt);

    aloca_vetor(&p, qnt);
    cadastra_produtos(p, qnt);
    imprime_produtos(p, qnt);

    printf("\nO maior preco eh %d\n", maior_preco(p, qnt));
    maior_qnt(p, qnt, produto_mais_qnt);
    printf("\nO produto com maior quantida disponivel eh %s\n", produto_mais_qnt);


    free(p);

    return 0;
}