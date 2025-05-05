#ifndef FILA
#define FILA
#include <iostream>
#include "stdlib.h"
#include "../deck/deck.hpp"
using namespace std;

//mesma complexidade do deque
struct FilaDeque{
    Deque d;
    int N;
    FilaDeque(){
        d.initDeque();
    }
    auto insere(char dado){
        d.insereFim(dado);
        this->N = d.N;
    }
    auto remove(){
        char res = d.removeInicio();
        this->N = d.N;
        return res;
    }
    auto inicio(){
        return d.inicio();
    }
    auto fim(){
        return d.fim();
    }
    auto imprime(){
        d.imprime();
    }
};

#endif