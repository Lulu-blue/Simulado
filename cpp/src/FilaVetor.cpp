#include "FilaVetor.hpp"
#include <stdexcept>
#include <algorithm>

FilaVetor::FilaVetor() : inicio(0), fim(-1), tamanho(0) {}

bool FilaVetor::estaVazia() const {
    return tamanho == 0;
}

bool FilaVetor::estaCheia() const {
    return tamanho == MAX;
}

void FilaVetor::enfileirar(int valor) {
    if (estaCheia()) {
        throw std::runtime_error("Fila cheia!");
    }
    fim = (fim + 1) % MAX;
    dados[fim] = valor;
    tamanho++;
}

int FilaVetor::desenfileirar() {
    if (estaVazia()) {
        throw std::runtime_error("Fila vazia!");
    }
    int valor = dados[inicio];
    inicio = (inicio + 1) % MAX;
    tamanho--;
    return valor;
}

void FilaVetor::heapify(int arr[], int n, int i) {
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

void FilaVetor::heapSort() {
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