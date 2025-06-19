import time
import random
import heapq

class NoFila:
    def __init__(self, valor):
        self.valor = valor
        self.prox = None

class FilaPonteiro:
    def __init__(self):
        self.inicio = None
        self.fim = None
        self.tamanho = 0
    
    def esta_vazia(self):
        return self.inicio is None
    
    def enfileirar(self, valor):
        novo = NoFila(valor)
        if self.esta_vazia():
            self.inicio = novo
        else:
            self.fim.prox = novo
        self.fim = novo
        self.tamanho += 1
    
    def desenfileirar(self):
        if self.esta_vazia():
            print("Fila vazia!")
            return -1
        temp = self.inicio
        valor = temp.valor
        self.inicio = self.inicio.prox
        if self.inicio is None:
            self.fim = None
        self.tamanho -= 1
        return valor
    
    def heap_sort(self):
        if self.tamanho <= 1:
            return
        
        temp = []
        n = self.tamanho
        for _ in range(n):
            temp.append(self.desenfileirar())
        
        heapq._heapify_max(temp)
        
        for i in range(n-1, 0, -1):
            temp[0], temp[i] = temp[i], temp[0]
            heapq._siftdown_max(temp, 0, i)
        
        for valor in temp:
            self.enfileirar(valor)

class FilaVetor:
    MAX = 100000
    
    def __init__(self):
        self.dados = [0] * self.MAX
        self.inicio = 0
        self.fim = -1
        self.tamanho = 0
    
    def esta_vazia(self):
        return self.tamanho == 0
    
    def esta_cheia(self):
        return self.tamanho == self.MAX
    
    def enfileirar(self, valor):
        if self.esta_cheia():
            print("Fila cheia!")
            return
        self.fim = (self.fim + 1) % self.MAX
        self.dados[self.fim] = valor
        self.tamanho += 1
    
    def desenfileirar(self):
        if self.esta_vazia():
            print("Fila vazia!")
            return -1
        valor = self.dados[self.inicio]
        self.inicio = (self.inicio + 1) % self.MAX
        self.tamanho -= 1
        return valor
    
    def heap_sort(self):
        if self.tamanho <= 1:
            return
        
        temp = []
        n = self.tamanho
        for _ in range(n):
            temp.append(self.desenfileirar())
        
        heapq._heapify_max(temp)
        
        for i in range(n-1, 0, -1):
            temp[0], temp[i] = temp[i], temp[0]
            heapq._siftdown_max(temp, 0, i)
        
        for valor in temp:
            self.enfileirar(valor)

class NoLista:
    def __init__(self, valor):
        self.valor = valor
        self.prox = None

class ListaPonteiro:
    def __init__(self):
        self.inicio = None
        self.tamanho = 0
    
    def inserir(self, valor):
        novo = NoLista(valor)
        novo.prox = self.inicio
        self.inicio = novo
        self.tamanho += 1
    
    def heap_sort(self):
        temp = []
        atual = self.inicio
        while atual is not None:
            temp.append(atual.valor)
            atual = atual.prox
        
        heapq._heapify_max(temp)
        
        for i in range(len(temp)-1, 0, -1):
            temp[0], temp[i] = temp[i], temp[0]
            heapq._siftdown_max(temp, 0, i)
        
        atual = self.inicio
        for valor in temp:
            atual.valor = valor
            atual = atual.prox

class ListaVetor:
    MAX = 100000
    
    def __init__(self):
        self.dados = []
        self.tamanho = 0
    
    def inserir(self, valor):
        if self.tamanho >= self.MAX:
            print("Lista cheia!")
            return
        self.dados.append(valor)
        self.tamanho += 1
    
    def heap_sort(self):
        temp = self.dados.copy()
        heapq._heapify_max(temp)
        
        for i in range(len(temp)-1, 0, -1):
            temp[0], temp[i] = temp[i], temp[0]
            heapq._siftdown_max(temp, 0, i)
        
        self.dados = temp

class NoPilha:
    def __init__(self, valor):
        self.valor = valor
        self.prox = None

class PilhaPonteiro:
    def __init__(self):
        self.topo = None
        self.tamanho = 0
    
    def esta_vazia(self):
        return self.topo is None
    
    def empilhar(self, valor):
        novo = NoPilha(valor)
        novo.prox = self.topo
        self.topo = novo
        self.tamanho += 1
    
    def desempilhar(self):
        if self.esta_vazia():
            print("Pilha vazia!")
            return -1
        temp = self.topo
        valor = temp.valor
        self.topo = self.topo.prox
        self.tamanho -= 1
        return valor
    
    def heap_sort(self):
        temp = []
        n = self.tamanho
        for _ in range(n):
            temp.append(self.desempilhar())
        
        heapq._heapify_max(temp)
        
        for i in range(n-1, 0, -1):
            temp[0], temp[i] = temp[i], temp[0]
            heapq._siftdown_max(temp, 0, i)
        
        for valor in temp:
            self.empilhar(valor)

class PilhaVetor:
    MAX = 100000
    
    def __init__(self):
        self.dados = []
        self.topo = -1
    
    def esta_vazia(self):
        return self.topo == -1
    
    def esta_cheia(self):
        return self.topo == self.MAX - 1
    
    def empilhar(self, valor):
        if self.esta_cheia():
            print("Pilha cheia!")
            return
        self.dados.append(valor)
        self.topo += 1
    
    def desempilhar(self):
        if self.esta_vazia():
            print("Pilha vazia!")
            return -1
        self.topo -= 1
        return self.dados.pop()
    
    def heap_sort(self):
        temp = self.dados.copy()
        heapq._heapify_max(temp)
        
        for i in range(len(temp)-1, 0, -1):
            temp[0], temp[i] = temp[i], temp[0]
            heapq._siftdown_max(temp, 0, i)
        
        self.dados = temp

def gerar_dados_aleatorios(tamanho):
    return [random.randint(1, 100000) for _ in range(tamanho)]

def testar_heap_sort_fila_ponteiro(dados):
    fila = FilaPonteiro()
    for valor in dados:
        fila.enfileirar(valor)
    
    inicio = time.time()
    fila.heap_sort()
    fim = time.time()
    
    tempo_s = fim - inicio
    print(f"Fila (ponteiro) {len(dados):6} elementos: {tempo_s:.6f} s")

def testar_heap_sort_fila_vetor(dados):
    fila = FilaVetor()
    for valor in dados:
        fila.enfileirar(valor)
    
    inicio = time.time()
    fila.heap_sort()
    fim = time.time()
    
    tempo_s = fim - inicio
    print(f"Fila (vetor)    {len(dados):6} elementos: {tempo_s:.6f} s")

def testar_heap_sort_pilha_ponteiro(dados):
    pilha = PilhaPonteiro()
    for valor in dados:
        pilha.empilhar(valor)
    
    inicio = time.time()
    pilha.heap_sort()
    fim = time.time()
    
    tempo_s = fim - inicio
    print(f"Pilha (ponteiro){len(dados):6} elementos: {tempo_s:.6f} s")

def testar_heap_sort_pilha_vetor(dados):
    pilha = PilhaVetor()
    for valor in dados:
        pilha.empilhar(valor)
    
    inicio = time.time()
    pilha.heap_sort()
    fim = time.time()
    
    tempo_s = fim - inicio
    print(f"Pilha (vetor)   {len(dados):6} elementos: {tempo_s:.6f} s")

def testar_heap_sort_lista_ponteiro(dados):
    lista = ListaPonteiro()
    for valor in dados:
        lista.inserir(valor)
    
    inicio = time.time()
    lista.heap_sort()
    fim = time.time()
    
    tempo_s = fim - inicio
    print(f"Lista (ponteiro){len(dados):6} elementos: {tempo_s:.6f} s")

def testar_heap_sort_lista_vetor(dados):
    lista = ListaVetor()
    for valor in dados:
        lista.inserir(valor)
    
    inicio = time.time()
    lista.heap_sort()
    fim = time.time()
    
    tempo_s = fim - inicio
    print(f"Lista (vetor)   {len(dados):6} elementos: {tempo_s:.6f} s")

def main():
    tamanhos = [100, 1000, 10000, 100000]
    print("=== Benchmark Heap Sort (tempos em segundos) ===")
    
    for tamanho in tamanhos:
        dados = gerar_dados_aleatorios(tamanho)
        print(f"\nTestando com {tamanho} elementos:")
        
        testar_heap_sort_fila_ponteiro(dados.copy())
        testar_heap_sort_fila_vetor(dados.copy())
        
        testar_heap_sort_pilha_ponteiro(dados.copy())
        testar_heap_sort_pilha_vetor(dados.copy())
        
        testar_heap_sort_lista_ponteiro(dados.copy())
        testar_heap_sort_lista_vetor(dados.copy())

if __name__ == "__main__":
    main()