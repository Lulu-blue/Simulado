#include <stdio.h>
#include <stdlib.h>
#include "../include/Lista_vetor.h"

void lista_vetor_inicializar(ListaVetor *l) {
    l->tamanho = 0;
}

void lista_vetor_inserir(ListaVetor *l, int valor) {
    if (l->tamanho >= MAX) {
        printf("Lista cheia!\n");
        return;
    }
    l->dados[l->tamanho++] = valor;
}

void heap_sort_lista_vetor(ListaVetor *l) {
    int n = l->tamanho;
    
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        
        if (esq < n && l->dados[esq] > l->dados[maior]) maior = esq;
        if (dir < n && l->dados[dir] > l->dados[maior]) maior = dir;
        
        if (maior != i) {
            int temp = l->dados[i];
            l->dados[i] = l->dados[maior];
            l->dados[maior] = temp;
        }
    }
    
    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        int temp = l->dados[0];
        l->dados[0] = l->dados[i];
        l->dados[i] = temp;
        
        // Heapify reduced heap
        int maior = 0;
        int esq = 1;
        int dir = 2;
        
        if (esq < i && l->dados[esq] > l->dados[maior]) maior = esq;
        if (dir < i && l->dados[dir] > l->dados[maior]) maior = dir;
        
        if (maior != 0) {
            int temp = l->dados[0];
            l->dados[0] = l->dados[maior];
            l->dados[maior] = temp;
        }
    }
}