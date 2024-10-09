#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num; // variavel inteira
    num = 7; // atribui valor a num

    printf("Endereco de num: %p\n", &num);                // mostra o endereco de memoria ocupado por num
    printf("Valor de num: %d\n", num);                    // mostra o conteudo de num
    printf("Tamanho em bytes de num: %d\n", sizeof(num)); // mostra o tamanho de num

    int *p = &num; // nao esquecer que temos que colocar o "&"

    printf("Endereco de p: %p\n", &p);                           // mostra o endereco de memoria ocupado por p
    printf("Valor do endereço onde p esta apontando: %d\n", *p); // mostra o conteudo de p
    printf("Endereco que p esta apontando: %p\n", p);            // mostrar o endereco em Hexa
    printf("Tamanho em bytes de p: %d\n", sizeof((int)p));       // mostra o tamanho de p
}