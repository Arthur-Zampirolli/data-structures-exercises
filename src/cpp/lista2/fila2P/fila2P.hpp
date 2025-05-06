#ifndef FILA_2_P
#define FILA_2_P
#include "../pilha/pilha.hpp"

// Implemente uma estrutura que satisfaz o TAD Fila para o tipo ‘char’ e somente utiliza duas Pilhas como armazenamento interno (mais espaço constante): 

struct Fila2P { 
    PilhaDeque p1; // Pilha para ‘char’ 
    PilhaDeque p2; // Pilha para ‘char’ 
    // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc) // implementar métodos do TAD Fila 
    //complexidade O(n)
    auto frente(){
        //tem que pegar o fundo
        while(p1.tamanho() > 0){
            p2.push(p1.pop());
        }
        char result = p2.topo();
        while(p2.tamanho() > 0){
            p1.push(p2.pop());
        }
        return result;
    }
    //complexidade O(n)
    auto enfileira(char dado){   
        p2.push(dado);
        while(p2.tamanho() > 0){
            p1.push(p2.pop());
        }
    }
    //complexidade O(n)
    auto desenfileira(){
        //tem que pegar o fundo
        while(p1.tamanho() > 0){
            p2.push(p1.pop());
        }
        p2.pop();
        while(p2.tamanho() > 0){
            p1.push(p2.pop());
        }
    }
    //complexidade O(1)
    auto tamanho(){
        return p1.tamanho();
    }
    auto imprime(){
        p1.imprime();
    }
}; 


#endif