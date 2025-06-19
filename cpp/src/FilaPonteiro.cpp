#include "FilaPonteiro.hpp"
#include <stdexcept>
#include <vector>

FilaPonteiro::FilaPonteiro() : inicio(nullptr), fim(nullptr), tamanho(0) {}

FilaPonteiro::~FilaPonteiro() {
    while (!estaVazia()) {
        desenfileirar();
    }
}

bool FilaPonteiro::estaVazia() const {
    return inicio == nullptr;
}

void FilaPonteiro::enfileirar(int valor) {
    No* novo = new No(valor);
    if (estaVazia()) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
    tamanho++;
}

int FilaPonteiro::desenfileirar() {
    if (estaVazia()) {
        throw std::runtime_error("Fila vazia!");
    }
    No* temp = inicio;
    int valor = temp->valor;
    inicio = inicio->prox;
    if (inicio == nullptr) {
        fim = nullptr;
    }
    delete temp;
    tamanho--;
    return valor;
}

void FilaPonteiro::heapify(int arr[], int n, int i) {
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

void FilaPonteiro::heapSort() {
    if (tamanho <= 1) return;

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