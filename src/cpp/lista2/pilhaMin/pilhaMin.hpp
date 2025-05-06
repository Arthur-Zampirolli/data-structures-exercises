#ifndef PILHA_MIN
#define PILHA_MIN
#include <iostream>
#include "stdlib.h"
#include "../pilha/pilha.hpp"
using namespace std;

//mesma complexidade do deque
struct PilhaMin { 
    // incluir variáveis necessárias
    PilhaDeque p;
    int minimo; 
    int topo(){
        return p.topo();
    } 
    int desempilha(); 
    void empilha(int t); 
    int obterMinimo(); 
    // mais métodos auxiliares 
};
    

#endif