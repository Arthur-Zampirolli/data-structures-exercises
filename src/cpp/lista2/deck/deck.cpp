#include "deck.h"

Deck *novo(){
    Deck *n = (Deck*)malloc(sizeof(Deck));
    n->fim = n->inicio = nullptr;
    n->N = 0;
    return n;
}

Node *novoNode(char dado){
    Node* no = (Node*)malloc(sizeof(Node));
    no->dado = dado;
    no->ant = no->prox = nullptr;
    return no;
}

Node *inicio(Deck *d){
    return d->inicio;
}
Node *fim(Deck *d){
    return d->fim;
}
//algoritmo com complexidade O(1)
Deck *insereInicio(Deck *d, char dado){
    std::printf("inserindo %c no inicio do deck...\n", dado);
    Node *n = novoNode(dado);
    if(d->N == 0){
        d->inicio = d->fim = n;
        d->N++;
        return d;
    }
    Node *temp = d->inicio;
    temp->ant = n;
    n->prox = temp;
    d->inicio = n;
    d->N++;
    return d;
}
//algoritmo com complexidade O(1)
Deck *insereFim(Deck *d, char dado){
    std::printf("inserindo %c no fim do deck...\n", dado);
    Node *n = novoNode(dado);
    if(d->N == 0){
        d->inicio = d->fim = n;
        d->N++;
        return d;
    }
    Node *temp = d->fim;
    n->ant = temp;
    temp->prox = n;
    d->fim = n;
    d->N++;
    return d;
}
//algoritmo com complexidade O(1)
Deck *removeInicio(Deck *d){
    std::printf("removendo %c do inicio do deck...\n", d->inicio->dado);
    Node *dado = d->inicio;
    d->N--;
    if(d->N == 0){
        d->fim = d->inicio = nullptr;
        free(dado);
        return d;
    }
    d->inicio = dado->prox;
    dado->prox->ant = nullptr;
    free(dado);
    return d;
}
//algoritmo com complexidade O(1)
Deck *removeFim(Deck *d){
    std::printf("removendo %c do fim do deck...\n", d->fim->dado);
    Node *dado = d->fim;
    d->N--;
    if(d->N == 0){
        d->fim = d->inicio = nullptr;
        free(dado);
        return d;
    }
    d->fim = dado->ant;
    dado->ant->prox = nullptr;
    free(dado);
    return d;
}
//algoritmo com complexidade O(N)
void imprime(Deck *d){
    Node *inicio = d->inicio;
    std::printf("Imprimindo valores do deck...\n");
    while(inicio){
        std::printf("%c ", (int)inicio->dado);
        inicio = inicio->prox;
    }
    std::printf("\n");
}