#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/Fila_vetor.h"
#include "../include/Fila_pont.h"

#define TAMANHO_TESTE 10000

void testar_fila_vetor_grande()
{
    FilaVetor f;
    fila_vetor_inicializar(&f);
    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));
    inicio = clock();

    for (int i = 0; i < TAMANHO_TESTE; i++) { fila_vetor_enfileirar(&f, rand() % 100000);}

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Enfileiramento (vetor): %.4f segundos\n", tempo);

    inicio = clock();
    heap_sort_fila_vetor(&f);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Heap Sort (vetor): %.4f segundos\n", tempo);
}

void testar_fila_ponteiro_grande() 
{
    FilaPonteiro f;
    fila_ponteiro_inicializar(&f);
    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));
    inicio = clock();

    for (int i = 0; i < TAMANHO_TESTE; i++) {fila_ponteiro_enfileirar(&f, rand() % 100000);}

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Enfileiramento (ponteiro): %.4f segundos\n", tempo);

    inicio = clock();
    heap_sort_fila_ponteiro(&f);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Heap Sort (ponteiro): %.4f segundos\n", tempo);
}

int main()
{
    printf("--- TESTE COM 10.000 ELEMENTOS ----\n");
    
    printf("\nFILA COM VETOR\n");
    testar_fila_vetor_grande();
    
    printf("\nFILA COM PONTEIROS\n");
    testar_fila_ponteiro_grande();

    return 0;
}