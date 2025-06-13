#include <stdio.h>
#include <stdlib.h>
#include "Lista_vetor.h"

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

static void heapify(int arr[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior]) maior = esq;
    if (dir < n && arr[dir] > arr[maior]) maior = dir;

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify(arr, n, maior);
    }
}

void heap_sort_lista_vetor(ListaVetor *l) {
    int n = l->tamanho;
    if (n <= 1) return;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(l->dados, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = l->dados[0];
        l->dados[0] = l->dados[i];
        l->dados[i] = temp;
        heapify(l->dados, i, 0);
    }
}