#ifndef PILHA_PONTEIRO_H
#define PILHA_PONTEIRO_H

typedef struct no_pilha {
    int valor;
    struct no_pilha *prox;
} NoPilha;

typedef struct {
    NoPilha *topo;
    int tamanho;
} PilhaPonteiro;

void pilha_ponteiro_inicializar(PilhaPonteiro *p);
int pilha_ponteiro_esta_vazia(PilhaPonteiro *p);
void pilha_ponteiro_empilhar(PilhaPonteiro *p, int valor);
int pilha_ponteiro_desempilhar(PilhaPonteiro *p);
void heap_sort_pilha_ponteiro(PilhaPonteiro *p);

#endif