#define MAX 100

typedef struct {
   int inicio;
   int final;
   int vetor[MAX];
} Fila;

Fila* criaFila();

void liberaFila(Fila* f);

int estahVazia(Fila* f);

int estahCheia(Fila* f);

int enfileirar(Fila* f, int valor);

int desenfileirar(Fila* f, int* valor);

int desenfileirarDuplo(Fila* f, int* v1, int* v2);

void mostrarFila(Fila* f);
