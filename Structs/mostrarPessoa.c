#include <stdio.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[50];
    int idade;
} Pessoa;

void imprimePessoa(struct Pessoa p)
{
    printf("Nome: %s \nIdade: %d\n", p.nome, p.idade);
}

int main()
{
    Pessoa p1;
    strcpy(p1.nome, "Joao Santos Dummont");
    p1.idade = 30;

    imprimePessoa(p1);
}
