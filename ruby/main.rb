# main.rb
require_relative 'heapsort'
require_relative 'data_structures'
require 'time'
require 'objspace'
require 'etc'
require 'csv'

# --- Funções Auxiliares de Benchmark ---

def generate_random_data(size)
  Array.new(size) { rand(1..1_000_000) }
end

def get_memory_usage_kb
  if RUBY_PLATFORM =~ /linux/
    status_path = "/proc/#{Process.pid}/status"
    if File.exist?(status_path)
      File.foreach(status_path) do |line|
        if line.start_with?("VmRSS:")
          return line.split[1].to_i
        end
      end
    end
  end
  ObjectSpace.memsize_of_all / 1024.0
end

def print_results(structure_name, time_elapsed, mem_usage)
  # Adjusted for the desired image format
  printf "%-15s | Tempo: %.5f s | Memória: %.2f KB\n", structure_name, time_elapsed, mem_usage
end

# --- Function to Read CSV Data with Limit ---
def read_data_from_csv(file_path, column_name: 'ratings', limit: nil)
  data = []
  begin
    CSV.foreach(file_path, headers: true, converters: :numeric) do |row|
      if row[column_name]
        data << row[column_name]
      end
      break if limit && data.length >= limit
    end
  rescue Errno::ENOENT
    puts "Erro: Arquivo CSV não encontrado em #{file_path}"
    return []
  rescue CSV::MalformedCSVError => e
    puts "Erro: Arquivo CSV malformado em #{file_path}: #{e.message}"
    return []
  rescue => e
    puts "Erro ao ler o arquivo CSV #{file_path}: #{e.message}"
    return []
  end
  data
end

# --- Main Benchmark Function ---
def benchmark(structure_class, structure_name, data)
  GC.start
  mem_before = get_memory_usage_kb 
  
  start_time = Time.now
  
  if structure_class.const_defined?(:MAX_CAPACITY)
    structure = structure_class.new(structure_class::MAX_CAPACITY)
  else
    structure = structure_class.new
  end

  data.each do |value|
    if structure.respond_to?(:enfileirar)
      structure.enfileirar(value)
    elsif structure.respond_to?(:empilhar)
      structure.empilhar(value)
    elsif structure.respond_to?(:inserir)
      structure.inserir(value)
    end
  end
  
  structure.heap_sort

  end_time = Time.now
  
  GC.start
  mem_after = get_memory_usage_kb

  time_elapsed = end_time - start_time
  mem_used = (mem_after - mem_before).abs 
  
  print_results(structure_name, time_elapsed, mem_used)
end

# --- Main Function to Run All Benchmarks ---
def main
  ratings_file_path = "data/ratings.csv"
  
  # DEFINING DATA SIZES AS REQUESTED: 100, 1000, 10000, 100000, 1000000
  data_sizes = [100, 1_000, 10_000, 100_000, 1_000_000] # <--- MODIFIED HERE

  # Main benchmark title
  puts "=== Benchmark Heap Sort ==="
  puts "Estrutura        | Tempo (s)   | Memória (KB)" # Column headers
  puts "---------------------------------------------" # Line of dashes
  puts "" # Blank line for spacing

  data_sizes.each do |size|
    # Header for each test size, as per the image
    puts "Tamanho: #{size} elementos" 

    data = read_data_from_csv(ratings_file_path, column_name: 'ratings', limit: size)

    if data.empty?
      puts "Não foi possível carregar dados para o tamanho #{size}. Verifique o arquivo CSV."
      puts "" # Spacing
      next
    end
    
    # Run benchmarks for different structures using the loaded data
    benchmark(FilaPonteiro, "Fila Ponteiro", data.dup)
    benchmark(FilaVetor, "Fila Vetor", data.dup)
    benchmark(PilhaPonteiro, "Pilha Ponteiro", data.dup)
    benchmark(PilhaVetor, "Pilha Vetor", data.dup)
    benchmark(ListaPonteiro, "Lista Ponteiro", data.dup)
    benchmark(ListaVetor, "Lista Vetor", data.dup)
    puts "" # Blank line for spacing between size blocks
  end
end

main if __FILE__ == $0