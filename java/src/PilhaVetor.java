public class PilhaVetor {
    private static final int MAX = 100000;
    private int[] dados;
    private int topo;
    
    public PilhaVetor() {
        dados = new int[MAX];
        topo = -1;
    }
    
    public boolean estaVazia() {
        return topo == -1;
    }
    
    public boolean estaCheia() {
        return topo == MAX - 1;
    }
    
    public void empilhar(int valor) {
        if (estaCheia()) {
            System.out.println("Pilha cheia!");
            return;
        }
        dados[++topo] = valor;
    }
    
    public int desempilhar() {
        if (estaVazia()) {
            System.out.println("Pilha vazia!");
            return -1;
        }
        return dados[topo--];
    }
    
    public void heapSort() {
        if (topo + 1 <= 1) return;
        
        int n = topo + 1;
        
        // Build heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(dados, n, i);
        }
        
        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            int swap = dados[0];
            dados[0] = dados[i];
            dados[i] = swap;
            
            heapify(dados, i, 0);
        }
    }
    
    private void heapify(int[] arr, int n, int i) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        
        if (esq < n && arr[esq] > arr[maior]) {
            maior = esq;
        }
        
        if (dir < n && arr[dir] > arr[maior]) {
            maior = dir;
        }
        
        if (maior != i) {
            int swap = arr[i];
            arr[i] = arr[maior];
            arr[maior] = swap;
            
            heapify(arr, n, maior);
        }
    }
}