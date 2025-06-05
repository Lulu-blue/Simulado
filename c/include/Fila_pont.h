#ifndef FILA_PONT_H
#define FILA_PONT_H

typedef struct NoFila
{
    int valor;
    struct NoFila *prox;
} NoFila;

typedef struct 
{
    NoFila *inicio;
    NoFila *fim;
    int tamanho;
} FilaPonteiro;

void fila_ponteiro_inicializar(FilaPonteiro *f);
int fila_ponteiro_esta_vazia(FilaPonteiro *f);
void fila_ponteiro_enfileirar(FilaPonteiro *f, int valor);
int fila_ponteiro_desenfileirar(FilaPonteiro *f);

void heap_sort_fila_ponteiro(FilaPonteiro *f);

#endif