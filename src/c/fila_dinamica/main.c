#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct fila * prox;
    int dado;
}No;

typedef struct fila{
    No * inicio;
    No * fim;
    int N;
}Fila;

No *novo(int dado){
    No *no = malloc(sizeof(Fila));
    no->dado = dado;
    no->prox = 0;
}

Fila * insere(int dado, Fila* fila){
    No *no = novo(dado);
    printf("Inserindo valor %d na fila\n", dado);
    if(fila->N == 0){
        fila->fim = fila->inicio = no;
        fila->N++;
        return fila;
    }
    No *temp = fila->fim;
    fila->fim->prox = no;
    fila->fim = no;
    fila->N++;
    temp->prox = no;
    return fila;
}

void imprime(Fila *f){
    No *n = f->inicio;
    int cont = 0;
    while(n){
        printf("Dado %d valor = %d \n", cont, n->dado);
        n = n->prox;
        cont++;
    }
}

Fila *init(){
    Fila *novo;
    novo = malloc(sizeof(Fila));
    novo->N = novo->fim = novo->inicio = 0;
    return novo;
}

Fila *remover(Fila *f){
    No * removido = f->inicio;
    printf("removendo valor %d da fila\n", removido->dado);
    f->inicio = f->inicio->prox;
    free(removido);
    return f;
}

int main()
{
    Fila *f = init();
    int valores[] = {4,2,6,8,3,250};
    for(int i = 0; i <= 6; i++){
        f = insere(valores[i], f);
    }
    imprime(f);
    f = remover(f);
    imprime(f);
    f = insere(55, f);
    f = insere(5456, f);
    imprime(f);
    return 0;
}

