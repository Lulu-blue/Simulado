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

#define MAX_ENTRIES 10000

typedef struct
{
    int userId;
    int movieId;
    double rating;
    long timestamp;
} Rating;

void carregar_ratings(const char* filename, Rating ratings[], int max)
{
    const char* paths[] =
    {
        filename,
        "../data/ratings.csv",
        "./data/ratings.csv",
        "data/ratings.csv",
        "../ratings.csv",
        NULL
    };

    FILE* file = NULL;
    for (int i = 0; paths[i] != NULL; i++)
    {
        file = fopen(paths[i], "r");
        if (file != NULL)
        {
            printf("Arquivo encontrado em: %s\n", paths[i]);
            break;
        }
    }

    if (!file) 
    {
        fprintf(stderr, "Erro: Não foi possível encontrar o arquivo ratings.csv\n");
        fprintf(stderr, "Procurou em:\n");
        for (int i = 0; paths[i] != NULL; i++)
        {
            fprintf(stderr, "- %s\n", paths[i]);
        }
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), file) == NULL)
    {
        fclose(file);
        fprintf(stderr, "Erro ao ler cabeçalho do arquivo\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (count < max && fscanf(file, "%d,%d,%lf,%ld",
           &ratings[count].userId, &ratings[count].movieId,
           &ratings[count].rating, &ratings[count].timestamp) == 4) {count++;}
    
    if (ferror(file))
    {
        perror("Erro durante leitura do arquivo");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    fclose(file);
    printf("Carregados %d registros\n\n", count);
}

void testar_heap_sort_fila_ponteiro(Rating ratings[], int size)
{
    FilaPonteiro fila;
    fila_ponteiro_inicializar(&fila);

    for (int i = 0; i < size; i++)
    {
        fila_ponteiro_enfileirar(&fila, (int)(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    heap_sort_fila_ponteiro(&fila);
    clock_t fim = clock();

    double tempo_ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Fila (ponteiro) %6d elementos: %8.3f ms\n", size, tempo_ms);
}

void testar_heap_sort_fila_vetor(Rating ratings[], int size)
{
    FilaVetor fila;
    fila_vetor_inicializar(&fila);

    for (int i = 0; i < size; i++)
    {
        fila_vetor_enfileirar(&fila, (int)(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    heap_sort_fila_vetor(&fila);
    clock_t fim = clock();

    double tempo_ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Fila (vetor)    %6d elementos: %8.3f ms\n", size, tempo_ms);
}

void testar_heap_sort_pilha_ponteiro(Rating ratings[], int size)
{
    PilhaPonteiro pilha;
    pilha_ponteiro_inicializar(&pilha);

    for (int i = 0; i < size; i++)
    {
        pilha_ponteiro_empilhar(&pilha, (int)(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    heap_sort_pilha_ponteiro(&pilha);
    clock_t fim = clock();

    double tempo_ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Pilha (ponteiro)%6d elementos: %8.3f ms\n", size, tempo_ms);
}

void testar_heap_sort_pilha_vetor(Rating ratings[], int size)
{
    PilhaVetor pilha;
    pilha_vetor_inicializar(&pilha);

    for (int i = 0; i < size; i++)
    {
        pilha_vetor_empilhar(&pilha, (int)(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    heap_sort_pilha_vetor(&pilha);
    clock_t fim = clock();

    double tempo_ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Pilha (vetor)   %6d elementos: %8.3f ms\n", size, tempo_ms);
}

void testar_heap_sort_lista_ponteiro(Rating ratings[], int size)
{
    ListaPonteiro lista;
    lista_ponteiro_inicializar(&lista);

    for (int i = 0; i < size; i++)
    {
        lista_ponteiro_inserir(&lista, (int)(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    heap_sort_lista_ponteiro(&lista);
    clock_t fim = clock();

    double tempo_ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Lista (ponteiro)%6d elementos: %8.3f ms\n", size, tempo_ms);
}

void testar_heap_sort_lista_vetor(Rating ratings[], int size)
{
    ListaVetor lista;
    lista_vetor_inicializar(&lista);

    for (int i = 0; i < size; i++)
    {
        lista_vetor_inserir(&lista, (int)(ratings[i].rating * 100));
    }

    clock_t inicio = clock();
    heap_sort_lista_vetor(&lista);
    clock_t fim = clock();

    double tempo_ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Lista (vetor)   %6d elementos: %8.3f ms\n", size, tempo_ms);
}

int main()
{
    Rating ratings[MAX_ENTRIES];
    int tamanhos[] = {100, 1000, 5000, 10000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Benchmark Heap Sort ===\n");
    carregar_ratings("ratings.csv", ratings, MAX_ENTRIES);

    for (int i = 0; i < num_tamanhos; i++)
    {
        printf("\nTestando com %d elementos:\n", tamanhos[i]);

        testar_heap_sort_fila_ponteiro(ratings, tamanhos[i]);
        testar_heap_sort_fila_vetor(ratings, tamanhos[i]);
        
        testar_heap_sort_pilha_ponteiro(ratings, tamanhos[i]);
        testar_heap_sort_pilha_vetor(ratings, tamanhos[i]);
    
        testar_heap_sort_lista_ponteiro(ratings, tamanhos[i]);
        testar_heap_sort_lista_vetor(ratings, tamanhos[i]);
    }

    return 0;
}