#ifndef LISTA_PONTEIRO_HPP
#define LISTA_PONTEIRO_HPP

class ListaPonteiro {
private:
    struct No {
        int valor;
        No* prox;
        No(int v) : valor(v), prox(nullptr) {}
    };
    
    No* inicio;
    int tamanho;
    
    void heapify(int arr[], int n, int i);
    
public:
    ListaPonteiro();
    ~ListaPonteiro();
    void inserir(int valor);
    void heapSort();
    int getTamanho() const { return tamanho; }
};

#endif // LISTA_PONTEIRO_H