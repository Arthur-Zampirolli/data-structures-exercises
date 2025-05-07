#ifndef PILHA_MIN
#define PILHA_MIN
#include <iostream>
#include "stdlib.h"
#include "../pilha/pilha.hpp"
using namespace std;

//complexidade O(N)
struct PilhaMin { 
    // incluir variáveis necessárias
    PilhaDequeInt p;
    PilhaDequeInt aux;
    int minimo; 
    //complexidade O(1)
    int topo(){
        return p.topo();
    } 
    //complexidade O(N)
    int desempilha(){//23  124 1 5 23
        int result = p.pop();
        if(result == minimo){
            minimo = p.topo();
        }
        if(minimo < p.topo() && minimo != result){
            return result;
        }
        while(p.tamanho() > 0){
            int a = p.pop();
            if(a < minimo){
                minimo = a;
            }
            aux.push(a);
        }
        while(aux.tamanho() > 0){
            p.push(aux.pop());
        }
        return result;
    }
    //complexidade O(1)
    void empilha(int t){
        if(p.tamanho() == 0){
            minimo = t;
        }
        if(minimo > t){
            minimo = t;
        }
        p.push(t);
    } 
    //complexidade O(1)
    int obterMinimo(){
        return minimo;
    } 
    //complexidade O(N)
    void imprime(){
        p.imprime();
    }
    // mais métodos auxiliares 
};
    

#endif