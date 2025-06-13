#ifndef LISTA_VETOR_HPP
#define LISTA_VETOR_HPP

#define MAX 100000

class ListaVetor
{
    private:
        int dados[MAX];
        int tamanho;

    public:
        ListaVetor();
        void inserir(int valor);
        void heap_sort();
        int get_tamanho() const { return tamanho; }
};

#endif