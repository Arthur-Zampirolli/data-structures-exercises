#ifndef DECK
#define DECK
#include <iostream>
#include "stdlib.h"
using namespace std;


typedef struct node{
    char dado;
    struct node* prox;
    struct node* ant;
}Node;

typedef struct deck{
    struct node *inicio;
    struct node *fim;
    int N;
}Deck;

Deck *novo();

Node *inicio(Deck *d);
Deck *insereInicio(Deck *d, char dado);
Node *fim(Deck *d);
Deck *insereFim(Deck *d, char dado);
Deck *removeInicio(Deck *d);
Deck *removeFim(Deck *d);
void imprime(Deck *d);

#endif