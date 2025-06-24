import java.util.Random;

public class Main {
    public static void main(String[] args) {
        int[] tamanhos = {100, 1000, 10000, 100000, 1000000};
        System.out.println("=== Benchmark Heap Sort ===");
        
        for (int tamanho : tamanhos) {
            int[] dados = gerarDadosAleatorios(tamanho);
            System.out.println("\nTestando com " + tamanho + " elementos:");
            
            testarHeapSortFilaPonteiro(dados.clone());
            testarHeapSortFilaVetor(dados.clone());
            testarHeapSortPilhaPonteiro(dados.clone());
            testarHeapSortPilhaVetor(dados.clone());
            testarHeapSortListaPonteiro(dados.clone());
            testarHeapSortListaVetor(dados.clone());
        }
    }
    
    private static int[] gerarDadosAleatorios(int tamanho) {
        Random random = new Random();
        int[] dados = new int[tamanho];
        for (int i = 0; i < tamanho; i++) {
            dados[i] = random.nextInt(1000000) + 1;
        }
        return dados;
    }
    
    private static void testarHeapSortFilaPonteiro(int[] dados) {
        FilaPonteiro fila = new FilaPonteiro();
        for (int valor : dados) {
            fila.enfileirar(valor);
        }
        
        long inicio = System.nanoTime();
        fila.heapSort();
        long fim = System.nanoTime();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        System.out.printf("Fila (ponteiro) %5d elementos: %.5f s%n", dados.length, tempoSegundos);
    }
    
    private static void testarHeapSortFilaVetor(int[] dados) {
        FilaVetor fila = new FilaVetor();
        for (int valor : dados) {
            fila.enfileirar(valor);
        }
        
        long inicio = System.nanoTime();
        fila.heapSort();
        long fim = System.nanoTime();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        System.out.printf("Fila (vetor)    %5d elementos: %.5f s%n", dados.length, tempoSegundos);
    }
    
    private static void testarHeapSortPilhaPonteiro(int[] dados) {
        PilhaPonteiro pilha = new PilhaPonteiro();
        for (int valor : dados) {
            pilha.empilhar(valor);
        }
        
        long inicio = System.nanoTime();
        pilha.heapSort();
        long fim = System.nanoTime();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        System.out.printf("Pilha (ponteiro)%5d elementos: %.5f s%n", dados.length, tempoSegundos);
    }
    
    private static void testarHeapSortPilhaVetor(int[] dados) {
        PilhaVetor pilha = new PilhaVetor();
        for (int valor : dados) {
            pilha.empilhar(valor);
        }
        
        long inicio = System.nanoTime();
        pilha.heapSort();
        long fim = System.nanoTime();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        System.out.printf("Pilha (vetor)   %5d elementos: %.5f s%n", dados.length, tempoSegundos);
    }
    
    private static void testarHeapSortListaPonteiro(int[] dados) {
        ListaPonteiro lista = new ListaPonteiro();
        for (int valor : dados) {
            lista.inserir(valor);
        }
        
        long inicio = System.nanoTime();
        lista.heapSort();
        long fim = System.nanoTime();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        System.out.printf("Lista (ponteiro)%5d elementos: %.5f s%n", dados.length, tempoSegundos);
    }
    
    private static void testarHeapSortListaVetor(int[] dados) {
        ListaVetor lista = new ListaVetor();
        for (int valor : dados) {
            lista.inserir(valor);
        }
        
        long inicio = System.nanoTime();
        lista.heapSort();
        long fim = System.nanoTime();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        System.out.printf("Lista (vetor)   %5d elementos: %.5f s%n", dados.length, tempoSegundos);
    }
}