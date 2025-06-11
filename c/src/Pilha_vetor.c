#include <stdio.h>
#include <stdlib.h>
#include "../include/Pilha_vetor.h"

void pilha_vetor_inicializar(PilhaVetor *p) {
    p->topo = -1;
}

int pilha_vetor_esta_vazia(PilhaVetor *p) {
    return p->topo == -1;
}

int pilha_vetor_esta_cheia(PilhaVetor *p) {
    return p->topo == MAX - 1;
}

void pilha_vetor_empilhar(PilhaVetor *p, int valor) {
    if (pilha_vetor_esta_cheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->dados[++p->topo] = valor;
}

int pilha_vetor_desempilhar(PilhaVetor *p) {
    if (pilha_vetor_esta_vazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo--];
}

void heap_sort_pilha_vetor(PilhaVetor *p) {
    int n = p->topo + 1;
    
    // Heapify
    for (int i = n / 2 - 1; i >= 0; i--) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        
        if (esq < n && p->dados[esq] > p->dados[maior]) maior = esq;
        if (dir < n && p->dados[dir] > p->dados[maior]) maior = dir;
        
        if (maior != i) {
            int temp = p->dados[i];
            p->dados[i] = p->dados[maior];
            p->dados[maior] = temp;
        }
    }
    
    // Extrair elementos
    for (int i = n - 1; i > 0; i--) {
        int temp = p->dados[0];
        p->dados[0] = p->dados[i];
        p->dados[i] = temp;
        
        // Heapify reduzido
        int maior = 0;
        int esq = 1;
        int dir = 2;
        
        if (esq < i && p->dados[esq] > p->dados[maior]) maior = esq;
        if (dir < i && p->dados[dir] > p->dados[maior]) maior = dir;
        
        if (maior != 0) {
            int temp = p->dados[0];
            p->dados[0] = p->dados[maior];
            p->dados[maior] = temp;
        }
    }
}