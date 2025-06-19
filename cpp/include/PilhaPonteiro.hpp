#ifndef PILHA_PONTEIRO_HPP
#define PILHA_PONTEIRO_HPP

class PilhaPonteiro {
private:
    struct No {
        int valor;
        No* prox;
        No(int v) : valor(v), prox(nullptr) {}
    };
    
    No* topo;
    int tamanho;
    
    void heapify(int arr[], int n, int i);
    
public:
    PilhaPonteiro();
    ~PilhaPonteiro();
    bool estaVazia() const;
    void empilhar(int valor);
    int desempilhar();
    void heapSort();
    int getTamanho() const { return tamanho; }
};

#endif 