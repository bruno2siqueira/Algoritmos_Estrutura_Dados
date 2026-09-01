#include <stdio.h>
// definir a struct ContaBancaria
typedef struct ContaBancaria
{
    int numeroConta;
    float saldo;
} contaBancaria;

// tenho 4 assinatura de funcoes: Inicializa a conta, Deposita, Retira e Imprime os dados da conta

void AbrirConta(contaBancaria *conta, int numeroConta, float saldo);
void Depositar(contaBancaria *conta, float valor);
void Retirar(contaBancaria *conta, float valor);
void ImprimirDadosConta(contaBancaria conta);
