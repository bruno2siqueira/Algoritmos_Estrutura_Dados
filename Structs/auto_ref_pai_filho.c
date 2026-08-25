#include <stdio.h>
#include <string.h>
int main()
{
    typedef struct Pessoa
    {
        char nome[50];
        int idade;
        struct Pessoa *pai;
    } Pessoa;

    Pessoa Joao, Pedro;
    strcpy(Joao.nome, "Joao");
    Joao.idade = 30;
    strcpy(Pedro.nome, "Pedro");
    Pedro.idade = 65;
    Joao.pai = &Pedro; // Joao é filho de Pedro
    printf("Nome: %s, Idade: %d, Pai: %s, tem %d anos de idade \n", Joao.nome, Joao.idade, Joao.pai->nome, Joao.pai->idade);
    printf("Nome: %s, Idade: %d\n", Pedro.nome, Pedro.idade);

    return 0;
}