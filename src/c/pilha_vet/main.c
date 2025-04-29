#include "stdlib.h"
#include "stdio.h"
#define SIZE 10

typedef struct pilha{
    int dados[SIZE];
    int N;
    int topo;
}Pilha;

Pilha *inicializa(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = p->N = 0;
    return p;
}

Pilha *push(Pilha *p, int dado){
    if(p->N < SIZE){
        printf("inserindo valor %d na pilha\n", dado);
        p->N++;
        p->dados[p->N - 1] = dado;
        p->topo = p->N - 1;
        return p;
    }
    return p;
}

void imprimePilha(Pilha *p){
    for(int i = p->topo; i >= 0; i--){
        printf("valor %d da pilha = %d\n", i, p->dados[i]);
    }
}

int pop(Pilha *p){
    int valor = p->dados[p->topo];
    p->topo--;
    p->N--;
    printf("desempilhando o valor %d\n\n", valor);
    return valor;
}

int main(){
    Pilha *p = inicializa();
    p = push(p, 1);
    p = push(p, 2);
    p = push(p, 3);
    imprimePilha(p);
    pop(p);
    imprimePilha(p);
    p = push(p, 4);
    imprimePilha(p);
    return 0;
}