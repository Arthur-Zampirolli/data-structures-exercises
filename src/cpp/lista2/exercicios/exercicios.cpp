#include "exercicios.hpp"

void exercicio1a(){
    auto d = new Deque();
    d->insereInicio('a');
    d->insereFim('b');
    d->insereInicio('d');
    d->imprime();
    d->removeFim();
    d->imprime();
}

void exercicio1b(){
    auto pd = new PilhaDeque();
    pd->push('n');
    pd->imprime();
    pd->push('a');
    pd->push('t');
    pd->imprime();
    pd->pop();
    pd->imprime();
}

void exercicio2(){
    auto p2f = new Pilha2F();
    p2f->push('n');
    p2f->push('a');
    p2f->push('t');
    p2f->push('a');
    p2f->push('l');
    p2f->push('i');
    p2f->push('a');
    p2f->imprime();
    std::printf("Topo da p2f %c\n", p2f->topo()->dado);
    p2f->pop();
    p2f->imprime();
    std::printf("Topo da p2f %c\n", p2f->topo()->dado);
    p2f->pop();
    p2f->imprime();
}

void exercicio3(){
    auto f2p = new Fila2P();
    f2p->enfileira('n');
    f2p->enfileira('a');
    f2p->enfileira('t');
    f2p->enfileira('a');
    f2p->enfileira('l');
    f2p->enfileira('i');
    f2p->enfileira('a');
    std::printf("frente da f2p %c\n", f2p->frente());
    f2p->imprime();
    f2p->desenfileira();
    std::printf("frente da f2p %c\n", f2p->frente());
    f2p->imprime();
    f2p->enfileira('a');
    f2p->enfileira('b');
    f2p->enfileira('c');
    f2p->imprime();
    f2p->desenfileira();
    f2p->imprime();
}
void exercicio4a(){
    std::stack<char> s; 
    s.push('A'); 
    s.push('B'); 
    s.push('C'); 
    imprimeStack(s);
    inverte4a(&s); 
    imprimeStack(s);
    // pilha s deve estar invertida 
}
void exercicio4b(){
    std::stack<char> s; 
    s.push('A'); 
    s.push('B'); 
    s.push('C'); 
    imprimeStack(s);
    inverte4b(&s); 
    imprimeStack(s);
    // pilha s deve estar invertida 
}

void exercicio4c(){
    std::stack<char> s; 
    s.push('A'); 
    s.push('B'); 
    s.push('C'); 
    imprimeStack(s);
    inverte4c(&s); 
    imprimeStack(s);
    // pilha s deve estar invertida 
}

void exercicio5(){

    // pilha s deve estar invertida 
}

void exercicio6(){

    // pilha s deve estar invertida 
}
void exercicio7(){
 

    // pilha s deve estar invertida 
}
/*funcoes auxiliares dos exercicios 4 pra frente*/

void imprimeStack(stack<char> p){
    // if(p.empty()) return;
    // char c = p.top();
    // p.pop();
    // imprimeStack(p);
    // std::printf(" %c ", c);
    // p.push(c);
    while(p.size() > 0){
        char c = p.top();
        std::printf(" %c ", c);
        p.pop();
    }
    ::printf("\n");
}
//complexidade O(N)
void inverte4a(stack<char>*s){
    queue<char> q;
    while(s->size() > 0){
        q.push(s->top());
        s->pop();
    }
    while(q.size() > 0){
        s->push(q.front());
        q.pop();
    }
}
void inverte4b(stack<char>*s){
    //complexidade O(N)
    stack<char> p1;
    stack<char> p2;
    while(s->size() > 0){
        char c = s->top();
        p1.push(c);
        s->pop();
    }
    while(p1.size() > 0){
        char c = p1.top();
        p2.push(c);
        p1.pop();
    }
    while(p2.size() > 0){
        char c = p2.top();
        s->push(c);
        p2.pop();
    }
}
//complexidade O(N^2)
void inverte4c(stack<char>*s){
    stack<char> p;
    //complexidade O(N)
    while(s->size() > 0){
        char c = s->top();
        s->pop();
        p.push(c);
    }
    //complexidade O(N^2)
    fillQueue(s, &p);
}
void fillQueue(stack<char>*s, stack<char> *p){
    if(p->empty())return;
    char c = p->top();
    p->pop();
    fillQueue(s, p);
    s->push(c);
}