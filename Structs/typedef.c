#include <stdio.h>
int main()
{
    typedef struct Data
    {
        int dia;
        int mes;
        int ano;
    } Data;

    // funcao void que recebe uma struct Data como parametro
    void mostrarData(struct Data d)
    {
        printf("Data: %d/%d/%d \n", d.dia, d.mes, d.ano);
    }

    Data d1; // d1 é do tipo Data
    d1.ano = 2024;
    d1.mes = 6;
    d1.dia = 6;

    mostrarData(d1);
}