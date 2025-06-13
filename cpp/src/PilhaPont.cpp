#include "PilhaPont.hpp"
#include <stdexcept>
#include <algorithm>
#include <functional>

PilhaPonteiro::PilhaPonteiro() : topo(nullptr), tamanho(0) {}

PilhaPonteiro::~PilhaPonteiro() {
    while (!esta_vazia()) {
        desempilhar();
    }
}

bool PilhaPonteiro::esta_vazia() const {
    return topo == nullptr;
}

void PilhaPonteiro::empilhar(int valor) {
    NoPilha* novo = new NoPilha(valor);
    novo->prox = topo;
    topo = novo;
    tamanho++;
}

int PilhaPonteiro::desempilhar() {
    if (esta_vazia()) {
        throw std::runtime_error("Pilha vazia!");
    }
    NoPilha* temp = topo;
    int valor = temp->valor;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return valor;
}


void PilhaPonteiro::heap_sort()
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
    int n = tamanho;
    
    for (int i = 0; i < n; i++) temp[i] = desempilhar();
    for (int i = n/2-1; i >= 0; i--) heapify(temp, n, i);
    for (int i = n-1; i > 0; i--) {
        std::swap(temp[0], temp[i]);
        heapify(temp, i, 0);
    }
    for (int i = 0; i < n; i++) empilhar(temp[i]);
    
    delete[] temp;
}