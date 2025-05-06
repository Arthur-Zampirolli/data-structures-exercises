#ifndef PILHA_2_FILAS
#define PILHA_2_FILAS
#include "../fila/fila.hpp"

struct Pilha2F{
    FilaDeque aux;
    FilaDeque p;
    //complexidade O(1)
    auto push(char dado){
        aux.insere(dado);
    }
    //complexidade O(N)
    auto pop(){
        //tem que circular ela pra baixo
        int i = aux.N - 1;
        while(i >= 1){
            char c = aux.remove();
            aux.insere(c);
            i--;
        }
        aux.remove();
    }
    //complexidade O(1)
    auto topo(){
        return aux.fim();
    }
    //complexidade O(N)
    void imprime(){
        aux.imprimeFim();
    }
    //complexidade O(1)
    auto tamanho(){
        return aux.N;
    }
    private: 
    //complexidade O(N)
        void transfere(int d){
            while(aux.N > 0 && d < 0){
                char c = aux.remove();
                std:: printf("Transferindo %c de aux pra p...\n", c);
                p.insere(c);
            }
            while(aux.N > 0 && d > 0){
                char c = p.remove();
                std:: printf("Transferindo %c de p pra aux...\n", c);
                aux.insere(c);
            }
        }
};

#endif