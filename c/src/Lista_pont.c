#include <stdio.h>
#include <stdlib.h>
#include "../include/Lista_pont.h"

void lista_ponteiro_inicializar(ListaPonteiro *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

void lista_ponteiro_inserir(ListaPonteiro *l, int valor) {
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    novo->valor = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->tamanho++;
}

void heap_sort_lista_ponteiro(ListaPonteiro *l) {
    int *temp = (int *)malloc(l->tamanho * sizeof(int));
    int n = l->tamanho;
    NoLista *atual = l->inicio;
    
    // Extrai elementos
    for (int i = 0; i < n; i++) {
        temp[i] = atual->valor;
        atual = atual->prox;
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
    atual = l->inicio;
    for (int i = 0; i < n; i++) {
        atual->valor = temp[i];
        atual = atual->prox;
    }
    
    free(temp);
}