#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
    int *pi, *pj;

    pi = &x;
    pj = pi;

    printf("Endereco de x: %p\n", &x);
    printf("Endereco de *pi: %p\n", &pi);
    printf("Endereco de *pj: %p\n", &pj);

    printf("Conteudo de x: %d\n", x);
    printf("Conteudo de *pi: %p\n", pi);
    printf("Conteudo de *pj: %p\n", pj);

    printf("Valor do Endereço que *pi aponta: %d\n", *pi);
    printf("VAlor do Endereço que *pj aponta: %d\n", *pj);

    return 0;
}