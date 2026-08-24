#include <stdio.h>
#include <string.h>
int main()
{
    struct Pessoa
    {
        char *nome;
        int idade;
        float peso;
        char *email;
        char cidade[50];
    };

    struct Pessoa p1;
    p1.nome = "João";
    p1.idade = 30;
    p1.peso = 70.5;
    p1.email = "joao@iffar.com";
    strcpy(p1.cidade, "Sao Borja");

    printf("Pessoa 1:\n");
    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Peso: %.2f\n", p1.peso);
    printf("Email: %s\n", p1.email);
    printf("Cidade: %s\n", p1.cidade);
    return 0;
}