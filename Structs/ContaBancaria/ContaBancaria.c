// devo implementar a struct ContaBancaria e suas funcoes
#include <stdio.h>
#include "ContaBancaria.h"

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
