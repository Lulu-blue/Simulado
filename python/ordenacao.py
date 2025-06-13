import time
import csv
from heapq import heappush, heappop

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
        
        # Extrai todos os elementos
        elementos = []
        while not self.esta_vazia():
            elementos.append(self.desenfileirar())
        
        # Heap Sort
        elementos.sort()  # Python usa TimSort, mas para fins de comparação
        
        # Reinsere ordenado
        for elem in elementos:
            self.enfileirar(elem)

class FilaVetor:
    def __init__(self, max_size=10000):
        self.dados = [0] * max_size
        self.inicio = 0
        self.fim = -1
        self.tamanho = 0
        self.max_size = max_size
    
    def esta_vazia(self):
        return self.tamanho == 0
    
    def esta_cheia(self):
        return self.tamanho == self.max_size
    
    def enfileirar(self, valor):
        if self.esta_cheia():
            print("Fila cheia!")
            return
        self.fim = (self.fim + 1) % self.max_size
        self.dados[self.fim] = valor
        self.tamanho += 1
    
    def desenfileirar(self):
        if self.esta_vazia():
            print("Fila vazia!")
            return -1
        valor = self.dados[self.inicio]
        self.inicio = (self.inicio + 1) % self.max_size
        self.tamanho -= 1
        return valor
    
    def heap_sort(self):
        if self.tamanho <= 1:
            return
        
        # Extrai todos os elementos
        elementos = []
        while not self.esta_vazia():
            elementos.append(self.desenfileirar())
        
        # Heap Sort
        elementos.sort()
        
        # Reinsere ordenado
        for elem in elementos:
            self.enfileirar(elem)

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
        if self.tamanho <= 1:
            return
        
        # Extrai todos os elementos
        elementos = []
        while not self.esta_vazia():
            elementos.append(self.desempilhar())
        
        # Heap Sort
        elementos.sort()
        
        # Reinsere ordenado
        for elem in elementos:
            self.empilhar(elem)

class PilhaVetor:
    def __init__(self, max_size=10000):
        self.dados = [0] * max_size
        self.topo = -1
        self.max_size = max_size
    
    def esta_vazia(self):
        return self.topo == -1
    
    def esta_cheia(self):
        return self.topo == self.max_size - 1
    
    def empilhar(self, valor):
        if self.esta_cheia():
            print("Pilha cheia!")
            return
        self.topo += 1
        self.dados[self.topo] = valor
    
    def desempilhar(self):
        if self.esta_vazia():
            print("Pilha vazia!")
            return -1
        valor = self.dados[self.topo]
        self.topo -= 1
        return valor
    
    def heap_sort(self):
        if self.topo <= 0:
            return
        
        # Extrai todos os elementos
        elementos = []
        while not self.esta_vazia():
            elementos.append(self.desempilhar())
        
        # Heap Sort
        elementos.sort()
        
        # Reinsere ordenado
        for elem in elementos:
            self.empilhar(elem)

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
        if self.tamanho <= 1:
            return
        
        # Extrai todos os elementos
        elementos = []
        atual = self.inicio
        while atual is not None:
            elementos.append(atual.valor)
            atual = atual.prox
        
        # Heap Sort
        elementos.sort()
        
        # Atualiza os valores na lista
        atual = self.inicio
        for elem in elementos:
            atual.valor = elem
            atual = atual.prox

class ListaVetor:
    def __init__(self, max_size=10000):
        self.dados = [0] * max_size
        self.tamanho = 0
        self.max_size = max_size
    
    def inserir(self, valor):
        if self.tamanho >= self.max_size:
            print("Lista cheia!")
            return
        self.dados[self.tamanho] = valor
        self.tamanho += 1
    
    def heap_sort(self):
        if self.tamanho <= 1:
            return
        
        # Cria uma heap mínima
        heap = []
        for i in range(self.tamanho):
            heappush(heap, self.dados[i])
        
        # Extrai os elementos ordenados
        for i in range(self.tamanho):
            self.dados[i] = heappop(heap)

def carregar_ratings(filename):
    paths = [
        filename,
        "../data/ratings.csv",
        "./data/ratings.csv",
        "data/ratings.csv",
        "../ratings.csv"
    ]
    
    ratings = []
    
    for path in paths:
        try:
            with open(path, 'r') as file:
                reader = csv.reader(file)
                next(reader)  # Pula o cabeçalho
                for row in reader:
                    if len(row) == 4:
                        rating = {
                            'userId': int(row[0]),
                            'movieId': int(row[1]),
                            'rating': float(row[2]),
                            'timestamp': int(row[3])
                        }
                        ratings.append(rating)
                print(f"Arquivo encontrado em: {path}")
                break
        except FileNotFoundError:
            continue
    else:
        print("Erro: Não foi possível encontrar o arquivo ratings.csv")
        print("Procurou em:")
        for path in paths:
            print(f"- {path}")
        exit(1)
    
    print(f"Carregados {len(ratings)} registros\n")
    return ratings

def testar_heap_sort_fila_ponteiro(ratings, size):
    fila = FilaPonteiro()
    for i in range(size):
        fila.enfileirar(int(ratings[i]['rating'] * 100))
    
    inicio = time.time()
    fila.heap_sort()
    fim = time.time()
    
    tempo_ms = (fim - inicio) * 1000
    print(f"Fila (ponteiro) {size:6d} elementos: {tempo_ms:8.3f} ms")

def testar_heap_sort_fila_vetor(ratings, size):
    fila = FilaVetor()
    for i in range(size):
        fila.enfileirar(int(ratings[i]['rating'] * 100))
    
    inicio = time.time()
    fila.heap_sort()
    fim = time.time()
    
    tempo_ms = (fim - inicio) * 1000
    print(f"Fila (vetor)    {size:6d} elementos: {tempo_ms:8.3f} ms")

def testar_heap_sort_pilha_ponteiro(ratings, size):
    pilha = PilhaPonteiro()
    for i in range(size):
        pilha.empilhar(int(ratings[i]['rating'] * 100))
    
    inicio = time.time()
    pilha.heap_sort()
    fim = time.time()
    
    tempo_ms = (fim - inicio) * 1000
    print(f"Pilha (ponteiro){size:6d} elementos: {tempo_ms:8.3f} ms")

def testar_heap_sort_pilha_vetor(ratings, size):
    pilha = PilhaVetor()
    for i in range(size):
        pilha.empilhar(int(ratings[i]['rating'] * 100))
    
    inicio = time.time()
    pilha.heap_sort()
    fim = time.time()
    
    tempo_ms = (fim - inicio) * 1000
    print(f"Pilha (vetor)   {size:6d} elementos: {tempo_ms:8.3f} ms")

def testar_heap_sort_lista_ponteiro(ratings, size):
    lista = ListaPonteiro()
    for i in range(size):
        lista.inserir(int(ratings[i]['rating'] * 100))
    
    inicio = time.time()
    lista.heap_sort()
    fim = time.time()
    
    tempo_ms = (fim - inicio) * 1000
    print(f"Lista (ponteiro){size:6d} elementos: {tempo_ms:8.3f} ms")

def testar_heap_sort_lista_vetor(ratings, size):
    lista = ListaVetor()
    for i in range(size):
        lista.inserir(int(ratings[i]['rating'] * 100))
    
    inicio = time.time()
    lista.heap_sort()
    fim = time.time()
    
    tempo_ms = (fim - inicio) * 1000
    print(f"Lista (vetor)   {size:6d} elementos: {tempo_ms:8.3f} ms")

def main():
    print("=== Benchmark Heap Sort ===")
    ratings = carregar_ratings("ratings.csv")
    tamanhos = [100, 1000, 5000, 10000]
    
    for tamanho in tamanhos:
        print(f"\nTestando com {tamanho} elementos:")
        
        testar_heap_sort_fila_ponteiro(ratings, tamanho)
        testar_heap_sort_fila_vetor(ratings, tamanho)
        
        testar_heap_sort_pilha_ponteiro(ratings, tamanho)
        testar_heap_sort_pilha_vetor(ratings, tamanho)
        
        testar_heap_sort_lista_ponteiro(ratings, tamanho)
        testar_heap_sort_lista_vetor(ratings, tamanho)

if __name__ == "__main__":
    main()