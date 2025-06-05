#include <stdio.h>
#include "../include/Fila_vetor.h"

void fila_vetor_inicializar(FilaVetor *f) 
{
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int fila_vetor_esta_vazia(FilaVetor *f) { return (f->tamanho == 0);}

int fila_vetor_esta_cheia(FilaVetor *f) {return (f->tamanho == MAX);}


void fila_vetor_enfileirar(FilaVetor *f, int valor) 
{
    if (fila_vetor_esta_cheia(f)) 
    {
        printf("Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;
}

int fila_vetor_desenfileirar(FilaVetor *f) 
{
    if (fila_vetor_esta_vazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return valor;
}

void heapify_fila_vetor(int arr[], int n, int i) 
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior]) maior = esq;

    if (dir < n && arr[dir] > arr[maior]) maior = dir;

    if (maior != i)
    {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify_fila_vetor(arr, n, maior);
    }
}


void heap_sort_fila_vetor(FilaVetor *f)
{
    int temp[MAX];
    int n = f->tamanho;
    for (int i = 0; i < n; i++) { temp[i] = fila_vetor_desenfileirar(f);}


    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_fila_vetor(temp, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp_val = temp[0];
        temp[0] = temp[i];
        temp[i] = temp_val;
        heapify_fila_vetor(temp, i, 0);
    }

    for (int i = 0; i < n; i++) { fila_vetor_enfileirar(f, temp[i]);}
}