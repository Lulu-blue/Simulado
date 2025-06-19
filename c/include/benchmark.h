#ifndef BENCHMARK_H
#define BENCHMARK_H

#define MAX_ENTRIES 100000

typedef struct {
    int userId;
    int movieId;
    double rating;
    long timestamp;
} Rating;

void carregar_ratings(const char* filename, Rating ratings[], int max);
void executar_benchmark();
void testar_heap_sort_fila_ponteiro(Rating ratings[], int size);
void testar_heap_sort_fila_vetor(Rating ratings[], int size);
void testar_heap_sort_pilha_ponteiro(Rating ratings[], int size);
void testar_heap_sort_pilha_vetor(Rating ratings[], int size);
void testar_heap_sort_lista_ponteiro(Rating ratings[], int size);
void testar_heap_sort_lista_vetor(Rating ratings[], int size);

#endif