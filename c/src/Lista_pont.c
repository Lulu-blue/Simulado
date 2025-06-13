#include <stdio.h>
#include <stdlib.h>
#include "Lista_pont.h"

void lista_ponteiro_inicializar(ListaPonteiro *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

void lista_ponteiro_inserir(ListaPonteiro *l, int valor) {
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->tamanho++;
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

void heap_sort_lista_ponteiro(ListaPonteiro *l) {
    if (l->tamanho <= 1) return;

    int *temp = (int *)malloc(l->tamanho * sizeof(int));
    if (!temp) {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    
    NoLista *atual = l->inicio;
    for (int i = 0; i < l->tamanho; i++) {
        temp[i] = atual->valor;
        atual = atual->prox;
    }

    for (int i = l->tamanho / 2 - 1; i >= 0; i--) {
        heapify(temp, l->tamanho, i);
    }

    for (int i = l->tamanho - 1; i > 0; i--) {
        int temp_val = temp[0];
        temp[0] = temp[i];
        temp[i] = temp_val;
        heapify(temp, i, 0);
    }

    atual = l->inicio;
    for (int i = 0; i < l->tamanho; i++) {
        atual->valor = temp[i];
        atual = atual->prox;
    }

    free(temp);
}