#include <stdio.h>
#include <stdlib.h>


/*
Crie um programa que declare uma estrutura (registro) para o cadastro de alunos. 
(a) Dever˜ ao ser armazenados, para cada aluno[x]: matr´ ıcula, sobrenome (apenas um) e ano de nascimento. 
(b) Ao in´ ıcio do programa, o usu´ ario dever´ a informar o n´umero de alunos que ser˜ ao armazenados 
(c) O programa dever´ a alocar dinamicamente a quantidade necess´ aria de mem´ oria para armazenar os registros dos alunos. 
(d) O programa dever´ a pedir ao usu´ ario que entre com as informac¸˜ oes dos alunos. 
(e) Ao final, mostrar os dados armazenados e liberar a mem´ oria alocada.
*/

typedef struct
{
    int dia;
    int mes;
    int ano;
} nascimento;


typedef struct
{
    char nome[15];
    char sobrenome[20];
    char matricula[50];
    nascimento data;
} registro;

registro *aloca_aluno(registro *aluno, int qnt)
{
    registro *temp = NULL;

    temp = (registro *) realloc(aluno, qnt * sizeof(registro));
    if (temp == NULL)
    {
        return NULL;
    }
    
    return temp;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprime_alunos(registro *aluno, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("\n------ Aluno %i Registrado ------\n", i + 1);
        printf("Nome: %s", aluno[i].nome);
        printf("Sobrenome: %s", aluno[i].sobrenome);
        printf("Matricula: %s", aluno[i].matricula);
        printf("Data de Nascimento: %d/%d/%d\n", aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano);
        printf("-----------------------------------\n");
    } 
}

void registra_aluno(registro *aluno, int x)
{
    x--;
    printf("\n------ Area de Cadastro ------\n");
    getchar();
    printf("Nome: ");
    fgets(aluno[x].nome, 15, stdin);
    printf("Sobrenome: ");
    fgets(aluno[x].sobrenome, 20, stdin);
    printf("Matricula: ");
    fgets(aluno[x].matricula, 50, stdin);
    printf("Dia de nascimento: ");
    scanf("%d", &aluno[x].data.dia);
    printf("Mes de nascimento: ");
    scanf("%d", &aluno[x].data.mes);
    printf("Ano de nascimento: ");
    scanf("%d", &aluno[x].data.ano);
    printf("------ Cadastro Finalizado ------\n");
}

int main()
{
    int qnt = 0, escolha = 0;
    registro *aluno = NULL;
    while(escolha != 3){
        printf("1 - Registrar um aluno.\n");
        printf("2 - Ver alunos.\n");
        printf("3 - sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
        qnt++;
            aluno = aloca_aluno(aluno, qnt);
            if (aluno == NULL)
            {
                printf("\nErro ao cadastrar aluno!!\n");
            }
            registra_aluno(aluno, qnt);
            break;
        case 2:
            imprime_alunos(aluno, qnt);
            break;
        case 3:
            break;
        default:
            printf("\nSelecione uma opcao valida!!\n\n");
        }
    }

    free(aluno);

    return 0;
}