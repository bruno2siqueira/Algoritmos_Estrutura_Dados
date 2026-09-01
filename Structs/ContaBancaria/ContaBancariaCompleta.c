#include <stdio.h>
// definir a struct ContaBancaria
typedef struct ContaBancaria
{
    int numeroConta;
    float saldo;
} contaBancaria;

void AbrirConta(contaBancaria *conta, int numeroConta, float saldo)
{
    conta->numeroConta = numeroConta;
    conta->saldo = saldo;
}
void Depositar(contaBancaria *conta, float valor)
{
    conta->saldo += valor;
}
void Retirar(contaBancaria *conta, float valor)
{
    conta->saldo -= valor;
}
void ImprimirDadosConta(contaBancaria conta)
{
    printf("Número da Conta: %d \n", conta.numeroConta);
    printf("Saldo: %.2f \n", conta.saldo);
}

int main()
{
    struct ContaBancaria conta1;
    AbrirConta(&conta1, 1, 1000.0);
    ImprimirDadosConta(conta1);
    Depositar(&conta1, 500.0);
    ImprimirDadosConta(conta1);
    Retirar(&conta1, 200.0);
    ImprimirDadosConta(conta1);
    return 0;
}