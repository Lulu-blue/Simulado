# data_structures.rb
# Definições de classes para Fila, Lista e Pilha, em versões de Ponteiro e Vetor.

# --- Fila Baseada em Ponteiros (Lista Ligada) ---
class NoFila
    attr_accessor :valor, :prox
    def initialize(valor); @valor = valor; @prox = nil; end
  end
  
  class FilaPonteiro
    attr_accessor :inicio, :fim, :tamanho
    def initialize; @inicio = nil; @fim = nil; @tamanho = 0; end
    
    def esta_vazia?; @inicio.nil?; end
    
    def enfileirar(valor)
      novo = NoFila.new(valor)
      esta_vazia? ? (@inicio = novo) : (@fim.prox = novo)
      @fim = novo; @tamanho += 1
    end
    
    def desenfileirar
      return nil if esta_vazia?
      valor = @inicio.valor
      @inicio = @inicio.prox
      @fim = nil if @inicio.nil?
      @tamanho -= 1
      valor
    end
    
    def heap_sort
      return if @tamanho <= 1
      temp_array = Array.new(@tamanho) { desenfileirar } # Mais conciso
      
      # CORREÇÃO AQUI: Chamar HeapAlgorithms.heap_sort
      HeapAlgorithms.heap_sort(temp_array) 
      
      temp_array.each { |valor| enfileirar(valor) }
    end
  end
  
  # --- Fila Baseada em Vetor (Array Ruby) ---
  class FilaVetor
    MAX_CAPACITY = 1_000_000
    attr_accessor :dados, :inicio, :tamanho
    
    def initialize(max_capacity = MAX_CAPACITY)
      @dados = []
      @inicio = 0; @tamanho = 0
    end
    
    def esta_vazia?; @tamanho == 0; end
    def esta_cheia?; @tamanho >= MAX_CAPACITY; end
    
    def enfileirar(valor)
      return if esta_cheia?
      @dados << valor; @tamanho += 1
    end
    
    def desenfileirar
      return nil if esta_vazia?
      valor = @dados.shift # Nota: Array#shift é O(n), não ideal para filas grandes
      @tamanho -= 1
      valor
    end
    
    def heap_sort
      return if @tamanho <= 1
      temp_array = Array.new(@tamanho) { desenfileirar }
      
      # CORREÇÃO AQUI
      HeapAlgorithms.heap_sort(temp_array)
      
      @dados.clear; @inicio = 0; @tamanho = 0
      temp_array.each { |valor| enfileirar(valor) }
    end
  end
  
  # --- Lista Baseada em Ponteiros (Lista Ligada Simples) ---
  class NoLista
    attr_accessor :valor, :prox
    def initialize(valor); @valor = valor; @prox = nil; end
  end
  
  class ListaPonteiro
    attr_accessor :inicio, :tamanho
    def initialize; @inicio = nil; @tamanho = 0; end
    
    def inserir(valor)
      novo = NoLista.new(valor)
      novo.prox = @inicio; @inicio = novo; @tamanho += 1
    end
    
    def heap_sort
      temp_array = []
      atual = @inicio
      while atual; temp_array << atual.valor; atual = atual.prox; end
      
      # CORREÇÃO AQUI
      HeapAlgorithms.heap_sort(temp_array) 
      
      atual = @inicio
      temp_array.each do |valor|
        break unless atual # Se a lista original for menor que o array ordenado
        atual.valor = valor; atual = atual.prox
      end
    end
  end
  
  # --- Lista Baseada em Vetor (Array Ruby) ---
  class ListaVetor
    MAX_CAPACITY = 1_000_000
    attr_accessor :dados, :tamanho
    
    def initialize(max_capacity = MAX_CAPACITY)
      @dados = []; @tamanho = 0
    end
    
    def inserir(valor)
      return if @tamanho >= MAX_CAPACITY
      @dados << valor; @tamanho += 1
    end
    
    def heap_sort
      temp_array = @dados.dup # Cria uma cópia
      
      # CORREÇÃO AQUI
      HeapAlgorithms.heap_sort(temp_array)
      
      @dados = temp_array # Atribui o array ordenado de volta
    end
  end
  
  # --- Pilha Baseada em Ponteiros (Lista Ligada) ---
  class NoPilha
    attr_accessor :valor, :prox
    def initialize(valor); @valor = valor; @prox = nil; end
  end
  
  class PilhaPonteiro
    attr_accessor :topo, :tamanho
    def initialize; @topo = nil; @tamanho = 0; end
    
    def esta_vazia?; @topo.nil?; end
    
    def empilhar(valor)
      novo = NoPilha.new(valor)
      novo.prox = @topo; @topo = novo; @tamanho += 1
    end
    
    def desempilhar
      return nil if esta_vazia?
      valor = @topo.valor
      @topo = @topo.prox; @tamanho -= 1
      valor
    end
    
    def heap_sort
      temp_array = Array.new(@tamanho) { desempilhar }
      
      # CORREÇÃO AQUI
      HeapAlgorithms.heap_sort(temp_array) 
      
      temp_array.each { |valor| empilhar(valor) }
    end
  end
  
  # --- Pilha Baseada em Vetor (Array Ruby) ---
  class PilhaVetor
    MAX_CAPACITY = 1_000_000
    attr_accessor :dados, :topo
    
    def initialize(max_capacity = MAX_CAPACITY)
      @dados = []; @topo = -1
    end
    
    def esta_vazia?; @topo == -1; end
    def esta_cheia?; @topo == MAX_CAPACITY - 1; end
    
    def empilhar(valor)
      return if esta_cheia?
      @dados << valor; @topo += 1
    end
    
    def desempilhar
      return nil if esta_vazia?
      @topo -= 1; @dados.pop
    end
    
    def heap_sort
      temp_array = @dados.dup # Cria uma cópia
      
      # CORREÇÃO AQUI
      HeapAlgorithms.heap_sort(temp_array)
      
      @dados = temp_array # Atribui o array ordenado de volta
      @topo = @dados.length - 1 # Ajusta o topo
    end
  end