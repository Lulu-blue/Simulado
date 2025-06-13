#ifndef PILHA_PONTEIRO_HPP
#define PILHA_PONTEIRO_HPP

class PilhaPonteiro
{
private:
        struct NoPilha
        {
            int valor;
            NoPilha* prox;
            NoPilha(int v) : valor(v), prox(nullptr) {}
        };

        NoPilha* topo;
        int tamanho;

    public:
        PilhaPonteiro();
        ~PilhaPonteiro();
        bool esta_vazia() const;
        void empilhar(int valor);
        int desempilhar();
        void heap_sort();
        int get_tamanho() const { return tamanho; }
};

#endif