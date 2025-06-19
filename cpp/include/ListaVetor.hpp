#ifndef LISTA_VETOR_HPP
#define LISTA_VETOR_HPP

class ListaVetor {
private:
    static const int MAX = 100000;
    int dados[MAX];
    int tamanho;
    
    void heapify(int arr[], int n, int i);
    
public:
    ListaVetor();
    void inserir(int valor);
    void heapSort();
    int getTamanho() const { return tamanho; }
};

#endif // LISTA_VETOR_H