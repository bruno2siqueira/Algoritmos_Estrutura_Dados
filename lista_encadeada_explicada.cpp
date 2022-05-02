#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

/****************************************************************************/
/*       ESTRUTURA ALUNO                            					    */ 
/* 		 Defini��o da estrutura que iremos utilizar no nosso algor�tmo		*/
/****************************************************************************/
struct aluno{
	int matricula;
	char nome[20];
	float nota1, nota2, nota3;
};

/****************************************************************************/
/*       ESTRUTURA ELEMENTO					                                */ 
/*       Esta estrutura armazar� as informa��es da Lista					*/
/****************************************************************************/
struct elemento{
	int dado;
	struct elemento *prox;
};

/****************************************************************************/
/*       Defini��o de um ponteiro *Lista do tipo elemento                   */ 
/*       Mas quem � o Elemento?            				                    */ 
/*       - � a estrutura da Lista 						                    */ 
/*       que contem o Dado e ponteiro para o pr�ximo elemento da lista      */ 
/****************************************************************************/
typedef struct elemento* Lista;

/****************************************************************************/
/*       Defini��o de uma estrutura do tipo Elemento chamada Elem	        */ 
/*       Elem ser� utilizado para faciliar em algumas opera��es			    */ 
/****************************************************************************/
typedef struct elemento Elem;


/****************************************************************************/
/*       Programa Principal 							    				*/ 
/*       criando um ponteiro para a Lista (aponta para o in�cio da Lista);  */ 
/*       Lembre-se: Lista � um ponteiro para a estrutura elemento;			*/
/*       ----																*/
/*		 Nesse caso, *li � um "ponteiro para ponteiro" [**] onde cada		*/ 
/*       elemento (ou n�) da lista [dado, *prox] � um ponteiro, o *li � um  */
/*       "ponteiro para ponteiro" [**] que aponta para Lista [dado, *prox]	*/
/*       ----																*/
/*       Um "ponteiro para ponteiro" consegue armazenar o endere�o de um	*/
/*       ponteiro															*/
/****************************************************************************/
Lista* li; // li � um ponteiro para ponteiro para a struct Elemento


/****************************************************************************/
/*       OPERA��ES NA LISTA							                        */ 
/****************************************************************************/

/****************************************************************************/
/*      CRIAR LISTA						                        	        */
/* 		A fun��o criarLista retorna uma lista* (lista asterisco)			*/
/*		
/****************************************************************************/
Lista* criarLista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));/* malloc para reservar mem�ria para o primeiro n� da Lista */
	
	if(li != NULL)  // se der certo a aloca��o o meu primeiro n� vai apontar para NULL
		*li = NULL; // ao pontar para NULL representa uma lista vazia
			  		// ver a 1� linha do main
	return li;
 	
 	//      CHAMADA NO MAIN
 	//      li = criarLista();   

}

/****************************************************************************/
/*      LIBERAR LISTA						                        	    */
/* 		A fun��o libera a lista quando eu n�o for mais usar ela				*/
/*		Ela recebe como par�metro a lista que pretende liberar, nesse caso  */
/*      queremos liberar a Lista *li										*/
/****************************************************************************/
void liberaLista(Lista *li){  // passa a Lista* li
	if(li != NULL){ // se tivermos uma lista v�lida, come�amos a esvazi�-la.
		Elem* no;   // defino um ponteiro Elem (AUXILIAR)
		while ((*li) != NULL){ // pego o 1� elemento da lista (o in�cio da Lista). Enquanto ela for diferente de NULL, ou seja, enquanto eu n�o tiver uma lista vazia...
			no = *li;           // o meu NO recebe *li, ou seja, o meu NO recebe o in�cio da Lista (*li)...
			*li = (*li)->prox; // o in�cio da lista (*li) vai apontar par ao pr�ximo elemento da lista (prox) e...
			free(no);			// vamos liberar o NO, que era o antigo in�cio. Assim, nunca percemos a refer�ncia do in�cio da Lista
		}						// repete todo o processo at� eliminar todos os elementos lista.
		free(li);  				// quanto chegar em NULL, a Lista* li � liberada.
	}
	
	//      CHAMADA NO MAIN
 	//      liberaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR O TAMANHO DA LISTA			                       	    */
/* 		A fun��o verifica o tamonho da lista, contando quantos elementos h�	*/
/****************************************************************************/
int tamanhoDaLista(Lista* li){
	if(li == NULL) return 0; // se o in�cio for NULL, retorna O, i.e. lista vazia
    int cont = 0; 			 // uma vari�vel contatora
    Elem* no = *li;			// 'no' auxiliar aponta para o in�cio da lista (*li)
    while(no != NULL){		// Enquanto o 'no' for diferente de NULL, ou seja, enquanto n�o chegar ao final da Lista, percorre...
    	cont++; 			// incrementa a vari�vel contadora
    	no = no->prox;  	// 'no' aponta para o pr�ximo, percorrendo toda a Lista
	}
	return cont;			// ap�s percorrer a lista, retorna o valor de cont
	
	//      CHAMADA NO MAIN
 	//      int x = tamanhoDaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR SE LISTA CHEIA			                       		    */
/* 		A fun��o verifica se a lista esta cheia								*/
/*		Embora saibamos que a lista ser� cheia se acabar a m�m�ria do PC	*/
/****************************************************************************/
int listaCheia(Lista* li){
	return 0;			// retorna falso
			
	//      CHAMADA NO MAIN
 	//      int x = listaCheia(li); 
 	// 		if(listaCheia(li))
}

/****************************************************************************/
/*      VERIFICAR SE LISTA VAZIA			                       		    */
/* 		A fun��o verifica se a lista esta vazia								*/
/*		*/
/****************************************************************************/
int listaVazia(Lista* li){
	if(li == NULL)	// se lista for nula li== NULL, retorna verdadeiro 
		  return 1;
	if(*li == NULL)	// se o conte�do da lista for nula *li== NULL, retorna verdadeiro 
		  return 1;
	return 0;			// retorna falso, ou seja, a Lista n�o esta vazia
			
	//      CHAMADA NO MAIN
 	//      int x = listaVazia(li); 
 	// 		if(listaVazia(li))
}

/****************************************************************************/
/*      INSERIR ELEMENTO NA LISTA				                       		*/
/* 		Existem 3 forma de inser��o	(formas coordenadas de inser��o)		*/
/*		1� - No in�cio														*/
/*		2� - No meio														*/
/*		3� - No final														*/
/*		Mas sempre temos que verificar a condi��o da nossa lista ao inserir */
/*      elementos em uma lista vazio.										*/
/* -------------------------------------------------------------------------*/
/*      O que acontece?														*/
/*		Quando criamos uma lista, ela � vazia, onde � reservado espa�o para */
/*		o conte�do e um ponteiro apontado para o prox.						*/
/*		Nesse caso, o INICIO para apontar para o NO, e o PROX para NULL, ou */
/* 		para o pr�prio INICIO												*/
/****************************************************************************/
int insereInicio(Lista* li, int x){  // para a Lista e os Dados que quero que sejam armazenados
	if(li == NULL) return 0; // falso, lista n�o existe
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em mem�ria o novo Elem NO
	if(no == NULL) return 0; // falso, n�o conseguiu alocar NO
		no->dado = x ;		 // NO recebe dados 
		no->prox = (*li);	 // NO->PROX aponta para Lista
		*li = no;			 // Lista aponta para NO
		
	return 1; //verdadeiro, NO inserido
	
	//      CHAMADA NO MAIN
 	//      int x = insereInicio(li, dados_do_aluno); 
 	// 		
}

int insereFim(Lista* li, int x){
	if(li == NULL) return 0; //falso, lista n�o existe
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em mem�ria o novo Elem NO
	if(no == NULL) return 0; //falso, n�o conseguiu alocar NO
	no->dado = x; 	// NO recebe dados
	no->prox = NULL;	// NO->PROX aponta para NULL
	if((*li) == NULL){  // testa se a lista esta vazia: insere no inicio 
		*li = no;		// Se for vazia, a li vai apontar para o pr�prio NO
	}else{				//Sen�o
		Elem *aux = *li;	      // Este � um ponteiro auxiliar aponta para lista (li) , e assim, poder percorrer a lista li para encontrar o seu final (�ltimo NO)
		while(aux->prox != NULL){ // o la�o vai percorrer a lista at� encontrar o fim da lista (NULL)
			aux = aux->prox;      // avan�a at� encontrar o fim, e armazena a informa��o do �ltimo elemento
		}
		aux->prox = no;   // depois de localizar o �ltimo elemento, aponta o AUX->PROX para o NO, permitndo que a cadeia de elementos da Lista fiquem ligados.
	}
	return 1;  //fim do programa, NO adicionado no fim
	
	//      CHAMADA NO MAIN
 	//      int x = insereFim(li, dados_do_aluno); 
 	// 		
}

int insereOrdenado(Lista* li, int x){ // posso inserir nos 3 casos, no inicio, no meio, ouno fim
	if(li == NULL) return 0; //falso, lista n�o existe
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em mem�ria o novo Elem NO
	if(no == NULL) return 0; //falso, n�o conseguiu alocar NO
	
	/***** implementar **********/ 		
}

/****************************************************************************/
/*      REMOVER ELEMENTO NA LISTA				                       		*/
/* 		Existem 3 forma de remo��o											*/
/*		1� - No in�cio														*/
/*		2� - No meio														*/
/*		3� - No final														*/
/*		Mas sempre temos que verificar a consi��o da nossa lista 			*/
/*		CUIDADOS!!!															*/
/*		- N�o posso remover algo de uma lista vazia							*/
/*		- removendo o �ltimo n�, a lista fica vazia							*/
/****************************************************************************/

int removeInicio(Lista *li){
	if(li == NULL) return 0; //falso, lista n�o existe
	if((*li) == NULL) return 0; //falso, lista vazia
	
	Elem *no = *li; // NO aponta para INICIO
	*li = no->prox; //  INICIO aponta para o NO->PROX
	free(no);	    // Libera o NO 
	return 1;
 
 	//      CHAMADA NO MAIN
 	//      int x = removeInicio(li); 	
	
	}

int removeFinal(Lista *li){  // tenho que percorrer a minha lista at� chegar ao final
	if(li == NULL) return 0; //falso, lista n�o existe
	if((*li) == NULL) return 0; //falso, lista vazia
	
	Elem *ant;		// ponteiro que ir� apontar para o NO anterior
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
