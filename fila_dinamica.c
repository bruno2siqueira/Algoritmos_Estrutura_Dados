#include <stdlib.h>
#include <stdio.h>
#define MAX 100

// TAD da Fila
typedef struct{
   int inicio; 		// indice para INICIO da fila
   int final;  		// indice para FIM da fila
   int vetor[MAX]; 	// vetor para armazenar os valores da fila
}Fila; 				// nome da Estrutura

// M�todo que cria a Fila
/* Coment�rios:
  c.1 - Deve-se criar um ponteiro do tipo FILA para que seja alocado em mem�ria (dinamicamente).
	    ou seja, so se aloca dinamicamente ponteiro, por isso, foi criado um ponteiro do tipo FILA
  c.2 - Como *f � um ponteiro do tipo FILA, ele faz uma requisi��o de aloca��o de mem�ria para o tamanho informado.
		A fun��o malloc( ) aloca size bytes e retorna um ponteiro para a mem�ria alocada. A mem�ria n�o � inicializada.
  c.3 - Como � uma FILA, temos dois indices que controlam o INICIO e o FIM da Fila. Assim, ambos devem ser inicializados
		Nesse algor�tmo, ambos s�o apontados para a ZERO (0)
*/
Fila* criaFila() {

	Fila* f; // c.1

 	f = malloc(sizeof(Fila)); // c.2

	 // c.3
	f->inicio = 0; //(*f).inicio = 0;
	f->final  = 0; //(*f).final = 0;

	return f;
}

// M�todo libera Fila
/* Coment�rios:
  c.4 - o m�todo recebe como par�metro um ponteiro do tipo da estrutura, ou seja, Fila* f.
  c.5 - o conte�do da Fila criada deve ser liberada. Assim, o m�todo free � invocado.
	    A fun��o free( ) libera o espa�o de mem�ria apontado pelo ponteiro Fila *f.
*/
void liberaFila(Fila* f) {    // c.4
	free(f);  // c.5
	f = NULL; // aponta f (que continua existindo) para NULL
}

// M�todo estahVazia
/* Coment�rios:
  c.6 - o m�todo recebe como par�metro um ponteiro do tipo da estrutura, ou seja, Fila* f.
  c.7 - retorna 1 (verdadeiro) se os ponteiros inicio e final estiverem no mesmo lugar (inicio e final == 0).
*/
int estahVazia(Fila* f) {
	if (f->inicio == f->final)
	   return 1; //Fila vazia
	else
	   return 0;
}

// M�todo estahCheia
/* Coment�rios:
  c.8 - o m�todo recebe como par�metro um ponteiro do tipo da estrutura, ou seja, Fila* f.
  c.9 - retorna 1 (verdadeiro) se o ponteiro final estiver no limite da fila (final == MAX).
*/
int estahCheia(Fila* f) {
	if (f->final == MAX)
	   return 1; //fila cheia
	else
	   return 0;
}

// M�todo enfilera
/* Coment�rios:
  c.10 - o m�todo recebe como par�metro um ponteiro do tipo da estrutura, ou seja, Fila* f e o int valor a ser enfileirado.
        Mas, deve verificar se a fila estahCheia. Se sim, n�o poder� enfileirar.
  c.11 - para enfileirar o valor, deve-se ajustar os indices. O (*f).final recebe o valor que e depois incrementa o final para a pr�xima posi��o.
  c.12 - retorna 1 (verdadeiro) se o valor foi enfileirado.
*/
int enfileirar(Fila* f, int valor) {
	if ( ! estahCheia(f) ) {
		f->vetor[f->final] = valor;
		f->final++;
	    return 1;

	} else
 	    return 0;
}

void mostrarFila(Fila* f) {

	int i;

	printf("\n");

	for (i=f->inicio; i<f->final; i++)
	    printf("%d | ", f->vetor[i]);
}

int desenfileirar(Fila* f, int* valor) {

	if ( ! estahVazia(f) ) {

		*valor = f->vetor[f->inicio];
		f->inicio++;

		return 1;
	} else
	    return 0;

}


int main(int argc, char** argv)
{	
	Fila* filaDoBanco;
	
	filaDoBanco = criaFila();
	
	enfileirar(filaDoBanco,  50);
	enfileirar(filaDoBanco, 150);
	enfileirar(filaDoBanco, 200);
	enfileirar(filaDoBanco, 250);
	
	printf("\n Mostrando a fila ....");
	mostrarFila(filaDoBanco);
	
	int aux;
	
	while ( ! estahVazia(filaDoBanco) ) {
		desenfileirar(filaDoBanco, &aux);
		printf("\nValor %d foi retirado da fila\n ", aux);
	}	
		
	printf("\n Mostrando a fila ....");
	mostrarFila(filaDoBanco);
		
	liberaFila(filaDoBanco);
	
	filaDoBanco = criaFila();
	
	return 0;
}
