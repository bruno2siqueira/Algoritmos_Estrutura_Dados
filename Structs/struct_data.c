#include "stdio.h"

// declarando a Struct Data

typedef struct Data{
    int dia, mes, ano;
};
void imprime(struct Data x){
    printf("%d-%d-%d\n", x.dia, x.mes, x.ano);
}
int main()
{
    struct Data d;
    d.dia = 10;
    d.mes = 12;
    d.ano = 1500;

    imprime(d);
    return 0;
}