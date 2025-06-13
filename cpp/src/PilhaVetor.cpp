#include "PilhaVetor.hpp"
#include <stdexcept>
#include <algorithm>
#include <functional>

PilhaVetor::PilhaVetor() : topo(-1) {}

bool PilhaVetor::esta_vazia() const {
    return topo == -1;
}

bool PilhaVetor::esta_cheia() const {
    return topo == MAX - 1;
}

void PilhaVetor::empilhar(int valor) {
    if (esta_cheia()) {
        throw std::runtime_error("Pilha cheia!");
    }
    dados[++topo] = valor;
}

int PilhaVetor::desempilhar() {
    if (esta_vazia()) {
        throw std::runtime_error("Pilha vazia!");
    }
    return dados[topo--];
}

void PilhaVetor::heap_sort()
{
    if (topo + 1 <= 1) return;

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

    int temp[MAX];
    int n = topo + 1;
    
    for (int i = 0; i < n; i++) temp[i] = dados[i];
    for (int i = n/2-1; i >= 0; i--) heapify(temp, n, i);
    for (int i = n-1; i > 0; i--) {
        std::swap(temp[0], temp[i]);
        heapify(temp, i, 0);
    }
    for (int i = 0; i < n; i++) dados[i] = temp[i];
}