#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP
#include "Rating.hpp"
#include "FilaPont.hpp"
#include "FilaVetor.hpp"
#include "PilhaPont.hpp"
#include "PilhaVetor.hpp"
#include "ListaPont.hpp"
#include "ListaVetor.hpp"
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <stdexcept>

class Benchmark
{
    private:
        static const int MAX_ENTRIES = 1000000;
        std::vector<Rating> ratings;

        void carregar_ratings(const std::string& filename);
        
    public:
        Benchmark();
        void executar();
        
        template<typename T>
        void testar_heap_sort(const std::vector<Rating>& ratings, int size, const std::string& nome);
};

#endif