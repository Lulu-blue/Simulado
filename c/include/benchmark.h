#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "Fila_pont.h"
#include "Fila_vetor.h"
#include "Pilha_pont.h"
#include "Pilha_vetor.h"
#include "Lista_pont.h"
#include "Lista_vetor.h"

#define MAX_ENTRIES 1000000

typedef struct {
    int userId;
    int movieId;
    float rating;
    int timestamp;
} Rating;

void carregar_ratings(const char *filename, Rating ratings[], int max_entries);
void executar_benchmark();
void print_memory_usage();
void testar_heap_sort_fila_ponteiro(Rating ratings[], int size);
void testar_heap_sort_fila_vetor(Rating ratings[], int size);
void testar_heap_sort_pilha_ponteiro(Rating ratings[], int size);
void testar_heap_sort_pilha_vetor(Rating ratings[], int size);
void testar_heap_sort_lista_ponteiro(Rating ratings[], int size);
void testar_heap_sort_lista_vetor(Rating ratings[], int size);

#endif 