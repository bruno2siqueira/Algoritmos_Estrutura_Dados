#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

/****************************************************************************/
/*       ESTRUTURA ALUNO                            					    */ 
/* 		 Definição da estrutura que iremos utilizar no nosso algorítmo		*/
/****************************************************************************/
struct aluno{
	int matricula;
	char nome[20];
	float nota1, nota2, nota3;
};

/****************************************************************************/
/*       ESTRUTURA ELEMENTO					                                */ 
/*       Esta estrutura armazará as informações da Lista					*/
/****************************************************************************/
struct elemento{
	int dado;
	struct elemento *prox;
};

/****************************************************************************/
/*       Definição de um ponteiro *Lista do tipo elemento                   */ 
/*       Mas quem é o Elemento?            				                    */ 
/*       - é a estrutura da Lista 						                    */ 
/*       que contem o Dado e ponteiro para o próximo elemento da lista      */ 
/****************************************************************************/
typedef struct elemento* Lista;

/****************************************************************************/
/*       Definição de uma estrutura do tipo Elemento chamada Elem	        */ 
/*       Elem será utilizado para faciliar em algumas operações			    */ 
/****************************************************************************/
typedef struct elemento Elem;


/****************************************************************************/
/*       Programa Principal 							    				*/ 
/*       criando um ponteiro para a Lista (aponta para o início da Lista);  */ 
/*       Lembre-se: Lista é um ponteiro para a estrutura elemento;			*/
/*       ----																*/
/*		 Nesse caso, *li é um "ponteiro para ponteiro" [**] onde cada		*/ 
/*       elemento (ou nó) da lista [dado, *prox] é um ponteiro, o *li é um  */
/*       "ponteiro para ponteiro" [**] que aponta para Lista [dado, *prox]	*/
/*       ----																*/
/*       Um "ponteiro para ponteiro" consegue armazenar o endereço de um	*/
/*       ponteiro															*/
/****************************************************************************/
Lista* li; // li é um ponteiro para ponteiro para a struct Elemento


/****************************************************************************/
/*       OPERAÇÕES NA LISTA							                        */ 
/****************************************************************************/

/****************************************************************************/
/*      CRIAR LISTA						                        	        */
/* 		A função criarLista retorna uma lista* (lista asterisco)			*/
/*		
/****************************************************************************/
Lista* criarLista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));/* malloc para reservar memória para o primeiro nó da Lista */
	
	if(li != NULL)  // se der certo a alocação o meu primeiro nó vai apontar para NULL
		*li = NULL; // ao pontar para NULL representa uma lista vazia
			  		// ver a 1ª linha do main
	return li;
 	
 	//      CHAMADA NO MAIN
 	//      li = criarLista();   

}

/****************************************************************************/
/*      LIBERAR LISTA						                        	    */
/* 		A função libera a lista quando eu não for mais usar ela				*/
/*		Ela recebe como parâmetro a lista que pretende liberar, nesse caso  */
/*      queremos liberar a Lista *li										*/
/****************************************************************************/
void liberaLista(Lista *li){  // passa a Lista* li
	if(li != NULL){ // se tivermos uma lista válida, começamos a esvaziá-la.
		Elem* no;   // defino um ponteiro Elem (AUXILIAR)
		while ((*li) != NULL){ // pego o 1º elemento da lista (o início da Lista). Enquanto ela for diferente de NULL, ou seja, enquanto eu não tiver uma lista vazia...
			no = *li;           // o meu NO recebe *li, ou seja, o meu NO recebe o início da Lista (*li)...
			*li = (*li)->prox; // o início da lista (*li) vai apontar par ao próximo elemento da lista (prox) e...
			free(no);			// vamos liberar o NO, que era o antigo início. Assim, nunca percemos a referência do início da Lista
		}						// repete todo o processo até eliminar todos os elementos lista.
		free(li);  				// quanto chegar em NULL, a Lista* li é liberada.
	}
	
	//      CHAMADA NO MAIN
 	//      liberaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR O TAMANHO DA LISTA			                       	    */
/* 		A função verifica o tamonho da lista, contando quantos elementos há	*/
/****************************************************************************/
int tamanhoDaLista(Lista* li){
	if(li == NULL) return 0; // se o início for NULL, retorna O, i.e. lista vazia
    int cont = 0; 			 // uma variável contatora
    Elem* no = *li;			// 'no' auxiliar aponta para o início da lista (*li)
    while(no != NULL){		// Enquanto o 'no' for diferente de NULL, ou seja, enquanto não chegar ao final da Lista, percorre...
    	cont++; 			// incrementa a variável contadora
    	no = no->prox;  	// 'no' aponta para o próximo, percorrendo toda a Lista
	}
	return cont;			// após percorrer a lista, retorna o valor de cont
	
	//      CHAMADA NO MAIN
 	//      int x = tamanhoDaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR SE LISTA CHEIA			                       		    */
/* 		A função verifica se a lista esta cheia								*/
/*		Embora saibamos que a lista será cheia se acabar a mémória do PC	*/
/****************************************************************************/
int listaCheia(Lista* li){
	return 0;			// retorna falso
			
	//      CHAMADA NO MAIN
 	//      int x = listaCheia(li); 
 	// 		if(listaCheia(li))
}

/****************************************************************************/
/*      VERIFICAR SE LISTA VAZIA			                       		    */
/* 		A função verifica se a lista esta vazia								*/
/*		*/
/****************************************************************************/
int listaVazia(Lista* li){
	if(li == NULL)	// se lista for nula li== NULL, retorna verdadeiro 
		  return 1;
	if(*li == NULL)	// se o conteúdo da lista for nula *li== NULL, retorna verdadeiro 
		  return 1;
	return 0;			// retorna falso, ou seja, a Lista não esta vazia
			
	//      CHAMADA NO MAIN
 	//      int x = listaVazia(li); 
 	// 		if(listaVazia(li))
}

/****************************************************************************/
/*      INSERIR ELEMENTO NA LISTA				                       		*/
/* 		Existem 3 forma de inserção	(formas coordenadas de inserção)		*/
/*		1ª - No início														*/
/*		2ª - No meio														*/
/*		3ª - No final														*/
/*		Mas sempre temos que verificar a condição da nossa lista ao inserir */
/*      elementos em uma lista vazio.										*/
/* -------------------------------------------------------------------------*/
/*      O que acontece?														*/
/*		Quando criamos uma lista, ela é vazia, onde é reservado espaço para */
/*		o conteúdo e um ponteiro apontado para o prox.						*/
/*		Nesse caso, o INICIO para apontar para o NO, e o PROX para NULL, ou */
/* 		para o próprio INICIO												*/
/****************************************************************************/
int insereInicio(Lista* li, int x){  // para a Lista e os Dados que quero que sejam armazenados
	if(li == NULL) return 0; // falso, lista não existe
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em memória o novo Elem NO
	if(no == NULL) return 0; // falso, não conseguiu alocar NO
		no->dado = x ;		 // NO recebe dados 
		no->prox = (*li);	 // NO->PROX aponta para Lista
		*li = no;			 // Lista aponta para NO
		
	return 1; //verdadeiro, NO inserido
	
	//      CHAMADA NO MAIN
 	//      int x = insereInicio(li, dados_do_aluno); 
 	// 		
}

int insereFim(Lista* li, int x){
	if(li == NULL) return 0; //falso, lista não existe
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em memória o novo Elem NO
	if(no == NULL) return 0; //falso, não conseguiu alocar NO
	no->dado = x; 	// NO recebe dados
	no->prox = NULL;	// NO->PROX aponta para NULL
	if((*li) == NULL){  // testa se a lista esta vazia: insere no inicio 
		*li = no;		// Se for vazia, a li vai apontar para o próprio NO
	}else{				//Senão
		Elem *aux = *li;	      // Este é um ponteiro auxiliar aponta para lista (li) , e assim, poder percorrer a lista li para encontrar o seu final (último NO)
		while(aux->prox != NULL){ // o laço vai percorrer a lista até encontrar o fim da lista (NULL)
			aux = aux->prox;      // avança até encontrar o fim, e armazena a informação do último elemento
		}
		aux->prox = no;   // depois de localizar o último elemento, aponta o AUX->PROX para o NO, permitndo que a cadeia de elementos da Lista fiquem ligados.
	}
	return 1;  //fim do programa, NO adicionado no fim
	
	//      CHAMADA NO MAIN
 	//      int x = insereFim(li, dados_do_aluno); 
 	// 		
}

int insereOrdenado(Lista* li, int x){ // posso inserir nos 3 casos, no inicio, no meio, ouno fim
	if(li == NULL) return 0; //falso, lista não existe
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em memória o novo Elem NO
	if(no == NULL) return 0; //falso, não conseguiu alocar NO
	
	/***** implementar **********/ 		
}

/****************************************************************************/
/*      REMOVER ELEMENTO NA LISTA				                       		*/
/* 		Existem 3 forma de remoção											*/
/*		1ª - No início														*/
/*		2ª - No meio														*/
/*		3ª - No final														*/
/*		Mas sempre temos que verificar a consição da nossa lista 			*/
/*		CUIDADOS!!!															*/
/*		- Não posso remover algo de uma lista vazia							*/
/*		- removendo o último nó, a lista fica vazia							*/
/****************************************************************************/

int removeInicio(Lista *li){
	if(li == NULL) return 0; //falso, lista não existe
	if((*li) == NULL) return 0; //falso, lista vazia
	
	Elem *no = *li; // NO aponta para INICIO
	*li = no->prox; //  INICIO aponta para o NO->PROX
	free(no);	    // Libera o NO 
	return 1;
 
 	//      CHAMADA NO MAIN
 	//      int x = removeInicio(li); 	
	
	}

int removeFinal(Lista *li){  // tenho que percorrer a minha lista até chegar ao final
	if(li == NULL) return 0; //falso, lista não existe
	if((*li) == NULL) return 0; //falso, lista vazia
	
	Elem *ant;		// ponteiro que irá apontar para o NO anterior
	Elem *no = *li; // ponteiro que aponta para a Lista Li (INICIO)
	while (no->prox != NULL){ // percorrendo a lista
	    ant = no;			  // ANT aponta para o NO (sabendo que NO esta apontando para o INICIO)
		no = no->prox;        // 
	}
	if(no == (*li)){ // remove o primeiro
		  *li = no->prox;
	}else
		ant->prox = no->prox;
	free(no);  
	return 1;
}

void mostraLista(Lista *li){
	Elem *no = *li;
	while(no != NULL){	
        printf("%d ", no->dado);
        no = no->prox;
    }
}

/****************************************************************************/
/*       Main code                                                          */ 
/****************************************************************************/
int  main(){
  	 
	 Lista* myList;
	 myList = criarLista();
	 insereInicio(myList, 1);
	 insereInicio(myList, 2);
	 insereInicio(myList, 3);
	 insereInicio(myList, 4);
	 mostraLista(myList);
	 
	 printf("\n Inseriu 5 no fim \n");
	 insereFim(myList, 5);
	 mostraLista(myList); 
	 
	 liberaLista(myList);  
	 getche();
 
 return 0;    
}     
