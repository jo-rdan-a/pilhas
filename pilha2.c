#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

    typedef struct {
    int itens[MAX];
    int topo;
    } Pilha;

    void inicializarPilha(Pilha *p) {
    p->topo = -1;
    }

    int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
    }

    int pilhaVazia(Pilha *p) {
    return p->topo == -1;
    }

    void empilhar(Pilha *p, int item) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = item;
    }

    int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1; 
    }
    return p->itens[(p->topo)--];
    }

    int topoPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1; 
    }
    return p->itens[p->topo];
    }

    int main() {
    Pilha p;
    inicializarPilha(&p);

    empilhar(&p, 05);
    empilhar(&p, 06);
    empilhar(&p, 07);

    printf("Topo: %d\n", topoPilha(&p));

    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p)); 

    return 0;
}