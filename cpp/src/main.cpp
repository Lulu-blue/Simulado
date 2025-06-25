#include "HeapSortBenchmark.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

int main() {
    HeapSortBenchmark benchmark;
    benchmark.run();
    return 0;
}