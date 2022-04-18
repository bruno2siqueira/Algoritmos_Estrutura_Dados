#include <stdio.h>
#include "fila.h"

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
