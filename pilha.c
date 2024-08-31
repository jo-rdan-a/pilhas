#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

int pilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

void empilhar(Pilha *p, int item) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->dado = item;
    novo->proximo = p->topo;
    p->topo = novo;
}

int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1; 
    }
    Nodo *temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->proximo;
    free(temp);
    return valor;
}

int topoPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1; 
    }
    return p->topo->dado;
}

int main() {
    Pilha p;
    inicializarPilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    printf("Topo: %d\n", topoPilha(&p));

    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p)); 

    return 0;
}