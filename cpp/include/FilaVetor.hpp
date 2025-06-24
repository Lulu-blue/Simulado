#ifndef FILA_VETOR_HPP
#define FILA_VETOR_HPP

class FilaVetor {
private:
    static const int MAX = 1000000;
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
    
    void heapify(int arr[], int n, int i);
    
public:
    FilaVetor();
    bool estaVazia() const;
    bool estaCheia() const;
    void enfileirar(int valor);
    int desenfileirar();
    void heapSort();
    int getTamanho() const { return tamanho; }
};

#endif 