#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>


typedef int tpitem; // tipo a ser armazenado

typedef struct tp_no {
	   tpitem info;
	   struct tp_no *prox;
} tplista; 

/* cria lista apontando para NULL */
tplista *lista =  NULL;


/**
* Verifica se lista estah vazia
**/
int vazia (tplista *t) {  
		return (t==NULL);
}

/**
* Faz listagem 
**/
void listagem (tplista *t) {  
  tplista *p;
   for (p=t; p!=NULL; p=p->prox)
	printf("Info: %d\n", p->info);
}

/**
* Busca elemento
**/
tplista* busca (tplista *t , tpitem valor) {
   tplista *p=t;
	while ((p!=NULL) && (p->info!=valor))
		   p=p->prox;
	return p;
}

/**
* Aloca novo nodo
**/
tplista* aloca( ) {
	tplista* pt;
	pt=(tplista*) malloc(sizeof(tplista));
	return pt;
}

/**
* Insere valor - Por referencia
**/
int insere (tplista **t , tpitem e) {
	tplista *novo;
	tplista *ant=NULL;
	tplista *p=*t;
	novo = aloca();
	if (!novo) 
		return 0;
	novo->info = e;
	while (p && p->info < e) {
		ant=p;
		p=p->prox;  
	  }


	novo->prox=p; 
	if (ant==NULL)
		*t=novo;
	else 
		ant->prox=novo; 
	return 1;
}
/**
* Remove valor - Por referencia
**/
int retira (tplista **t, tpitem e) {
	tplista *ant=NULL, *p=*t;
	
	while (p != NULL && p->info != e)
	{
		ant=p;
		p=p->prox;  
	 }
	if (p==NULL) 
		return 0; 
	else {
		if (ant==NULL)
			*t=p->prox;
		else 
			ant->prox=p->prox; 
		free(p);
		return 1;
	}
}


/**
* Destroi
**/
void destroi (tplista *t) {
	tplista *p=t, *q;
	while (p!=NULL) {
		q=p->prox; /* guarda referência p/ o próximo */
		free(p); /* libera a memória apontada por p */
		p=q; /* faz p apontar para o próximo */
	}
}


/****************************************************************************/
/*       Main code                                                          */ 
/****************************************************************************/
int  main(){
     
     
     tplista * aux; /* ponteiro auxiliar para buscas */

     printf("\nInserindo elementos na lista e mostrando o resultado \n");          
     insere(&lista,4);
     insere(&lista,5);
     insere(&lista,7);          
    
     listagem(lista);

      printf("\nRetirado um elemento da lista e mostrando o resultado \n");     
     retira(&lista,5);
     listagem(lista);
   
     printf("\nProcurando um elemento na lista \n");     
     aux = busca(lista, 12 );
     if(aux)
       printf("Valor %d encontrado \n", aux->info);
     else
       printf("Valor nao encontrado \n");
     
     printf("\nDestroindo a lista \n");          
     destroi(lista);
     
     
     getche();
 
 return 0;    
}     
