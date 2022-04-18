#include <stdio.h>
#include "fila.h"

int main(int argc, char** argv)
{	
	Fila *A = criaFila();
	
	int i;
	
	for (i=0; i<5; i++) {
		if ( enfileirar(A, i) == 1 )
		   printf("\nO valor %d foi enfileirado ", i);
		else
		   printf("\nNão foi possível enfileirar o valor %d ", i);
	}
	
	printf("\nFila A (original)");
	mostrarFila(A);	
	
	int aux;

	for (i=0; i<3; i++) {
		if ( desenfileirar(A, &aux) == 1 )
		   printf("\nO valor %d foi desenfileirar ", aux);
		else
		   printf("\nNão foi possível desenfileirar");
	}
	
	printf("\nFila A (depois do desenfileiramento)");
	mostrarFila(A);

	for (i=0; i<3; i++) {
		if ( enfileirar(A, i) == 1 )
		   printf("\nO valor %d foi enfileirado ", i);
		else
		   printf("\nNão foi possível enfileirar o valor %d ", i);
	}

	printf("\nFila A (final)");
	mostrarFila(A);
		
	liberaFila(A);
	return 0;
}
