#ifndef FILA_PONTEIRO_HPP
#define FILA_PONTEIRO_HPP

#include <functional>  // Para std::function
class FilaPonteiro
{
    private:
        struct NoFila
        {
            int valor;
            NoFila* prox;
            NoFila(int v) : valor(v), prox(nullptr) {}
        };

        NoFila* inicio;
        NoFila* fim;
        int tamanho;

    public:
        FilaPonteiro();
        ~FilaPonteiro();
        bool esta_vazia() const;
        void enfileirar(int valor);
        int desenfileirar();
        void heap_sort();
        int get_tamanho() const { return tamanho; }
};

#endif