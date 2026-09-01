#include <stdio.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float salarioBruto;
    float salarioLiquido;
} Pessoa;

float calcularSalarioLiquido(struct Pessoa p, float salarioBruto)
{
    return p.salarioLiquido = salarioBruto * 0.86;
}
void imprimePessoa(struct Pessoa p)
{
    printf("Nome: %s \n", p.nome);
    printf("Idade: %d \n", p.idade);
    printf("Salário Bruto: %.2f \n", p.salarioBruto);
    printf("Salário Líquido: %.2f \n", p.salarioLiquido);
}

int main()
{
    Pessoa p1;
    Pessoa p2;
    strcpy(p1.nome, "Cristian");
    p1.idade = 30;
    p1.salarioBruto = 5000.00;
    p1.salarioLiquido = calcularSalarioLiquido(p1, p1.salarioBruto);
    imprimePessoa(p1);

    p1.salarioLiquido = calcularSalarioLiquido(p2, p2.salarioBruto);
    imprimePessoa(p2);
}
