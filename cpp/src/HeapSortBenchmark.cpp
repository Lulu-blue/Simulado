#include "HeapSortBenchmark.hpp"
#include "FilaPonteiro.hpp"
#include "FilaVetor.hpp"
#include "PilhaPonteiro.hpp"
#include "PilhaVetor.hpp"
#include "ListaPonteiro.hpp"
#include "ListaVetor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <stdexcept>
#include <iomanip>

HeapSortBenchmark::HeapSortBenchmark() {
    loadRatings("ratings.csv");
}

void HeapSortBenchmark::loadRatings(const std::string& filename) {
    std::vector<std::string> paths = {
        filename,
        "../data/ratings.csv",
        "./data/ratings.csv",
        "data/ratings.csv",
        "../ratings.csv"
    };

    std::ifstream file;
    for (const auto& path : paths) {
        file.open(path);
        if (file.is_open()) {
            std::cout << "Arquivo encontrado em: " << path << std::endl;
            break;
        }
    }

    if (!file.is_open()) {
        std::cerr << "Erro: Não foi possível encontrar o arquivo ratings.csv" << std::endl;
        std::cerr << "Procurou em:" << std::endl;
        for (const auto& path : paths) {
            std::cerr << "- " << path << std::endl;
        }
        exit(EXIT_FAILURE);
    }

    std::string line;
    std::getline(file, line);

    while (ratings.size() < MAX_ENTRIES && std::getline(file, line)) {
        std::stringstream ss(line);
        Rating r;
        char comma;
        ss >> r.userId >> comma >> r.movieId >> comma >> r.rating >> comma >> r.timestamp;
        ratings.push_back(r);
    }

    file.close();
    std::cout << "Carregados " << ratings.size() << " registros\n\n";
}

void HeapSortBenchmark::run() {
    std::cout << "=== Benchmark Heap Sort ===\n";
    
    for (int size : sizes) {
        std::cout << "\nTestando com " << size << " elementos:\n";
        
        testFilaPonteiro(size);
        testFilaVetor(size);
        testPilhaPonteiro(size);
        testPilhaVetor(size);
        testListaPonteiro(size);
        testListaVetor(size);
    }
}

void HeapSortBenchmark::testFilaPonteiro(int size) {
    FilaPonteiro fila;
    for (int i = 0; i < size; i++) {
        fila.enfileirar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    fila.heapSort();
    clock_t fim = clock();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Fila (ponteiro) " << size << " elementos: " 
              << std::fixed << std::setprecision(6) << tempo_seg << " s\n";
}

void HeapSortBenchmark::testFilaVetor(int size) {
    FilaVetor fila;
    for (int i = 0; i < size; i++) {
        fila.enfileirar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    fila.heapSort();
    clock_t fim = clock();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Fila (vetor)    " << size << " elementos: " 
              << std::fixed << std::setprecision(6) << tempo_seg << " s\n";
}

void HeapSortBenchmark::testPilhaPonteiro(int size) {
    PilhaPonteiro pilha;
    for (int i = 0; i < size; i++) {
        pilha.empilhar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    pilha.heapSort();
    clock_t fim = clock();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Pilha (ponteiro)" << size << " elementos: " 
              << std::fixed << std::setprecision(6) << tempo_seg << " s\n";
}

void HeapSortBenchmark::testPilhaVetor(int size) {
    PilhaVetor pilha;
    for (int i = 0; i < size; i++) {
        pilha.empilhar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    pilha.heapSort();
    clock_t fim = clock();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Pilha (vetor)   " << size << " elementos: " 
              << std::fixed << std::setprecision(6) << tempo_seg << " s\n";
}

void HeapSortBenchmark::testListaPonteiro(int size) {
    ListaPonteiro lista;
    for (int i = 0; i < size; i++) {
        lista.inserir(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    lista.heapSort();
    clock_t fim = clock();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Lista (ponteiro)" << size << " elementos: " 
              << std::fixed << std::setprecision(6) << tempo_seg << " s\n";
}

void HeapSortBenchmark::testListaVetor(int size) {
    ListaVetor lista;
    for (int i = 0; i < size; i++) {
        lista.inserir(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    lista.heapSort();
    clock_t fim = clock();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    std::cout << "Lista (vetor)   " << size << " elementos: " 
              << std::fixed << std::setprecision(6) << tempo_seg << " s\n";
}