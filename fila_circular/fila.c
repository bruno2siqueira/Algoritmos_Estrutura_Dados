#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila* criaFila() {
	
	Fila* f;
	
	//f = malloc( 408 );
	f = malloc(sizeof(Fila));
	
	f->inicio = 0; //(*f).inicio = 0;
	f->final  = 0; //(*f).final = 0;
	f->tamanho = 0; //inicializar o tamanho
	
	return f;
	
}

void liberaFila(Fila* f) {
	free(f);
	f = NULL;	
}

int estahVazia(Fila* f) {
	if (f->tamanho == 0)
	   return 1; //Fila vazia
	else
	   return 0; 
}

int estahCheia(Fila* f) {
	if (f->tamanho == MAX)
	   return 1; //fila cheia
	else
	   return 0;	
}

int enfileirar(Fila* f, int valor) {
	if ( ! estahCheia(f) ) {
		f->vetor[f->final] = valor;
		f->final++;		
		
		if (f->final == MAX) //Girar o vetor
		   f->final = 0;
		   
		f->tamanho++; //incrementar o tamanho
		
	    return 1;	

	} else 
 	    return 0;
}

void mostrarFila(Fila* f) {
	
	int i = f->inicio;
	int aux = 0;
	
	printf("\n");
	
	while (aux < f->tamanho) {
	    printf("%d | ", f->vetor[i]);
	    i++;
	    
	    if (i == MAX) 
	       i = 0;
	       
	    aux++;
	}
}

int desenfileirar(Fila* f, int* valor) {
	
	if ( ! estahVazia(f) ) {
		
		*valor = f->vetor[f->inicio];
		f->inicio++;
		
		if (f->inicio == MAX)
		   f->inicio = 0;
		   
		f->tamanho--;
		
		return 1;
	} else 
	    return 0;
	
}


