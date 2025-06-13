#include "FilaPont.hpp"
#include <algorithm>
#include <functional>
#include <stdexcept>

FilaPonteiro::FilaPonteiro() : inicio(nullptr), fim(nullptr), tamanho(0) {}

FilaPonteiro::~FilaPonteiro() {
    while (!esta_vazia()) {
        desenfileirar();
    }
}

bool FilaPonteiro::esta_vazia() const {
    return inicio == nullptr;
}

void FilaPonteiro::enfileirar(int valor) {
    NoFila* novo = new NoFila(valor);
    if (esta_vazia()) {
        inicio = novo;
    } else {
        fim->prox = novo;
    }
    fim = novo;
    tamanho++;
}

int FilaPonteiro::desenfileirar() {
    if (esta_vazia()) {
        throw std::runtime_error("Fila vazia!");
    }
    NoFila* temp = inicio;
    int valor = temp->valor;
    inicio = inicio->prox;
    delete temp;
    tamanho--;
    if (inicio == nullptr) {
        fim = nullptr;
    }
    return valor;
}

void FilaPonteiro::heap_sort() {
    if (tamanho <= 1) return;

    // Declara heapify antes de defini-la
    std::function<void(int[], int, int)> heapify;

    heapify = [&heapify](int arr[], int n, int i) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        if (esq < n && arr[esq] > arr[maior]) 
            maior = esq;

        if (dir < n && arr[dir] > arr[maior]) 
            maior = dir;

        if (maior != i) {
            std::swap(arr[i], arr[maior]);
            heapify(arr, n, maior);
        }
    };

    int* temp = new int[tamanho];
    int n = tamanho;
    
    for (int i = 0; i < n; i++) {
        temp[i] = desenfileirar();
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(temp, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(temp[0], temp[i]);
        heapify(temp, i, 0);
    }

    for (int i = 0; i < n; i++) {
        enfileirar(temp[i]);
    }

    delete[] temp;
}