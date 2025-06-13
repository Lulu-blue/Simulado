#include "ListaPont.hpp"
#include <algorithm>
#include <functional>

ListaPonteiro::ListaPonteiro() : inicio(nullptr), tamanho(0) {}

ListaPonteiro::~ListaPonteiro() {
    NoLista* atual = inicio;
    while (atual != nullptr) {
        NoLista* proximo = atual->prox;
        delete atual;
        atual = proximo;
    }
}

void ListaPonteiro::inserir(int valor) {
    NoLista* novo = new NoLista(valor);
    novo->prox = inicio;
    inicio = novo;
    tamanho++;
}

void ListaPonteiro::heap_sort()
{
    if (tamanho <= 1) return;

    std::function<void(int[], int, int)> heapify;
    
    heapify = [&heapify](int arr[], int n, int i) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        if (esq < n && arr[esq] > arr[maior]) maior = esq;
        if (dir < n && arr[dir] > arr[maior]) maior = dir;

        if (maior != i) {
            std::swap(arr[i], arr[maior]);
            heapify(arr, n, maior);
        }
    };

    int* temp = new int[tamanho];
    NoLista* atual = inicio;
    
    for (int i = 0; i < tamanho; i++) {
        temp[i] = atual->valor;
        atual = atual->prox;
    }
    for (int i = tamanho/2-1; i >= 0; i--) heapify(temp, tamanho, i);
    for (int i = tamanho-1; i > 0; i--) {
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