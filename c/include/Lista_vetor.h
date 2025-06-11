#ifndef LISTA_VETOR_H
#define LISTA_VETOR_H

#define MAX 10000

typedef struct {
    int dados[MAX];
    int tamanho;
} ListaVetor;

void lista_vetor_inicializar(ListaVetor *l);
void lista_vetor_inserir(ListaVetor *l, int valor);
void heap_sort_lista_vetor(ListaVetor *l);

#endif