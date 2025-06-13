#ifndef PILHA_VETOR_HPP
#define PILHA_VETOR_HPP

#define MAX 100000

class PilhaVetor
{
    private:
        int dados[MAX];
        int topo;

    public:
        PilhaVetor();
        bool esta_vazia() const;
        bool esta_cheia() const;
        void empilhar(int valor);
        int desempilhar();
        void heap_sort();
        int get_tamanho() const { return topo + 1; }
};

#endif