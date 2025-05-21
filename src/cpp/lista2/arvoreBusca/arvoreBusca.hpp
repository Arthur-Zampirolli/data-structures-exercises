#ifndef ARVORE_BUSCA
#define ARVORE_BUSCA



template<typename T>
struct ArvoreBusca{
    template<typename X>
    struct No{
        X dado;
        struct No<T>* dir;
        struct No<T>* esq;
    };
    No<T> * raiz;
    No<T> * cursor;
    int N;
    ArvoreBusca(){
        this->N = 0;
    }
    No<T> *novoNo(T dado){
        No<T> *novo = new No<T>;
        novo->dado = dado;
        novo->dir = novo->esq = 0;
        ::printf("novo node criado!\n");
        ::printf("dados do node %d, %d, %d...\n", novo->dado, novo->dir, novo->esq);
        return novo;
    }
    No<T> *getRaiz(){
        return this->raiz;
    }
    auto insere(T dado, No<T> *r){
        ::printf("Inserindo valor na arvore...\n");
        No<T> *novo = novoNo(dado);
        
        if(this->N == 0){
            ::printf("inserindo novo node...\n");
            r = novo;
            this->N++;
            return r;
        }
        if(dado >= r->dado){
            ::printf("inserindo na direita...\n");
            return insere(dado, r->dir);
        }
        else{
            ::printf("inserindo na esquerda...\n");
            return insere(dado, r->esq);
        }
        return r;
    }
    auto imprime(No<T> *r){
        if(r){
            std::printf("%d", r->dado);
            return;
        }
        imprime(r->dir);
        imprime(r->esq);
    }
};

#endif