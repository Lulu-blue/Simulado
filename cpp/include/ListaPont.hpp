#ifndef LISTA_PONTEIRO_HPP
#define LISTA_PONTEIRO_HPP

class ListaPonteiro
{
    private:
        struct NoLista
        {
            int valor;
            NoLista* prox;
            NoLista(int v) : valor(v), prox(nullptr) {}
        };

        NoLista* inicio;
        int tamanho;

    public:
        ListaPonteiro();
        ~ListaPonteiro();
        void inserir(int valor);
        void heap_sort();
        int get_tamanho() const { return tamanho; }
};

#endif