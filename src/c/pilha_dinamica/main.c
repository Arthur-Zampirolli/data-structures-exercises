#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* prox;
    int dado;
}No;

typedef struct pilha{
    struct no* topo;
    int N;
}Pilha;

No * newNode(int dado){
    No *novo = malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = 0;
    return novo;
}

Pilha *push(int dado, Pilha *p){
    printf("inserindo valor %d na pilha\n", dado);
    No *novo = newNode(dado);
    if(p->topo == 0){
        p->topo = novo;
        p->N++;
        return p;
    }
    novo->prox = p->topo;
    p->topo = novo;
    p->N++;
    return p;
}

Pilha *pop(Pilha *p){
    No *apagar = p->topo;
    p->topo = p->topo->prox;
    p->N--;
    printf("apagando o topo de valor = %d... \n", apagar->dado);
    free(apagar);
    return p;
}

void imprime(Pilha *p){
    No *temp = p->topo;
    int i = 0;
    while(temp){
        printf("dado %d valor %d\n", i, temp->dado);
        temp = temp->prox;
        i++;
    }
}
Pilha *novaPilha(){
    Pilha *p = malloc(sizeof(Pilha));
    p->N = p->topo = 0;
    return p;
}
int main()
{
    Pilha *p = novaPilha();
    p = push(1, p);
    imprime(p);
    p = push(2, p);
    p = push(98, p);
    p = push(775, p);
    imprime(p);
    p = pop(p);
    imprime(p);
    return 0;
}
