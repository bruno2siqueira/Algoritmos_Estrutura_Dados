#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define msg_aguarde "Pressione a tecla ENTER para continuar"

void aguarde(char* msg){
	
	printf("%s",msg);
    char x;

    scanf("%c%*c", &x);
    
    /* %c = especifica um caracter
       %*c = a utilização do sinal de * (asterisco) antes do sinal de % (porcentagem) indica que o restante das informações lidas será validada mas não armazendada

     * Fonte: 
     *    http://www.vivaolinux.com.br/dica/Limpando-a-sujeirinha-no-buffer-do-teclado/
     *    http://qualadoce.blogspot.com/2008/02/o-scanf-engana.html
    */
}

void menu(){
	
	system("cls");
	printf("Escolha uma opcao do menu \n\n");
	
	printf("1 - Inserir um elemento\n");
	printf("2 - Procurar um elemento\n");
	printf("3 - Excluir um elemento da lista\n");
	printf("4 - Imprimir a lista\n");
	printf("0 - Excluir a lista e sair do programa\n");
	
	printf("\nDigite a opcao....: ");
}

int main(int argc, char** argv)
{
	Elemento* l;
	
	l = lst_cria();
	
	char op = ' ';

    while (op != '0') {
		
		menu();
		scanf("%c",&op);

        char* v;
		
		switch (op) {
			
			case '1' : 
			    printf("\nDigite o valor que deseja inserir....: ");
			    v = malloc(50);
			    scanf(" %50[^\n]",v);
			    
			    /* O espaço em branco no início ignora espaços em branco na entrada
			     * O 50 delimita o número máximo de caracteres a serem lidos
			     * O %[] indica o conjunto de caracteres que serão permitidos 
			     * O ^ nega o conteúdo do %[] ou seja, a leitura será feita até que não for encontrado o caracter \n
			    */
			    
			    l = lst_insere(l,v);
			    break;
			
			case '2' : 
			
			    printf("\nDigite o valor que deseja pesquisar..: ");
			    
			    v = malloc(50);
			    scanf(" %50[^\n]",v);
			    
        	    if (lst_busca(l,v) != NULL) {
        		   printf("O valor %s existe na lista (pressione enter para voltar ao MENU)",v);
	            }
	            else {
	               printf("O valor %s NAO existe na lista (pressione enter para voltar ao MENU)",v);
	            }
	            
	            aguarde("");
			    break;

			case '3' : 
			    printf("\nDigite o valor que deseja excluir....: ");
			    
			    v = malloc(50);
			    scanf(" %50[^\n]",v);

                l = lst_retira(l, v);    	

                printf("A primeira ocorrência do valor %s (se existente) foi excluída da lista",v);
	            
	            aguarde("");
			    break;

			case '4' : 
			    printf("\nConteudo da lista ... \n\n");
			    lst_imprime(l);
			    printf("\n");
			    aguarde(msg_aguarde);
			    break;
		}
	}
	
	lst_libera(l);
    
	return 0;
}
