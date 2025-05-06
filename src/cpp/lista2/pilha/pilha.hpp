#ifndef PILHA
#define PILHA
#include <iostream>
#include "stdlib.h"
#include "../deck/deck.hpp"
using namespace std;

//mesma complexidade do deque
struct PilhaDeque{
    Deque d;
    PilhaDeque(){
        //d = new Deque();
        d.initDeque();
    }
    auto topo(){
        return d.inicio();
    }
    auto push(char dado){
        d.insereInicio(dado);
    }
    auto pop(){
        return d.removeInicio();
    }
    auto imprime(){
        d.imprime();
    }
    auto tamanho(){
        return d.tamanho();
    }
};


#endif