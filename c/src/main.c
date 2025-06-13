#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
    double rating;
    long timestamp;
} Rating;

void carregar_ratings(const char* filename, Rating ratings[], int max) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir arquivo %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        fclose(file);
        fprintf(stderr, "Erro ao ler cabeçalho\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (count < max && fscanf(file, "%d,%d,%lf,%ld",
           &ratings[count].userId, &ratings[count].movieId,
           &ratings[count].rating, &ratings[count].timestamp) == 4) {
        count++;
    }
    
    fclose(file);
    printf("Carregados %d registros\n\n", count);
}

// [Manter as funções de teste existentes, mas adicionar verificações de erro]

int main() {
    Rating* ratings = malloc(MAX_ENTRIES * sizeof(Rating));
    if (!ratings) {
        fprintf(stderr, "Falha ao alocar memória para ratings\n");
        return EXIT_FAILURE;
    }

    int tamanhos[] = {100, 1000, 10000, 100000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Benchmark Heap Sort ===\n");
    carregar_ratings("ratings.csv", ratings, MAX_ENTRIES);

    for (int i = 0; i < num_tamanhos; i++) {
        printf("\nTestando com %d elementos:\n", tamanhos[i]);

        if (tamanhos[i] <= 100000) {  // Limitar testes para estruturas menores
            testar_heap_sort_fila_ponteiro(ratings, tamanhos[i]);
            testar_heap_sort_pilha_ponteiro(ratings, tamanhos[i]);
            testar_heap_sort_lista_ponteiro(ratings, tamanhos[i]);
        }
        
        testar_heap_sort_fila_vetor(ratings, tamanhos[i]);
        testar_heap_sort_pilha_vetor(ratings, tamanhos[i]);
        testar_heap_sort_lista_vetor(ratings, tamanhos[i]);
    }

    free(ratings);
    return 0;
}