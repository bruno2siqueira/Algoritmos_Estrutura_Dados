#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Registro
{
    char nome[100];
    int idade;
    float salario;
    char sexo;
} Registro;

int main()
{
    Registro Pessoas[3]; // Pessoa é uma vari'avel do tipo Registro

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]s", Pessoas[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &Pessoas[i].idade);
        printf("Digite o salario: ");
        scanf("%f", &Pessoas[i].salario);
        printf("Digite o sexo: ");
        scanf(" %c", &Pessoas[i].sexo);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d - Nome %s, Idade: %d, Salario: %.2f e Sexo: %c\n", i + 1, Pessoas[i].nome, Pessoas[i].idade, Pessoas[i].salario, Pessoas[i].sexo);
    }
    return 0;
}
