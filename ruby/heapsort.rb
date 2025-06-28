# heapsort.rb
# Módulo para o algoritmo Heap Sort.

module HeapAlgorithms # <--- NOVIDADE: Definindo um módulo
    # Função auxiliar para heapify (max-heap).
    # Reorganiza uma sub-árvore para manter a propriedade de max-heap.
    #
    # @param arr [Array] O array a ser heapificado
    # @param n [Integer] O tamanho do heap atual
    # @param i [Integer] O índice da raiz da sub-árvore
    def self.heapify(arr, n, i) # <--- NOVIDADE: self. para método de módulo
      largest = i
      left = 2 * i + 1
      right = 2 * i + 2
  
      if left < n && arr[left] > arr[largest]
        largest = left
      end
  
      if right < n && arr[right] > arr[largest]
        largest = right
      end
  
      if largest != i
        arr[i], arr[largest] = arr[largest], arr[i] # Troca os elementos
        self.heapify(arr, n, largest) # <--- NOVIDADE: self. para chamar heapify recursivamente
      end
    end
  
    # Implementação do algoritmo Heap Sort.
    # Ordena um array em ordem crescente usando a propriedade de max-heap.
    #
    # @param arr [Array] O array a ser ordenado
    def self.heap_sort(arr) # <--- NOVIDADE: self. para método de módulo
      n = arr.length
  
      # Constrói um max-heap
      (n / 2 - 1).downto(0) do |i|
        self.heapify(arr, n, i) # <--- NOVIDADE: self. para chamar heapify
      end
  
      # Extrai elementos um por um do heap
      (n - 1).downto(1) do |i|
        arr[0], arr[i] = arr[i], arr[0] # Move a raiz (maior elemento) para o final
        self.heapify(arr, i, 0) # <--- NOVIDADE: self. para chamar heapify
      end
    end
  end