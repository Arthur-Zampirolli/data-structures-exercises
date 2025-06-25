#include "arvores.hpp"
#include <cctype>
#include <queue>
#include <cmath>
#define UNDEFINED 
NoBin *aloca(char c)
{
    NoBin *no = new NoBin;
    no->chave = c;
    no->dir = no->esq = nullptr;
    return no;
}

auto preordem(NoBin* no) -> void{
    if(!no) return;
    ::printf(" %c ", no->chave);
    preordem(no->esq);
    preordem(no->dir);
}
auto posordem(NoBin* no) -> void{
    if(!no) return;
    posordem(no->esq);
    posordem(no->dir);
    ::printf(" %c ", no->chave);
}
auto inorder(NoBin* no) -> void{
    if(!no) return;
    inorder(no->esq);
    ::printf(" %c ", no->chave);
    inorder(no->dir);
}

auto maior(NoBin *no) -> char
{
    NoBin *temp = no;
    char maior = '\0';
    if(no){
        maior = no->chave;
    }
    while(temp){//complexidade O(LogN)
        ::printf("iterando...\n");
        ::printf("maior %c\n", maior);
        maior = temp->chave;
        temp = temp->dir;
    }
    return maior;
}
auto menor(NoBin *no) -> char
{
    NoBin *temp = no;
    char menor = '\0';
    if(no){
        menor = no->chave;
    }
    while(temp){//complexidade O(LogN)
        ::printf("iterando...\n");
        ::printf("menor %c\n", menor);
        menor = temp->chave;
        temp = temp->esq;
    }
    return menor;
}

auto insere(char chave, NoBin *raiz) -> void
{
    ::printf("Inserindo chave=%c na árvore...\n", chave);
    if (!raiz)
    {
        raiz = aloca(chave);
    }
    else
    {
        if (chave > raiz->chave)
        {
            if (raiz->dir == nullptr)
            {
                raiz->dir = aloca(chave);
            }
            else
            {
                insere(chave, raiz->dir);
            }
        }
        if (chave <= raiz->chave)
        {
            if (raiz->esq == nullptr)
            {
                raiz->esq = aloca(chave);
            }
            else
            {
                insere(chave, raiz->esq);
            }
        }
    }
}
auto remove(NoBin *raiz, char dado) -> void
{
    return;
}
auto imprime(NoBin *raiz) -> void
{
    if (!raiz)
        return;

    imprime(raiz->esq);
    imprime(raiz->dir);
    ::printf("%c ", raiz->chave);


}
auto estritaBin(NoBin *no) -> bool
{
    if(!no) return true;
    if((!no->esq && no->dir) || ((!no->esq && no->dir))) return false;
    if(no->esq && no->dir){
        return estritaBin(no->esq);
        return estritaBin(no->dir);
    }
    if(!no->dir && !no->esq) return true;
}
auto ehPerfeita(NoBin *no) -> bool
{
    //todo no folha tem que estar no mesmo nível e todo no só pode ter ou zero ou 2 filhos
    std::queue<NoBin *> fila;
    std::queue<int> profundidades;
    fila.push(no);
    int depth = 1;
    int maxDepth = 0;
    bool leave = false;
    while(!fila.empty()){//complexidade O(N)
        NoBin *temp = fila.front();
        fila.pop();
        if((temp->esq && !temp->dir)||(!temp->esq && temp->dir)) return false;
        if(temp->esq && temp->dir){
            fila.push(temp->esq);
            fila.push(temp->dir);
            depth++;
        }
        if(!temp->esq && !temp->dir){
            profundidades.push(depth);
            if(depth > maxDepth){
                maxDepth = depth;
                //depth = 1;
            }
        }
    }
    while(!profundidades.empty()){//complexidade O(N)
        auto p = profundidades.front();
        profundidades.pop();
        ::printf("verificando profundidade p = %d com a máxima %d", p, maxDepth);
        if((maxDepth != p)){
            return false;
        }
    }
    return true;
}


auto emNiveis(NoBin *no) -> void
{
    std::queue<NoBin*> fila;
    fila.push(no);
    int nivel = 0;
    int i = 0;
    while(!fila.empty()){//complexidade O(N)
        NoBin* temp = fila.front();
        fila.pop();
        if(!temp){
            ::printf(" * ");
        }
        else{
            ::printf(" %c", temp->chave);
            fila.push(temp->esq);
            fila.push(temp->dir);
        }
    }
    ::printf("\n");
}
auto mostraFila(std::queue<NoBin*> fila) -> void;
auto ehCompleta(NoBin *no) -> bool
{
    //todo no folha tem que estar no mesmo nível e todo no só pode ter ou zero ou 2 filhos
    std::queue<NoBin *> fila;
    fila.push(no);
    int profundidade = 1;
    while(!fila.empty()){//complexidade O(N)
        mostraFila(fila);
        NoBin *temp = fila.front();
        fila.pop();
        if(temp){
            fila.push(temp->esq); 
            fila.push(temp->dir);
        }
        else{
            while(!fila.empty()){//O(N)
                if(fila.front()) return false;
                fila.pop();
            }
        }
    }
    return true;
}

auto mostraFila(std::queue<NoBin*> fila) -> void{
    std::queue<NoBin*> temp;
    while(!fila.empty()){//complexidade O(N)
        if(fila.front()){
            ::printf("%c ", fila.front()->chave);
        }
        temp.push(fila.front());
        fila.pop();
    }
    ::printf("\n");
    while(!temp.empty()){
        fila.push(temp.front());
        temp.pop();
    }
}

auto bstreeRequirements(NoBin*no) -> bool{
    //filhos n podem ser iguais
    //filhos de um lado devem ser > que os de outro
    //O(1)
    if(no){
        if(no->dir && no->esq){
            if(no->esq->chave == no->dir->chave ) return false;
            if((no->esq->chave < no->chave && no->dir->chave < no->chave) || (no->esq->chave > no->chave && no->dir->chave > no->chave)) return false;
        }
    }
    return true;
}

auto ehBinariaBusca(NoBin* no) -> bool{
    if(!no) return true;
    return bstreeRequirements(no);
    ehBinariaBusca(no->dir);
    ehBinariaBusca(no->esq);
}

auto busca(char chave, NoBin *no) -> char {
    //return '\0';
    if(!no) return '\0';
    else if(no->chave == chave) return chave;
    else if(chave > no->chave){
        return busca(chave, no->dir);
    }
    else if(chave < no->chave){
        return busca(chave, no->esq);
    }
}

auto altura(NoBin *no) -> int
{
    if (!no)
        return 0;
    int dir = altura(no->dir);
    int esq = altura(no->esq);
    if(dir > esq){
        return dir + 1;
    }else{
        return esq + 1;
    }
}
auto anterior(char chave, NoBin* no) -> char{
    
    if(!no) return '\0';
    if(no->dir){
        if(no->dir->chave == chave) return no->chave;
    }
    if(no->esq){
        if(no->esq->chave == chave) return no->chave;
    }
    if(chave < no->chave){
        return anterior(chave, no->esq);
    }
    else{
        return anterior(chave, no->dir);
    }
    return '\0';
}
auto posterior(char chave, NoBin* no) -> char{
    if(!no) return '\0';
    if(!no->dir) return '\0';
    if(no->chave == chave) return no->dir->chave;
    if(chave < no->chave){
        return posterior(chave, no->esq);
    }
    else{
        return posterior(chave, no->dir);
    }
    return '\0';
}
auto fator(NoBin* no) ->int{
    if(no){
        return altura(no->esq) - altura(no->dir);
    }
    return 0;
}
auto qualRotacao(NoBin* no) -> void{
    auto limite = 2;
    if(no){
        auto fb = fator(no);
        auto fbDir = fator(no->dir);
        auto fbEsq = fator(no->esq);
        if(fb >= limite){
            if(fbDir < 0){
                ::printf("rotação dupla a esquerda\n");
            }
            else{
                ::printf("rotação a direita\n");
            }
        }   
        if(fb <= - limite){  
            if(fbEsq > 0){
                ::printf("rotação dupla a direita\n");
            }else{
                ::printf("rotação a esquerda\n");
            }
        }
    }
    else{
        ::printf("nenhuma rotação\n");
    }
}

//heap de maximos
auto ehHeap(int* heap, int N) -> bool
{
    for(int i = 0; i < (N-1)/2; i++){//O(N)
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        if((dir < N) && (heap[i] < heap[dir])) return false;
        if((esq < N) && (heap[i] < heap[esq])) return false;
    }
    return true;
}
auto heapify(int* heap, int N, int i) -> void{
    int maior = i;
    int esq = 2*i+1;
    int dir = 2*i+2;
    ::printf("heapify %d %d %d\n", maior, esq, dir);
    if(esq < N && heap[esq] > heap[i]){
        maior = esq;
    }
    if(dir < N && heap[dir] > heap[i]){
        maior = dir;
    }
    if(maior != i){
        //troca
        //std::swap(heap[i], heap[maior]);
        auto temp = heap[i];
        heap[i] = heap[maior];
        heap[maior] = temp;
        //chama heapify
        heapify(heap, N, maior);
    }
}
auto novo(int elemento, int* heap, int N) -> void
{
    heap[N-1] = elemento;
    for (int i = N/2 - 1; i >= 0; i--) {//O(N)
        heapify(heap, N, i);
    }
}

