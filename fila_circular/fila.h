#define MAX 5

typedef struct {
   int inicio;
   int final;
   int tamanho;
   int vetor[MAX];
} Fila;

Fila* criaFila();

void liberaFila(Fila* f);

int estahVazia(Fila* f);

int estahCheia(Fila* f);

int enfileirar(Fila* f, int valor);

int desenfileirar(Fila* f, int* valor);

void mostrarFila(Fila* f);
