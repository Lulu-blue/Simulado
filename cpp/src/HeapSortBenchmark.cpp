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
#include <cstdint>

#ifdef __linux__
#include <sys/resource.h>
#elif _WIN32
#include <windows.h>
#include <psapi.h>
#endif

HeapSortBenchmark::HeapSortBenchmark() {
    loadRatings("ratings.csv");
}

uint64_t HeapSortBenchmark::getMemoryUsageBytes() {
#ifdef __linux__
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return static_cast<uint64_t>(usage.ru_maxrss) * 1024; // Convert KB to bytes
#elif _WIN32
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return pmc.WorkingSetSize; // Already in bytes
#else
    return 0; // Not supported
#endif
}

void HeapSortBenchmark::printResults(const std::string& structureName, double time, double memoryUsedKB) {
    std::cout << structureName << " | Tempo: " 
              << std::fixed << std::setprecision(5) << time << " s"
              << " | Memória: " << std::fixed << std::setprecision(2) << memoryUsedKB << " KB\n";
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
    std::cout << "Estrutura         | Tempo (segundos) | Memória (KB)\n";
    std::cout << "--------------------------------------------------\n";
    
    for (int size : sizes) {
        std::cout << "\nTamanho: " << size << " elementos\n";
        std::cout << "--------------------------------------------------\n";
        
        testFilaPonteiro(size);
        testFilaVetor(size);
        testPilhaPonteiro(size);
        testPilhaVetor(size);
        testListaPonteiro(size);
        testListaVetor(size);
    }
}

void HeapSortBenchmark::testFilaPonteiro(int size) {
    uint64_t beforeMem = getMemoryUsageBytes();
    FilaPonteiro fila;
    for (int i = 0; i < size; i++) {
        fila.enfileirar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    fila.heapSort();
    clock_t fim = clock();
    uint64_t afterMem = getMemoryUsageBytes();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    double memoryKB = static_cast<double>(afterMem - beforeMem) / 1024.0;
    printResults("Fila (Ponteiro)  ", tempo_seg, memoryKB);
}

void HeapSortBenchmark::testFilaVetor(int size) {
    uint64_t beforeMem = getMemoryUsageBytes();
    FilaVetor fila;
    for (int i = 0; i < size; i++) {
        fila.enfileirar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    fila.heapSort();
    clock_t fim = clock();
    uint64_t afterMem = getMemoryUsageBytes();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    double memoryKB = static_cast<double>(afterMem - beforeMem) / 1024.0;
    printResults("Fila (Vetor)     ", tempo_seg, memoryKB);
}

void HeapSortBenchmark::testPilhaPonteiro(int size) {
    uint64_t beforeMem = getMemoryUsageBytes();
    PilhaPonteiro pilha;
    for (int i = 0; i < size; i++) {
        pilha.empilhar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    pilha.heapSort();
    clock_t fim = clock();
    uint64_t afterMem = getMemoryUsageBytes();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    double memoryKB = static_cast<double>(afterMem - beforeMem) / 1024.0;
    printResults("Pilha (Ponteiro) ", tempo_seg, memoryKB);
}

void HeapSortBenchmark::testPilhaVetor(int size) {
    uint64_t beforeMem = getMemoryUsageBytes();
    PilhaVetor pilha;
    for (int i = 0; i < size; i++) {
        pilha.empilhar(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    pilha.heapSort();
    clock_t fim = clock();
    uint64_t afterMem = getMemoryUsageBytes();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    double memoryKB = static_cast<double>(afterMem - beforeMem) / 1024.0;
    printResults("Pilha (Vetor)    ", tempo_seg, memoryKB);
}

void HeapSortBenchmark::testListaPonteiro(int size) {
    uint64_t beforeMem = getMemoryUsageBytes();
    ListaPonteiro lista;
    for (int i = 0; i < size; i++) {
        lista.inserir(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    lista.heapSort();
    clock_t fim = clock();
    uint64_t afterMem = getMemoryUsageBytes();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    double memoryKB = static_cast<double>(afterMem - beforeMem) / 1024.0;
    printResults("Lista (Ponteiro) ", tempo_seg, memoryKB);
}

void HeapSortBenchmark::testListaVetor(int size) {
    uint64_t beforeMem = getMemoryUsageBytes();
    ListaVetor lista;
    for (int i = 0; i < size; i++) {
        lista.inserir(static_cast<int>(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    lista.heapSort();
    clock_t fim = clock();
    uint64_t afterMem = getMemoryUsageBytes();

    double tempo_seg = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
    double memoryKB = static_cast<double>(afterMem - beforeMem) / 1024.0;
    printResults("Lista (Vetor)    ", tempo_seg, memoryKB);
}