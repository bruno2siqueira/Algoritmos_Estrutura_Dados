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
	if(li != NULL && (*li) != NULL ){ // se tivermos uma lista válida AND o conteúdo não for NULL (vazio), começamos a esvaziá-la.
		Elem *aux, *no = *li;   // defino um ponteiro Elem (AUXILIAR) e um ponteiro *no que aponta para *li para percorrer a lista
		while ((*li) != no->prox){ // pego o 1º elemento da lista (o início da Lista). Enquanto ENDEREÇO do 1º elemento for diferente do ENDEREÇO próximo elemento
			aux = no;      // coloco o meu NO no AUX...
			no = no->prox; //o meu NO avança para o PROX
			free(aux);	   // libero o AUX (antiga referencia no NO)
		}				   // repete todo o processo até eliminar todos os elementos lista.
		free(no);		   // libera o último NO remanescente, pois na última passada não vai haver AUX, mas o NO ainda vai existir
		free(li);  		   // libera a lista que foi alocada inicialmente
	}
	
	//      CHAMADA NO MAIN
 	//      liberaLista(li); 
}

/****************************************************************************/
/*      VERIFICAR O TAMANHO DA LISTA			                       	    */
/* 		A função verifica o tamonho da lista, contando quantos elementos há	*/
/****************************************************************************/
int tamanhoDaLista(Lista* li){
	if(li == NULL && (*li) == NULL)  return 0; //verifica se a lista não é vazia
    int cont = 0; 			 // uma variável contatora
    Elem* no = *li;			// 'no' auxiliar aponta para o início da lista (*li)
 	do{
	   	cont++; 			// incrementa a variável contadora
    	no = no->prox;  	// 'no' aponta para o próximo, percorrendo toda a Lista
	}while(no != (*li));		// Enquanto o 'no' for diferente de *li, ou seja, enquanto não chegar ao inicio da Lista, percorre...
	   return cont;			// após percorrer a lista, retorna o valor de cont  */
	}

	
	//      CHAMADA NO MAIN
 	//      int x = tamanhoDaLista(li); 


	



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
	if(li == NULL) return 0; // Minha lista é válida?
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em memória o novo Elem NO
	if(no == NULL) return 0; // Meu NO é valido?
		no->dado = x ;	// NO recebe dados, ou seja, copia os dados para o novo NO 
	if((*li) == NULL){	// Agora vamos inserir, então, Pergunta: Minha lista é vazia?
        *li = no;	 // LI recebe NO
		no->prox = no; 	 // NO->PROX aponta para o NO (ele mesmo)
	}else{  // se ela não for vazia
		 Elem *aux = *li;  //crio um ponteiro auxiliar guardar a ref. do início da lista e andar (percorrer) ela até encontrar o último
		 while (aux->prox != (*li)){ // enquanto o meu elem AUX for diferente do Inicio, percorro
		 	   aux = aux->prox;
		 }
            aux->prox = no;  // quando encontrar o NO (Referência do NÓ Inicio), aponta para o novo NO
            no->prox = *li;  // e o novo NO aponta o seu prox para Li (inicio da lista)
            *li = no;  // para finalizar, o Li aponta para o novo NO, mudando a posição do início
	}
	return 1; //verdadeiro, NO inserido
	
	//      CHAMADA NO MAIN
 	//      int x = insereInicio(li, dados_do_aluno); 
 	// 		
}

int insereFim(Lista* li, int x){
	if(li == NULL) return 0; // Minha Lista é valida?
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em memória o novo Elem NO
	if(no == NULL) return 0; // Meu NO é valido?
	no->dado = x; 	// NO recebe dados, ou seja, copia os dados para o novo NO 
	no->prox = NULL;	// NO->PROX aponta para NULL
	if((*li) == NULL){  // testa se a lista esta vazia: insere no inicio 
		*li = no;		// Se for vazia, a li vai apontar para o próprio NO
		no->prox = no;   // NO->PROX aponta para o NO (ele mesmo)
	}else{				//Senão
		Elem *aux = *li;	      // Este é um ponteiro auxiliar aponta para lista (li) , e assim, poder percorrer a lista li para encontrar o seu final (último NO)
		while(aux->prox != (*li)){// o laço vai percorrer a lista até encontrar o fim da lista (NULL)
			aux = aux->prox;      // avança até encontrar o fim, e armazena a informação do último elemento
		}
		aux->prox = no;   // depois de localizar o último elemento, aponta o AUX->PROX para o NO, permitndo que a cadeia de elementos da Lista fiquem ligados.
		no->prox = *li;
	}
	return 1;  //fim do programa, NO adicionado no fim
	
	//      CHAMADA NO MAIN
 	//      int x = insereFim(li, dados_do_aluno); 
 	// 		
}

int insereOrdenado(Lista* li, int x){ // posso inserir nos 3 casos, no inicio, no meio, ouno fim
	if(li == NULL) return 0; // Minha Lista é valida?
	Elem* no = (Elem*) malloc(sizeof(Elem)); // aloco em memória o novo Elem NO
	if(no == NULL) return 0; // Meu NO é valido?
 	no->dado = x;
 	if((*li) == NULL){  // testa se a lista esta vazia: insere no inicio 
		*li = no;		// Se for vazia, a li vai apontar para o próprio NO
		no->prox = no;   // NO->PROX aponta para o NO (ele mesmo)
		return 1;
	}else if((*li)->dado > x){	    				//Senão, vou ter procurar onde eu vou inserir o meu elemento dentro da minha lista		
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
