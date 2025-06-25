import java.util.Random;
import java.lang.management.ManagementFactory;
import java.lang.management.MemoryMXBean;
import java.lang.management.MemoryUsage;

public class Main {
    public static void main(String[] args) {
        int[] tamanhos = {100, 1000, 10000, 100000, 1000000};
        System.out.println("=== Benchmark Heap Sort ===");
        
        for (int tamanho : tamanhos) {
            int[] dados = gerarDadosAleatorios(tamanho);
            System.out.printf("\nTamanho: %d elementos\n", tamanho);
            System.out.println("---------------------------------------------");
            
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
    
    private static long getUsedMemory() {
        MemoryMXBean memoryBean = ManagementFactory.getMemoryMXBean();
        MemoryUsage heapUsage = memoryBean.getHeapMemoryUsage();
        return heapUsage.getUsed();
    }
    
    private static void printResults(String structureName, double time, long memoryBytes) {
        double memoryKB = memoryBytes / 1024.0;
        System.out.printf("%-15s | Tempo: %.5f s | Memória: %.2f KB\n", 
                         structureName, time, memoryKB);
    }
    
    private static void testarHeapSortFilaPonteiro(int[] dados) {
        long memBefore = getUsedMemory();
        FilaPonteiro fila = new FilaPonteiro();
        for (int valor : dados) {
            fila.enfileirar(valor);
        }
        
        long inicio = System.nanoTime();
        fila.heapSort();
        long fim = System.nanoTime();
        long memAfter = getUsedMemory();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        printResults("Fila Ponteiro", tempoSegundos, memAfter - memBefore);
    }
    
    private static void testarHeapSortFilaVetor(int[] dados) {
        long memBefore = getUsedMemory();
        FilaVetor fila = new FilaVetor(dados.length);
        for (int valor : dados) {
            fila.enfileirar(valor);
        }
        
        long inicio = System.nanoTime();
        fila.heapSort();
        long fim = System.nanoTime();
        long memAfter = getUsedMemory();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        printResults("Fila Vetor", tempoSegundos, memAfter - memBefore);
    }
    
    private static void testarHeapSortPilhaPonteiro(int[] dados) {
        long memBefore = getUsedMemory();
        PilhaPonteiro pilha = new PilhaPonteiro();
        for (int valor : dados) {
            pilha.empilhar(valor);
        }
        
        long inicio = System.nanoTime();
        pilha.heapSort();
        long fim = System.nanoTime();
        long memAfter = getUsedMemory();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        printResults("Pilha Ponteiro", tempoSegundos, memAfter - memBefore);
    }
    
    private static void testarHeapSortPilhaVetor(int[] dados) {
        long memBefore = getUsedMemory();
        PilhaVetor pilha = new PilhaVetor(dados.length);
        for (int valor : dados) {
            pilha.empilhar(valor);
        }
        
        long inicio = System.nanoTime();
        pilha.heapSort();
        long fim = System.nanoTime();
        long memAfter = getUsedMemory();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        printResults("Pilha Vetor", tempoSegundos, memAfter - memBefore);
    }
    
    private static void testarHeapSortListaPonteiro(int[] dados) {
        long memBefore = getUsedMemory();
        ListaPonteiro lista = new ListaPonteiro();
        for (int valor : dados) {
            lista.inserir(valor);
        }
        
        long inicio = System.nanoTime();
        lista.heapSort();
        long fim = System.nanoTime();
        long memAfter = getUsedMemory();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        printResults("Lista Ponteiro", tempoSegundos, memAfter - memBefore);
    }
    
    private static void testarHeapSortListaVetor(int[] dados) {
        long memBefore = getUsedMemory();
        ListaVetor lista = new ListaVetor(dados.length);
        for (int valor : dados) {
            lista.inserir(valor);
        }
        
        long inicio = System.nanoTime();
        lista.heapSort();
        long fim = System.nanoTime();
        long memAfter = getUsedMemory();
        
        double tempoSegundos = (fim - inicio) / 1e9;
        printResults("Lista Vetor", tempoSegundos, memAfter - memBefore);
    }
}