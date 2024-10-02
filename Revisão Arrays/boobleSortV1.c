#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam); // tamanho do vetor tam = 5 v[tam]
    int v[tam];
    srand(time(NULL));

    for (int a = 0; a < tam; a++) // preenchendo o vetor
    {
        v[a] = 1 + (rand() % 15);
    }
    for (int a = 0; a < tam; a++)
    {
        printf("v[%d] = %d\n", a, v[a]);
    }

    printf("Vetor Rodenado com Bubble Sort\n");
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam - 1; j++)
        {
            if (v[j] > v[j + 1])
            { // precisamos testar se o elemento da posição j > j+1
                int aux;
                aux = v[j + 1];  // aux recebe o menor
                v[j + 1] = v[j]; // ele posição maior recebe o maior element
                v[j] = aux;      // posicao atual, recebe o menor valor
            }
        }
    }
    for (int a = 0; a < tam; a++)
    {
        printf("v[%d] = %d\n", a, v[a]);
    }

    return 0;
}
