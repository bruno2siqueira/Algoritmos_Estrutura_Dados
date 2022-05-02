#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h>
#include "lista.h"

struct elemento {
	char* palavra;
	struct elemento* prox;
};

/*Função de criação: retorna uma lista vazia*/
Elemento* lst_cria() {
	return NULL;
}

/*Inserção no início: retorna a lista atualizada*/
Elemento* lst_insere(Elemento* lst, char* p) {
	Elemento* novo = malloc(sizeof(Elemento)); //(Lista*)
	
	novo->palavra = p;
	
	novo->prox = lst;
	return novo;
}

/*Função imprime: imprime valores dos elementos*/
void lst_imprime(Elemento* l)
{
	Elemento* p; // Variável auxiliar para percorrer a lista
	int i = 0;
	for (p = l; p != NULL; p = p->prox) {
		i++;
		printf("%do. elemento = %s\n", i, p->palavra);
	}
}

/*Função vazia: retorna 1 se vazia e 0 se não vazia*/
int lst_vazia(Elemento* l) {
	if (l == NULL)
	   return 1;
	else
	   return 0;
}

/*Função busca: busca um elemento na lista*/
Elemento* lst_busca(Elemento* l, char* p) {
	Elemento* t;
	
	for (t=l; t!=NULL; t=t->prox) {
		if ( strcmp(t->palavra, p) == 0 )
		   return t;
	}
	
	return NULL; //Só vai cair aqui se não achar o elemento
}

/*Função retira: retira um elemento da lista*/
Elemento* lst_retira(Elemento* lst, char* p) {
	Elemento* ant = NULL; /*ponteiro para o elemento anterior*/
	Elemento* t = lst; /*ponteiro para percorrer a lista*/
	
	/*procura elemento na lista e guarda o elemento anterior*/
	while (t!=NULL && strcmp(t->palavra, p)) {
		ant = t;
		t = t->prox;
	}
	
	if (t == NULL)
	    return lst; /* não achou: retorna a lista original */
	    
	/*retira o elemento */
	if (ant == NULL) {
		/* retira o elemento do início */
		lst = t->prox;
	} else {
		/*Retira o elemento do meio da lista*/
		ant->prox = t->prox;
	}
	
	free(t);
	return lst;
}

void lst_libera(Elemento* lst) {
	Elemento* p = lst;
	while (p != NULL) {
		Elemento* t = p->prox; /*Guarda a referência para o próximo elemento*/
		free(p); /*Libera a memória apontada por p*/
		p = t;
	}
}
		
