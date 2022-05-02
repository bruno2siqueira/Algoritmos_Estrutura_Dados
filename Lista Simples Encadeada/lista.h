typedef struct elemento Elemento;

/*Função de criação: retorna uma lista vazia*/
Elemento* lst_cria();

/*Inserção no início: retorna a lista atualizada*/
Elemento* lst_insere(Elemento* lst, char* p);

/*Função imprime: imprime valores dos elementos*/
void lst_imprime(Elemento* lst);

/*Função vazia: retorna 1 se vazia e 0 se não vazia*/
int lst_vazia(Elemento* lst);

/*Função busca: busca um elemento na lista*/
Elemento* lst_busca(Elemento* lst, char* p);

/*Função libera: libera toda a memória alocada para a lista*/
void lst_libera(Elemento* lst);

/*Função retira: retira um elemento da lista*/
Elemento* lst_retira(Elemento* lst, char* p);
