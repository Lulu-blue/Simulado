#include "Benchmark.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>

Benchmark::Benchmark() {
    carregar_ratings("ratings.csv");
}

void Benchmark::carregar_ratings(const std::string& filename) {
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
        std::cerr << "Erro: Não foi possível encontrar o arquivo ratings.csv\n";
        throw std::runtime_error("Arquivo não encontrado");
    }

    std::string line;
    std::getline(file, line); // Ignora cabeçalho

    while (ratings.size() < MAX_ENTRIES && std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 4) {
            try {
                int userId = std::stoi(tokens[0]);
                int movieId = std::stoi(tokens[1]);
                double rating = std::stod(tokens[2]);
                long timestamp = std::stol(tokens[3]);
                ratings.emplace_back(userId, movieId, rating, timestamp);
            } catch (...) {
                continue;
            }
        }
    }

    file.close();
    std::cout << "Carregados " << ratings.size() << " registros\n\n";
}

// Especialização para FilaPonteiro
template<>
void Benchmark::testar_heap_sort<FilaPonteiro>(const std::vector<Rating>& ratings, int size, const std::string& nome) {
    FilaPonteiro estrutura;
    for (int i = 0; i < size; i++) {
        estrutura.enfileirar(static_cast<int>(ratings[i].getRating() * 100));
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    estrutura.heap_sort();
    auto fim = std::chrono::high_resolution_clock::now();

    double tempo_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(fim - inicio).count();
    std::cout << std::left << std::setw(20) << nome 
              << std::right << std::setw(6) << size << " elementos: " 
              << std::fixed << std::setprecision(3) << std::setw(8) << tempo_ms << " ms\n";
}

// Especialização para FilaVetor
template<>
void Benchmark::testar_heap_sort<FilaVetor>(const std::vector<Rating>& ratings, int size, const std::string& nome) {
    FilaVetor estrutura;
    for (int i = 0; i < size; i++) {
        estrutura.enfileirar(static_cast<int>(ratings[i].getRating() * 100));
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    estrutura.heap_sort();
    auto fim = std::chrono::high_resolution_clock::now();

    double tempo_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(fim - inicio).count();
    std::cout << std::left << std::setw(20) << nome 
              << std::right << std::setw(6) << size << " elementos: " 
              << std::fixed << std::setprecision(3) << std::setw(8) << tempo_ms << " ms\n";
}

// Especialização para PilhaPonteiro
template<>
void Benchmark::testar_heap_sort<PilhaPonteiro>(const std::vector<Rating>& ratings, int size, const std::string& nome) {
    PilhaPonteiro estrutura;
    for (int i = 0; i < size; i++) {
        estrutura.empilhar(static_cast<int>(ratings[i].getRating() * 100));
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    estrutura.heap_sort();
    auto fim = std::chrono::high_resolution_clock::now();

    double tempo_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(fim - inicio).count();
    std::cout << std::left << std::setw(20) << nome 
              << std::right << std::setw(6) << size << " elementos: " 
              << std::fixed << std::setprecision(3) << std::setw(8) << tempo_ms << " ms\n";
}

// Especialização para PilhaVetor
template<>
void Benchmark::testar_heap_sort<PilhaVetor>(const std::vector<Rating>& ratings, int size, const std::string& nome) {
    PilhaVetor estrutura;
    for (int i = 0; i < size; i++) {
        estrutura.empilhar(static_cast<int>(ratings[i].getRating() * 100));
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    estrutura.heap_sort();
    auto fim = std::chrono::high_resolution_clock::now();

    double tempo_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(fim - inicio).count();
    std::cout << std::left << std::setw(20) << nome 
              << std::right << std::setw(6) << size << " elementos: " 
              << std::fixed << std::setprecision(3) << std::setw(8) << tempo_ms << " ms\n";
}

// Especialização para ListaPonteiro
template<>
void Benchmark::testar_heap_sort<ListaPonteiro>(const std::vector<Rating>& ratings, int size, const std::string& nome) {
    ListaPonteiro estrutura;
    for (int i = 0; i < size; i++) {
        estrutura.inserir(static_cast<int>(ratings[i].getRating() * 100));
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    estrutura.heap_sort();
    auto fim = std::chrono::high_resolution_clock::now();

    double tempo_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(fim - inicio).count();
    std::cout << std::left << std::setw(20) << nome 
              << std::right << std::setw(6) << size << " elementos: " 
              << std::fixed << std::setprecision(3) << std::setw(8) << tempo_ms << " ms\n";
}

// Especialização para ListaVetor
template<>
void Benchmark::testar_heap_sort<ListaVetor>(const std::vector<Rating>& ratings, int size, const std::string& nome) {
    ListaVetor estrutura;
    for (int i = 0; i < size; i++) {
        estrutura.inserir(static_cast<int>(ratings[i].getRating() * 100));
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    estrutura.heap_sort();
    auto fim = std::chrono::high_resolution_clock::now();

    double tempo_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(fim - inicio).count();
    std::cout << std::left << std::setw(20) << nome 
              << std::right << std::setw(6) << size << " elementos: " 
              << std::fixed << std::setprecision(3) << std::setw(8) << tempo_ms << " ms\n";
}

void Benchmark::executar()
{
    std::cout << "=== Benchmark Heap Sort ===\n";
    
    std::vector<int> tamanhos = {100, 1000, 5000, 10000};
    
    for (int tamanho : tamanhos) {
        std::cout << "\nTestando com " << tamanho << " elementos:\n";
        
        testar_heap_sort<FilaPonteiro>(ratings, tamanho, "Fila (ponteiro)");
        testar_heap_sort<FilaVetor>(ratings, tamanho, "Fila (vetor)");
        testar_heap_sort<PilhaPonteiro>(ratings, tamanho, "Pilha (ponteiro)");
        testar_heap_sort<PilhaVetor>(ratings, tamanho, "Pilha (vetor)");
        testar_heap_sort<ListaPonteiro>(ratings, tamanho, "Lista (ponteiro)");
        testar_heap_sort<ListaVetor>(ratings, tamanho, "Lista (vetor)");
    }
}