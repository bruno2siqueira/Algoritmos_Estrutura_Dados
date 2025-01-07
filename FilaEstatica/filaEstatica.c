#include <stdio.h>
#define MAX 10

typedef struct fila
{
    int inicio;
    int fim;
    int vetor[MAX];
} Fila;

// Inicializa a fila
Fila inicializarFila()
{
    Fila q;
    q.inicio = 0;
    q.fim = 0;
    return q;
}

// Verifica se a fila está vazia
int estahVazia(Fila q)
{
    return q.inicio == q.fim;
}

// Verifica se a fila está cheia
int estahCheia(Fila q)
{
    return ((q.fim + 1) % MAX) == q.inicio;
}

// Enfileira um elemento na fila
void enfileirar(Fila *q, int valor, int *erro)
{
    if (estahCheia(*q))
    {
        *erro = 1; // Fila cheia
    }
    else
    {
        q->vetor[q->fim] = valor;
        q->fim = (q->fim + 1) % MAX;
        *erro = 0; // Sucesso
    }
}

// Desenfileira um elemento da fila
int desenfileirar(Fila *q, int *erro)
{
    if (estahVazia(*q))
    {
        *erro = 1; // Fila vazia
        return -1;
    }
    else
    {
        int valor = q->vetor[q->inicio];
        q->inicio = (q->inicio + 1) % MAX;
        *erro = 0; // Sucesso
        return valor;
    }
}

// Função para mostrar o conteúdo da fila
void mostraFila(Fila q)
{
    int i = q.inicio;
    printf("\nFila: ");
    while (i != q.fim)
    {
        printf("%d ", q.vetor[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Fila q = inicializarFila();
    int erro, i;

    // Enfileirando elementos
    for (i = 1; i <= 10; i++)
    {
        enfileirar(&q, i, &erro);
        if (erro)
        {
            printf("Fila Cheia! Não foi possível enfileirar %d\n", i);
        }
    }

    mostraFila(q);

    // Desenfileirando elementos
    for (i = 1; i <= 5; i++)
    {
        int valor = desenfileirar(&q, &erro);
        if (!erro)
        {
            printf("Desenfileirado: %d\n", valor);
        }
        else
        {
            printf("Fila Vazia! Não foi possível desenfileirar\n");
        }
    }

    mostraFila(q);

    return 0;
}
