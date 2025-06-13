#include <stdio.h>
#include <stdlib.h>
#include "Pilha_pont.h"

void pilha_ponteiro_inicializar(PilhaPonteiro *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int pilha_ponteiro_esta_vazia(PilhaPonteiro *p) {
    return p->topo == NULL;
}

void pilha_ponteiro_empilhar(PilhaPonteiro *p, int valor) {
    NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
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

void heap_sort_pilha_ponteiro(PilhaPonteiro *p) {
    if (p->tamanho <= 1) return;

    int *temp = (int *)malloc(p->tamanho * sizeof(int));
    if (!temp) {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    int n = p->tamanho;
    
    for (int i = 0; i < n; i++) {
        temp[i] = pilha_ponteiro_desempilhar(p);
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
        pilha_ponteiro_empilhar(p, temp[i]);
    }

    free(temp);
}