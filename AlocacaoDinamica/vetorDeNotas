#include <stdio.h>
#include <stdlib.h>

int main() {
    float *v; /* vetor de notas */
    int i; /* contador */
    int n; /* número de elementos do vetor */

    /* peço o número de notas */
    printf("Qual o número de notas? ");
    scanf("%d", &n);

    /* aloca dinamicamente o vetor */
    v = (float *)malloc(n * sizeof(float));

    /* verifica se houve sucesso na alocação */
    if (v == NULL) {
        printf("Memória insuficiente para alocar o vetor.\n");
        return 1; /* encerra o programa se não houver memória */
    }

    /* lê as notas */
    for (i = 0; i < n; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &v[i]);
    }

    /* imprime as notas */
    printf("As notas são:\n");
    for (i = 0; i < n; i++) {
        printf("Nota %d: %.2f\n", i + 1, v[i]);
    }

    /* libera a memória alocada */
    free(v);

    return 0;
}
