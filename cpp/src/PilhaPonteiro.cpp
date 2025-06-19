#include "PilhaPonteiro.hpp"
#include <stdexcept>

PilhaPonteiro::PilhaPonteiro() : topo(nullptr), tamanho(0) {}

PilhaPonteiro::~PilhaPonteiro() {
    while (!estaVazia()) {
        desempilhar();
    }
}

bool PilhaPonteiro::estaVazia() const {
    return topo == nullptr;
}

void PilhaPonteiro::empilhar(int valor) {
    No* novo = new No(valor);
    novo->prox = topo;
    topo = novo;
    tamanho++;
}

int PilhaPonteiro::desempilhar() {
    if (estaVazia()) {
        throw std::runtime_error("Pilha vazia!");
    }
    No* temp = topo;
    int valor = temp->valor;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return valor;
}

void PilhaPonteiro::heapify(int arr[], int n, int i) {
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

void PilhaPonteiro::heapSort() {
    if (tamanho <= 1) return;

    int* temp = new int[tamanho];
    int n = tamanho;
    
    for (int i = 0; i < n; i++) {
        temp[i] = desempilhar();
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(temp, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(temp[0], temp[i]);
        heapify(temp, i, 0);
    }

    for (int i = 0; i < n; i++) {
        empilhar(temp[i]);
    }

    delete[] temp;
}