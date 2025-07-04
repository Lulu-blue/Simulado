#include <stdio.h>
#include <stdlib.h>
#include "Fila_pont.h"

void fila_ponteiro_inicializar(FilaPonteiro *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

int fila_ponteiro_esta_vazia(FilaPonteiro *f) { 
    return (f->inicio == NULL);
}

void fila_ponteiro_enfileirar(FilaPonteiro *f, int valor) {
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (fila_ponteiro_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;
    f->tamanho++;
}

int fila_ponteiro_desenfileirar(FilaPonteiro *f) {
    if (fila_ponteiro_esta_vazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }

    NoFila *temp = f->inicio;
    int valor = temp->valor;
    f->inicio = f->inicio->prox;
    free(temp);
    f->tamanho--;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    return valor;
}

static void heapify(int arr[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior]) 
        maior = esq;

    if (dir < n && arr[dir] > arr[maior]) 
        maior = dir;

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify(arr, n, maior);
    }
}

void heap_sort_fila_ponteiro(FilaPonteiro *f) {
    if (f->tamanho <= 1) return;

    int *temp = (int *)malloc(f->tamanho * sizeof(int));
    if (!temp) {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    int n = f->tamanho;
    
    for (int i = 0; i < n; i++) {
        temp[i] = fila_ponteiro_desenfileirar(f);
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(temp, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp_val = temp[0];
        temp[0] = temp[i];
        temp[i] = temp_val;
        heapify(temp, i, 0);
    }

    for (int i = 0; i < n; i++) {
        fila_ponteiro_enfileirar(f, temp[i]);
    }

    free(temp);
}