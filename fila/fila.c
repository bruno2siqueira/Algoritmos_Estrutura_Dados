#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila* criaFila() {
	
	Fila* f;
	
	//f = malloc( 408 );
	f = malloc(sizeof(Fila));
	
	f->inicio = 0; //(*f).inicio = 0;
	f->final  = 0; //(*f).final = 0;
	
	return f;
	
}

void liberaFila(Fila* f) {
	free(f);
	f = NULL;	
}

int estahVazia(Fila* f) {
	if (f->inicio == f->final)
	   return 1; //Fila vazia
	else
	   return 0; 
}

int estahCheia(Fila* f) {
	if (f->final == MAX)
	   return 1; //fila cheia
	else
	   return 0;	
}

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



