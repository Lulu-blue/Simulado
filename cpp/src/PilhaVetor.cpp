#include "PilhaVetor.hpp"
#include <stdexcept>

PilhaVetor::PilhaVetor() : topo(-1) {}

bool PilhaVetor::estaVazia() const {
    return topo == -1;
}

bool PilhaVetor::estaCheia() const {
    return topo == MAX - 1;
}

void PilhaVetor::empilhar(int valor) {
    if (estaCheia()) {
        throw std::runtime_error("Pilha cheia!");
    }
    dados[++topo] = valor;
}

int PilhaVetor::desempilhar() {
    if (estaVazia()) {
        throw std::runtime_error("Pilha vazia!");
    }
    return dados[topo--];
}

void PilhaVetor::heapify(int arr[], int n, int i) {
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

void PilhaVetor::heapSort() {
    int n = getTamanho();
    if (n <= 1) return;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(dados, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(dados[0], dados[i]);
        heapify(dados, i, 0);
    }
}