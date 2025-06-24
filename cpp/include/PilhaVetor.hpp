#ifndef PILHA_VETOR_HPP
#define PILHA_VETOR_HPP

class PilhaVetor {
private:
    static const int MAX = 1000000;
    int dados[MAX];
    int topo;
    
    void heapify(int arr[], int n, int i);
    
public:
    PilhaVetor();
    bool estaVazia() const;
    bool estaCheia() const;
    void empilhar(int valor);
    int desempilhar();
    void heapSort();
    int getTamanho() const { return topo + 1; }
};

#endif // PILHA_VETOR_H