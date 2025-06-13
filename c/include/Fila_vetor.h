#ifndef FILA_VETOR_H
#define FILA_VETOR_H

#define MAX 1000000

typedef struct
{
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaVetor;

void fila_vetor_inicializar(FilaVetor *f);
int fila_vetor_esta_vazia(FilaVetor *f);
int fila_vetor_esta_cheia(FilaVetor *f);
void fila_vetor_enfileirar(FilaVetor *f, int valor);
int fila_vetor_desenfileirar(FilaVetor *f);
void heap_sort_fila_vetor(FilaVetor *f);

#endif