#ifndef PILHA_VETOR_H
#define PILHA_VETOR_H

#define MAX 100000

typedef struct {
    int dados[MAX];
    int topo;
} PilhaVetor;

void pilha_vetor_inicializar(PilhaVetor *p);
int pilha_vetor_esta_vazia(PilhaVetor *p);
int pilha_vetor_esta_cheia(PilhaVetor *p);
void pilha_vetor_empilhar(PilhaVetor *p, int valor);
int pilha_vetor_desempilhar(PilhaVetor *p);
void heap_sort_pilha_vetor(PilhaVetor *p);

#endif