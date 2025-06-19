#include "../include/benchmark.h"
#include <time.h>
#include <stdio.h> 

void executar_benchmark() {
    Rating ratings[MAX_ENTRIES];
    int tamanhos[] = {100, 1000, 10000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Benchmark Heap Sort ===\n");
    carregar_ratings("ratings.csv", ratings, MAX_ENTRIES);

    for (int i = 0; i < num_tamanhos; i++) {
        printf("\nTestando com %d elementos:\n", tamanhos[i]);

        clock_t inicio, fim;
        double tempo;

        if (tamanhos[i] <= 100000) {
            inicio = clock();
            testar_heap_sort_fila_ponteiro(ratings, tamanhos[i]);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Fila Ponteiro: %.5f segundos\n", tempo);

            inicio = clock();
            testar_heap_sort_pilha_ponteiro(ratings, tamanhos[i]);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Pilha Ponteiro: %.5f segundos\n", tempo);

            inicio = clock();
            testar_heap_sort_lista_ponteiro(ratings, tamanhos[i]);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("Lista Ponteiro: %.5f segundos\n", tempo);
        }

        inicio = clock();
        testar_heap_sort_fila_vetor(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Fila Vetor: %.5f segundos\n", tempo);

        inicio = clock();
        testar_heap_sort_pilha_vetor(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Pilha Vetor: %.5f segundos\n", tempo);

        inicio = clock();
        testar_heap_sort_lista_vetor(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Lista Vetor: %.5f segundos\n", tempo);
    }
}