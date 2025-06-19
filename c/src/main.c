
#include "Fila_pont.h"
#include "Fila_vetor.h"
#include "Pilha_pont.h"
#include "Pilha_vetor.h"
#include "Lista_pont.h"
#include "Lista_vetor.h"
#include "../include/benchmark.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


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

    NoLista *atual = lista.inicio;
    while (atual != NULL) {
        NoLista *temp = atual;
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

int main() {
    Rating* ratings = malloc(MAX_ENTRIES * sizeof(Rating));
    if (!ratings) {
        fprintf(stderr, "Falha ao alocar memória para ratings\n");
        return EXIT_FAILURE;
    }

    int tamanhos[] = {100, 1000, 10000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Benchmark Heap Sort ===\n");
    carregar_ratings("data/ratings.csv", ratings, MAX_ENTRIES);

    for (int i = 0; i < num_tamanhos; i++) {
        printf("\nTestando com %d elementos:\n", tamanhos[i]);

        clock_t inicio, fim;
        double tempo;

        if (tamanhos[i] <= 100000)
        {
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

    free(ratings);
    return 0;
}