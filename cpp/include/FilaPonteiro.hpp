#ifndef FILA_PONTEIRO_HPP
#define FILA_PONTEIRO_HPP

class FilaPonteiro {
private:
    struct No {
        int valor;
        No* prox;
        No(int v) : valor(v), prox(nullptr) {}
    };
    
    No* inicio;
    No* fim;
    int tamanho;
    
    void heapify(int arr[], int n, int i);
    
public:
    FilaPonteiro();
    ~FilaPonteiro();
    bool estaVazia() const;
    void enfileirar(int valor);
    int desenfileirar();
    void heapSort();
    int getTamanho() const { return tamanho; }
};

#endif // FILA_PONTEIRO_H