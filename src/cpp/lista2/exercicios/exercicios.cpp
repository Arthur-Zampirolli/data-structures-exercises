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
void exercicio5a(){
    std::queue<char> q; 
    q.push('A'); 
    q.push('B'); 
    q.push('C'); 
    imprimeFila(q);
    inverte5a(&q);
    imprimeFila(q);

}
void exercicio5b(){
    std::queue<char> q; 
    q.push('A'); 
    q.push('B'); 
    q.push('C');
    imprimeFila(q); 
    inverte5b(&q); 
    imprimeFila(q);
}



void exercicio6(){
    PilhaMin p;
    p.empilha(2);
    p.empilha(3);
    p.empilha(4);
    p.empilha(5);
    p.empilha(6);
    p.empilha(1);
    ::printf("valor minimo: %d\n", p.obterMinimo());
    p.imprime();
    p.desempilha();
    p.imprime();
    ::printf("valor minimo: %d\n", p.obterMinimo());
    
}
void exercicio7(){
// Entrada: “((A+B)*(C-(F/D)))” 
// Saída: “AB+CFD/-*” 
    string exp = "((A+B)*(C-(F/D)))";
    if(!checkExpBalance(exp))return;

    // pilha s deve estar invertida 
}
/*funcoes auxiliares dos exercicios 4 pra frente*/
bool checkExpBalance(string e){
    int lp = 0;
    int rp = 0;
    int i = 0;
    while(i < e.length()){
        if(e[i] == '('){
            lp++;
        }
        if(e[i] == ')'){
            rp++;
        }
        i++;
    }
    return rp == lp;
}
char toPoloneseNotation(string e){
    stack<char> p;
    int i = 0;
    while(i < e.length()){
        if(e[i]!=' '){}
        i++;
    }
    return 'a';
}

void imprimeFila(queue<char> f){
    while(f.size() > 0){
        :: printf("%c ", f.front());
        f.pop();
    }
    ::printf("\n");
}

void imprimeStack(stack<char> p){
    // if(p.empty()) return;
    // char c = p.top();
    // p.pop();
    // imprimeStack(p);
    // std::printf(" %c ", c);
    // p.push(c);
    while(p.size() > 0){
        char c = p.top();
        ::printf(" %c ", c);
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

void inverte5a(queue<char> *s){
//inverter usando uma Pilha 
    stack<char> p;
    while(s->size() > 0){
        p.push(s->front());
        s->pop();
    }
    while(p.size() > 0){
        s->push(p.top());
        p.pop();
    }
}
//complexidade de O(N^2)
void inverte5b(queue<char> *f){
    //inverter usando duas filas 
    std::queue<char> f1; // primeira fila auxiliar 
    std::queue<char> f2; // segunda fila auxiliar 
    int N = f->size();
    while(f->size() > 0){
        char c = f->front();
        f->pop();
        f1.push(c);
    }
    //complexidade de O(N^2)
    while(f2.size() < N){
        f2.push(pegaUltimo(&f1));
    }
    while(f2.size() > 0){
        f->push(f2.front());
        f2.pop();
    }
}
char pegaUltimo(queue<char> *f){
    int i = 0;
    while(i < f->size()- 1){
        char c = f->front();
        f->pop();
        f->push(c);
        i++;
    }
    char c = f->front();
    f->pop();
    return c;
}

void fillQueue(stack<char>*s, stack<char> *p){
    if(p->empty())return;
    char c = p->top();
    p->pop();
    fillQueue(s, p);
    s->push(c);
}