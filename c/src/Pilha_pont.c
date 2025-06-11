#include <stdio.h>
#include <stdlib.h>
#include "../include/Pilha_pont.h"

void pilha_ponteiro_inicializar(PilhaPonteiro *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int pilha_ponteiro_esta_vazia(PilhaPonteiro *p) {
    return p->topo == NULL;
}

void pilha_ponteiro_empilhar(PilhaPonteiro *p, int valor) {
    NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

int pilha_ponteiro_desempilhar(PilhaPonteiro *p) {
    if (pilha_ponteiro_esta_vazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    NoPilha *temp = p->topo;
    int valor = temp->valor;
    p->topo = p->topo->prox;
    free(temp);
    p->tamanho--;
    return valor;
}

void heap_sort_pilha_ponteiro(PilhaPonteiro *p) {
    int *temp = (int *)malloc(p->tamanho * sizeof(int));
    int n = p->tamanho;
    
    // Extrai elementos
    for (int i = 0; i < n; i++) {
        temp[i] = pilha_ponteiro_desempilhar(p);
    }
    
    // Ordenação Heap Sort
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Heapify
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        
        if (esq < n && temp[esq] > temp[maior]) maior = esq;
        if (dir < n && temp[dir] > temp[maior]) maior = dir;
        
        if (maior != i) {
            int swap = temp[i];
            temp[i] = temp[maior];
            temp[maior] = swap;
        }
    }
    
    // Reinsere ordenado
    for (int i = 0; i < n; i++) {
        pilha_ponteiro_empilhar(p, temp[i]);
    }
    
    free(temp);
}