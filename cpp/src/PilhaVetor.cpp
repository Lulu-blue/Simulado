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
    int n = topo + 1;
    if (n <= 1) return;

    // Use iterative heapify
    auto heapify = [](int arr[], int n, int i) {
        while (true) {
            int maior = i;
            int esq = 2 * i + 1;
            int dir = 2 * i + 2;

            if (esq < n && arr[esq] > arr[maior]) maior = esq;
            if (dir < n && arr[dir] > arr[maior]) maior = dir;

            if (maior == i) break;
            
            std::swap(arr[i], arr[maior]);
            i = maior;
        }
    };

    // Build heap
    for (int i = n/2-1; i >= 0; i--) heapify(dados, n, i);
    
    // Extract elements from heap
    for (int i = n-1; i > 0; i--) {
        std::swap(dados[0], dados[i]);
        heapify(dados, i, 0);
    }
}