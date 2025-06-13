#include "ListaVetor.hpp"
#include <algorithm>
#include <functional>
#include <stdexcept>

ListaVetor::ListaVetor() : tamanho(0) {}

void ListaVetor::inserir(int valor)
{
    if (tamanho >= MAX) {
        throw std::runtime_error("Lista cheia!");
    }
    dados[tamanho++] = valor;
}

void ListaVetor::heap_sort()
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

    for (int i = tamanho/2-1; i >= 0; i--) heapify(dados, tamanho, i);
    for (int i = tamanho-1; i > 0; i--) {
        std::swap(dados[0], dados[i]);
        heapify(dados, i, 0);
    }
}