#include <stdio.h>
#include "ContaBancaria.h"

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
