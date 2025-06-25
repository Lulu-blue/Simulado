#include "../include/benchmark.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdint.h>
#include <string.h>

uint64_t get_current_memory_bytes() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return (uint64_t)usage.ru_maxrss * 1024;
}

void print_memory_usage(uint64_t* prev_memory_bytes) {
    uint64_t current = get_current_memory_bytes();
    uint64_t diff = current - *prev_memory_bytes;
    double diff_kb = (double)diff / 1024.0;
    printf("| Memória: %.2f KB", diff_kb);
    *prev_memory_bytes = current;
}

void carregar_ratings(const char* filename, Rating ratings[], int max_entries) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int i = 0;

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && i < max_entries) {
        if (sscanf(line, "%d,%d,%f,%d",
                  &ratings[i].userId,
                  &ratings[i].movieId,
                  &ratings[i].rating,
                  &ratings[i].timestamp) == 4) {
            i++;
        } else {
            fprintf(stderr, "Formato inválido na linha: %s\n", line);
        }
    }
    fclose(file);
}

void testar_heap_sort_fila_ponteiro(Rating ratings[], int size) {
    FilaPonteiro fila;
    fila_ponteiro_inicializar(&fila);
    
    for (int i = 0; i < size; i++) {
        fila_ponteiro_enfileirar(&fila, (int)(ratings[i].rating * 100));
    }
    
    heap_sort_fila_ponteiro(&fila);

    while (!fila_ponteiro_esta_vazia(&fila)) {
        fila_ponteiro_desenfileirar(&fila);
    }
}

void testar_heap_sort_fila_vetor(Rating ratings[], int size) {
    FilaVetor fila;
    fila_vetor_inicializar(&fila);
    
    for (int i = 0; i < size; i++) {
        fila_vetor_enfileirar(&fila, (int)(ratings[i].rating * 100));
    }
    
    heap_sort_fila_vetor(&fila);
}

void testar_heap_sort_pilha_ponteiro(Rating ratings[], int size) {
    PilhaPonteiro pilha;
    pilha_ponteiro_inicializar(&pilha);
    
    for (int i = 0; i < size; i++) {
        pilha_ponteiro_empilhar(&pilha, (int)(ratings[i].rating * 100));
    }
    
    heap_sort_pilha_ponteiro(&pilha);

    while (!pilha_ponteiro_esta_vazia(&pilha)) {
        pilha_ponteiro_desempilhar(&pilha);
    }
}

void testar_heap_sort_pilha_vetor(Rating ratings[], int size) {
    PilhaVetor pilha;
    pilha_vetor_inicializar(&pilha);
    
    for (int i = 0; i < size; i++) {
        pilha_vetor_empilhar(&pilha, (int)(ratings[i].rating * 100));
    }
    
    heap_sort_pilha_vetor(&pilha);
}

void testar_heap_sort_lista_ponteiro(Rating ratings[], int size) {
    ListaPonteiro lista;
    lista_ponteiro_inicializar(&lista);
    
    for (int i = 0; i < size; i++) {
        lista_ponteiro_inserir(&lista, (int)(ratings[i].rating * 100));
    }
    
    heap_sort_lista_ponteiro(&lista);

    NoLista* atual = lista.inicio;
    while (atual != NULL) {
        NoLista* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

void testar_heap_sort_lista_vetor(Rating ratings[], int size) {
    ListaVetor lista;
    lista_vetor_inicializar(&lista);
    
    for (int i = 0; i < size; i++) {
        lista_vetor_inserir(&lista, (int)(ratings[i].rating * 100));
    }
    
    heap_sort_lista_vetor(&lista);
}

void executar_benchmark() {
    Rating* ratings = malloc(MAX_ENTRIES * sizeof(Rating));
    if (!ratings) {
        fprintf(stderr, "Falha ao alocar memória para ratings\n");
        exit(EXIT_FAILURE);
    }

    int tamanhos[] = {100, 1000, 10000, 100000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Benchmark Heap Sort ===\n");
    carregar_ratings("data/ratings.csv", ratings, MAX_ENTRIES);

    for (int i = 0; i < num_tamanhos; i++) {
        printf("\nTamanho: %d elementos\n", tamanhos[i]);
        printf("---------------------------------------------\n");

        uint64_t mem_base = get_current_memory_bytes();
        clock_t inicio, fim;
        double tempo;

        inicio = clock();
        testar_heap_sort_fila_ponteiro(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Fila Ponteiro   | Tempo: %.5f s ", tempo);
        print_memory_usage(&mem_base);
        printf("\n");

        inicio = clock();
        testar_heap_sort_fila_vetor(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Fila Vetor      | Tempo: %.5f s ", tempo);
        print_memory_usage(&mem_base);
        printf("\n");

        inicio = clock();
        testar_heap_sort_pilha_ponteiro(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Pilha Ponteiro  | Tempo: %.5f s ", tempo);
        print_memory_usage(&mem_base);
        printf("\n");

        inicio = clock();
        testar_heap_sort_pilha_vetor(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Pilha Vetor     | Tempo: %.5f s ", tempo);
        print_memory_usage(&mem_base);
        printf("\n");

        inicio = clock();
        testar_heap_sort_lista_ponteiro(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Lista Ponteiro  | Tempo: %.5f s ", tempo);
        print_memory_usage(&mem_base);
        printf("\n");

        inicio = clock();
        testar_heap_sort_lista_vetor(ratings, tamanhos[i]);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Lista Vetor     | Tempo: %.5f s ", tempo);
        print_memory_usage(&mem_base);
        printf("\n");
    }

    free(ratings);
}
