#include "ListaPonteiro.hpp"
#include <stdexcept>

ListaPonteiro::ListaPonteiro() : inicio(nullptr), tamanho(0) {}

ListaPonteiro::~ListaPonteiro() {
    No* atual = inicio;
    while (atual != nullptr) {
        No* proximo = atual->prox;
        delete atual;
        atual = proximo;
    }
}

void ListaPonteiro::inserir(int valor) {
    No* novo = new No(valor);
    novo->prox = inicio;
    inicio = novo;
    tamanho++;
}

void ListaPonteiro::heapify(int arr[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior]) maior = esq;
    if (dir < n && arr[dir] > arr[maior]) maior = dir;

    if (maior != i) {
        std::swap(arr[i], arr[maior]);
        heapify(arr, n, maior);
    }
}

void ListaPonteiro::heapSort() {
    if (tamanho <= 1) return;

    int* temp = new int[tamanho];
    No* atual = inicio;
    
    for (int i = 0; i < tamanho; i++) {
        temp[i] = atual->valor;
        atual = atual->prox;
    }

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(temp, tamanho, i);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        std::swap(temp[0], temp[i]);
        heapify(temp, i, 0);
    }

    atual = inicio;
    for (int i = 0; i < tamanho; i++) {
        atual->valor = temp[i];
        atual = atual->prox;
    }

    delete[] temp;
}