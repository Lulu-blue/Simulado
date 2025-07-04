#ifndef HEAP_SORT_BENCHMARK_HPP
#define HEAP_SORT_BENCHMARK_HPP

#include <vector>
#include <string>
#include <cstdint> 

struct Rating {
    int userId;
    int movieId;
    double rating;
    long timestamp;
};

class HeapSortBenchmark {
private:
    static const int MAX_ENTRIES = 1000000;
    std::vector<Rating> ratings;
    const std::vector<int> sizes = {100, 1000, 10000, 100000, 1000000};
    
    void loadRatings(const std::string& filename);
    uint64_t getMemoryUsageBytes();
    void printResults(const std::string& structureName, double time, double memoryUsedKB);  
    void testFilaPonteiro(int size);
    void testFilaVetor(int size);
    void testPilhaPonteiro(int size);
    void testPilhaVetor(int size);
    void testListaPonteiro(int size);
    void testListaVetor(int size);
    
public:
    HeapSortBenchmark();
    void run();
};

#endif