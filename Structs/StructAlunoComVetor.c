#include <stdio.h>
#include <string.h>

typedef struct Aluno
{
    char nome[30];
    float matematica;
    float fisica;
    float media;
} Aluno;

int main()
{
    Aluno alunos[3];
    printf("Digite o nome, nota de matematica e nota de fisica dos alunos:\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%s %f %f", alunos[i].nome, &alunos[i].matematica, &alunos[i].fisica);
        // nesse caso, teremos que digita: nome nota_matematica nota_fisica
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Nome: %s \n Notas em Matematica = %.2f | Física = %.2f\n Media = %.2f \n", alunos[i].nome, alunos[i].matematica, alunos[i].fisica, (alunos[i].matematica + alunos[i].fisica) / 2);
        // nesse caso, teremos que digita: nome nota_matematica nota_fisica
    }

    return 0;
}