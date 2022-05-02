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
	if(li != NULL && (*li) != NULL ){ // se tivermos uma lista v�lida AND o conte�do n�o for NULL (vazio), come�amos a esvazi�-la.
		Elem *aux, *no = *li;   // defino um ponteiro Elem (AUXILIAR) e um ponteiro *no que aponta para *li para percorrer a lista
		while ((*li) != no->prox){ // pego o 1� elemento da lista (o in�cio da Lista). Enquanto ENDERE�O do 1� elemento for diferente do ENDERE�O pr�ximo elemento
			aux = no;      // coloco o meu NO no AUX...
			no = no->prox; //o meu NO avan�a para o PROX
			free(aux);	   // libero o AUX (antiga referencia no NO)
		}				   // repete todo o processo at� eliminar todos os elementos lista.
		free(no);		   // libera o �ltimo NO remanescente, pois na �ltima passada n�o vai haver AUX, mas o NO ainda vai existir
		free(li);  		   // libera a lista que foi alocada inicialmente
	}
	
	//      CHAMADA NO MAIN
 	//      liberaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR O TAMANHO DA LISTA			                       	    */
/* 		A fun��o verifica o tamonho da lista, contando quantos elementos h�	*/
/****************************************************************************/
int tamanhoDaLista(Lista* li){
	if(li == NULL && (*li) == NULL)  return 0; //verifica se a lista n�o � vazia
    int cont = 0; 			 // uma vari�vel contatora
    Elem* no = *li;			// 'no' auxiliar aponta para o in�cio da lista (*li)
 	do{
	   	cont++; 			// incrementa a vari�vel contadora
    	no = no->prox;  	// 'no' aponta para o pr�ximo, percorrendo toda a Lista
	}while(no != (*li));		// Enquanto o 'no' for diferente de *li, ou seja, enquanto n�o chegar ao inicio da Lista, percorre...
	   return cont;			// ap�s percorrer a lista, retorna o valor de cont  */
	}

	
	//      CHAMADA NO MAIN
 	//      int x = tamanhoDaLista(li); 


	



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
	if(li == NULL) return 0; // Minha lista � v�lida?
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em mem�ria o novo Elem NO
	if(no == NULL) return 0; // Meu NO � valido?
		no->dado = x ;	// NO recebe dados, ou seja, copia os dados para o novo NO 
	if((*li) == NULL){	// Agora vamos inserir, ent�o, Pergunta: Minha lista � vazia?
        *li = no;	 // LI recebe NO
		no->prox = no; 	 // NO->PROX aponta para o NO (ele mesmo)
	}else{  // se ela n�o for vazia
		 Elem *aux = *li;  //crio um ponteiro auxiliar guardar a ref. do in�cio da lista e andar (percorrer) ela at� encontrar o �ltimo
		 while (aux->prox != (*li)){ // enquanto o meu elem AUX for diferente do Inicio, percorro
		 	   aux = aux->prox;
		 }
            aux->prox = no;  // quando encontrar o NO (Refer�ncia do N� Inicio), aponta para o novo NO
            no->prox = *li;  // e o novo NO aponta o seu prox para Li (inicio da lista)
            *li = no;  // para finalizar, o Li aponta para o novo NO, mudando a posi��o do in�cio
	}
	return 1; //verdadeiro, NO inserido
	
	//      CHAMADA NO MAIN
 	//      int x = insereInicio(li, dados_do_aluno); 
 	// 		
}

int insereFim(Lista* li, int x){
	if(li == NULL) return 0; // Minha Lista � valida?
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em mem�ria o novo Elem NO
	if(no == NULL) return 0; // Meu NO � valido?
	no->dado = x; 	// NO recebe dados, ou seja, copia os dados para o novo NO 
	no->prox = NULL;	// NO->PROX aponta para NULL
	if((*li) == NULL){  // testa se a lista esta vazia: insere no inicio 
		*li = no;		// Se for vazia, a li vai apontar para o pr�prio NO
		no->prox = no;   // NO->PROX aponta para o NO (ele mesmo)
	}else{				//Sen�o
		Elem *aux = *li;	      // Este � um ponteiro auxiliar aponta para lista (li) , e assim, poder percorrer a lista li para encontrar o seu final (�ltimo NO)
		while(aux->prox != (*li)){// o la�o vai percorrer a lista at� encontrar o fim da lista (NULL)
			aux = aux->prox;      // avan�a at� encontrar o fim, e armazena a informa��o do �ltimo elemento
		}
		aux->prox = no;   // depois de localizar o �ltimo elemento, aponta o AUX->PROX para o NO, permitndo que a cadeia de elementos da Lista fiquem ligados.
		no->prox = *li;
	}
	return 1;  //fim do programa, NO adicionado no fim
	
	//      CHAMADA NO MAIN
 	//      int x = insereFim(li, dados_do_aluno); 
 	// 		
}

int insereOrdenado(Lista* li, int x){ // posso inserir nos 3 casos, no inicio, no meio, ouno fim
	if(li == NULL) return 0; // Minha Lista � valida?
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em mem�ria o novo Elem NO
	if(no == NULL) return 0; // Meu NO � valido?
 	no->dado = x;
 	if((*li) == NULL){  // testa se a lista esta vazia: insere no inicio 
		*li = no;		// Se for vazia, a li vai apontar para o pr�prio NO
		no->prox = no;   // NO->PROX aponta para o NO (ele mesmo)
		return 1;
	}else if((*li)->dado > x){	    				//Sen�o, vou ter procurar onde eu vou inserir o meu elemento dentro da minha lista		
		Elem *atual = *li;  
        while(atual->prox != (*li)){
  		     atual = atual->prox;
		}
            no->prox = *li;
            atual->prox = no;
            *li = no;
			return 1;
	}
	Elem *ant = *li, *atual = (*li)->prox;
	while(atual != (*li) && atual->dado < x){
		ant = atual;
		atual = atual->prox;
	}
	ant->prox = no;
	no->prox = atual;
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
	Elem *aux = *li;
	int i = 0;
	do{
		i++;
		printf("\n [NO-%d] %d ", i, aux->dado);
        aux = aux->prox;
	}while(aux != (*li));
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
	 int tam = tamanhoDaLista(myList); 
	 printf("\nTAMANHO de myList: %d", tam);
 
	// liberaLista(myList);  
	 getche();
 
 return 0;    
}     
