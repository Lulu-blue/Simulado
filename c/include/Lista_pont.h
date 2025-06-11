#ifndef LISTA_PONTEIRO_H
#define LISTA_PONTEIRO_H

typedef struct no_lista {
    int valor;
    struct no_lista *prox;
} NoLista;

typedef struct {
    NoLista *inicio;
    int tamanho;
} ListaPonteiro;

void lista_ponteiro_inicializar(ListaPonteiro *l);
void lista_ponteiro_inserir(ListaPonteiro *l, int valor);
void heap_sort_lista_ponteiro(ListaPonteiro *l);

#endif