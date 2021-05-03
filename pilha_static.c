#include <stdio.h>
#define MAX 10

typedef struct pilha {
    int topo;
    int vetor[MAX];
} Pilha;

Pilha inicializarPilha(Pilha p) {
    p.topo = 0;
    return p;
}

int estahVazia(Pilha p){
    if (p.topo == 0)
        return 1;
    else
        return 0;
}

int estahCheia(Pilha p){
    if (p.topo == MAX)
        return 1;
    else
        return 0;
}

Pilha empilha(Pilha p, int v, int* deuCerto){
    if (estahCheia(p))
        *deuCerto = 0;
    else {
        p.vetor[p.topo] = v;
        p.topo++;
        *deuCerto = 1;
    }

    return p;
}

Pilha desempilha(Pilha p, int* v, int* deuCerto){
    if (estahVazia(p))
        *deuCerto = 0;
    else {
        p.topo--;
        *v = p.vetor[p.topo];
        *deuCerto = 1;
    }

    return p;
}

int pegarTopo(Pilha p, int* topo){
    if (estahVazia(p))
        return 0;
    else {
        *topo = p.vetor[p.topo-1];
        return 1;
    }
}

void mostraOVetorDaPilha(Pilha p){
    int i;
    printf("\n --------------- \n");
    for (i=p.topo-1; i>=0; i--)
        printf("%d\n", p.vetor[i]);
    printf("\n --------------- \n");
}

int main(int argc, char** argv)
{
    Pilha a;
    Pilha b;

    a = inicializarPilha(a);
    b = inicializarPilha(b);

    int i;
    int erro;

    //Vai inserir  10 valores na pilha
    for (i=1;i<=10;i++) {
        printf("Vai empilhar o valor ... %d\n", i);
        a = empilha(a, i, &erro);
        printf("O código de retorno de erro foi ... %d\n", erro);
    }

    printf("A seguir a pilha A");
    mostraOVetorDaPilha(a);

    int temp; //variavel temp que vai guardar o valor do topo de a
    a = desempilha(a, &temp, &erro);

    b = empilha   (b, temp, &erro); //emplilha o topo de a (v: 10)
    b = empilha   (b, 2021, &erro); ////emplilha o topo de a (v: 2021)

    printf("A seguir a pilha B");
    mostraOVetorDaPilha(b);
    return 0;
}
