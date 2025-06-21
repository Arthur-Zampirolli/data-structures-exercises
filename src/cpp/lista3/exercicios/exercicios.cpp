#include "exercicios.hpp"



void exercicio1b(){
    NoBin * raiz = aloca('b');
    insere('B', raiz);
    insere('a', raiz);
    insere('x', raiz);
    insere('C', raiz);
    insere('z', raiz);
    insere('Z', raiz);
    ::printf("imprimindo nós da árvore em niveis\n");
    emNiveis(raiz);
}

void exercicio1e(){
    NoBin * raiz = aloca('b');
    insere('B', raiz);
    insere('a', raiz);
    insere('x', raiz);
    insere('C', raiz);
    insere('z', raiz);
    insere('Z', raiz);
    auto alt = altura(raiz);
        ::printf("altura do no %c eh %d\n", raiz->chave, alt);

}

void exercicio1f(){
    NoBin * raiz = aloca('b');
    insere('B', raiz);
    insere('a', raiz);
    insere('x', raiz);
    insere('C', raiz);
    insere('z', raiz);
    insere('Z', raiz);
    ::printf("imprimindo nós da árvore em preordem\n");
    preordem(raiz);
}
void exercicio1g(){
    NoBin * raiz = aloca('b');
    insere('B', raiz);
    insere('a', raiz);
    insere('x', raiz);
    insere('C', raiz);
    insere('z', raiz);
    insere('Z', raiz);
    ::printf("imprimindo nós da árvore em pos ordem\n");
    posordem(raiz);
}
void exercicio1h(){
    NoBin * raiz = aloca('b');
    insere('B', raiz);
    insere('a', raiz);
    insere('x', raiz);
    insere('C', raiz);
    insere('z', raiz);
    insere('Z', raiz);
    ::printf("imprimindo nós da árvore em ordem\n");
    inorder(raiz);
}

void exercicio2(){
    //achei desnecessário definir o protótipo desse jeito... podia ter retorno do ponteiro pra tratar raiz vazia dentro da função... '-'
    NoBin * raiz = aloca('b');
    insere('b', raiz);
    ::printf("imprimindo nós da árvore\n");
    imprime(raiz);
    ::printf("\n");
    insere('a', raiz);
    ::printf("imprimindo nós da árvore\n");
    imprime(raiz);
    ::printf("\n");
    insere('x', raiz);
    ::printf("imprimindo nós da árvore\n");
    imprime(raiz);
    ::printf("\n");
    insere('c', raiz);
    ::printf("imprimindo nós da árvore\n");
    imprime(raiz);
    ::printf("\n");
    insere('z', raiz);
    ::printf("imprimindo nós da árvore\n");
    imprime(raiz);
    ::printf("\n");
}
auto exercicio3() -> void{
    NoBin * raiz = aloca('b');
    insere('B', raiz);
    insere('a', raiz);
    insere('x', raiz);
    insere('C', raiz);
    insere('z', raiz);
    insere('Z', raiz);
    auto result = maior(raiz);
    ::printf("Maior valor da árvore: %c\n", result);
    ::printf("imprimindo nós da árvore\n");
    imprime(raiz);
}
auto exercicio4() -> void{
    NoBin * raiz = aloca('b');
    insere('B', raiz);
    insere('a', raiz);
    insere('x', raiz);
    insere('C', raiz);
    insere('z', raiz);
    insere('Z', raiz);
    insere('A', raiz);
    
    auto result = menor(raiz);
    ::printf("Menor valor da árvore: %c\n", result);
    ::printf("imprimindo nós da árvore\n");
    imprime(raiz);
}
auto exercicio5() -> void{
    NoBin * a1 = aloca('b');
    insere('B', a1);
    insere('a', a1);
    insere('x', a1);
    insere('C', a1);
    insere('z', a1);
    insere('Z', a1);
    insere('A', a1);
    
    auto result = ehBinariaBusca(a1);

    NoBin * a2 = aloca('d');
    a2->dir = aloca('x');
    a2->esq = aloca('z');
    a2->esq->dir = aloca('P');

    auto result2 = ehBinariaBusca(a2);
    ::printf("a1=%d e a2=%d\n", result, result2);
}

auto exercicio6() -> void{
    NoBin * a1 = aloca('b');
    insere('B', a1);
    insere('a', a1);
    insere('x', a1);
    insere('C', a1);
    insere('z', a1);
    insere('Z', a1);
    insere('A', a1);
    
    auto result = busca('Z', a1);
    auto a = altura(a1);
    ::printf("a1=%c %d\n", result, a);
    emNiveis(a1);
}

auto exercicio7() -> void{
    NoBin * a1 = aloca('b');
    insere('B', a1);
    insere('a', a1);
    insere('x', a1);
    insere('C', a1);
    insere('z', a1);
    insere('Z', a1);
    insere('A', a1);
    auto result = anterior('x', a1);
    ::printf("anterior result %c\n", result);
}

auto exercicio8() -> void{
    NoBin * a1 = aloca('b');
    insere('B', a1);
    insere('a', a1);
    insere('x', a1);
    insere('C', a1);
    insere('z', a1);
    insere('Z', a1);
    insere('A', a1);
    auto result = posterior('B', a1);
    ::printf("posterior result %c\n", result);
}
