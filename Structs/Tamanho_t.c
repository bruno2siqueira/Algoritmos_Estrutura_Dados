#include <stdio.h>
#include <string.h>

typedef struct Tamanho
{
    int t;
    char nome[50];
} Tamanho;

Tamanho define(char *nome, int valor)
{
    Tamanho x;
    strcpy(x.nome, nome);
    x.t = valor;
    return x;
}

int main()
{
    Tamanho t1 = define("Comum", 12);
    printf("Tamanho: %d - Nome: %s\n", t1.t, t1.nome);
}
