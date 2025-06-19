#include "../include/benchmark.h"
#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; paths[i] != NULL; i++) {
        file = fopen(paths[i], "r");
        if (file != NULL) {
            printf("Arquivo encontrado em: %s\n", paths[i]);
            break;
        }
    }

    if (!file) {
        fprintf(stderr, "Erro: Não foi possível encontrar ratings.csv\n");
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