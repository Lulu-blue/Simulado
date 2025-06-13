#ifndef FILA_VETOR_HPP
#define FILA_VETOR_HPP

#define MAX 10000

class FilaVetor
{
    private:
        int dados[MAX];
        int inicio;
        int fim;
        int tamanho;

    public:
        FilaVetor();
        bool esta_vazia() const;
        bool esta_cheia() const;
        void enfileirar(int valor);
        int desenfileirar();
        void heap_sort();
        int get_tamanho() const { return tamanho; }
};

#endif