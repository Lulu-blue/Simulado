public class PilhaPonteiro {
    private class NoPilha {
        int valor;
        NoPilha prox;
        
        public NoPilha(int valor) {
            this.valor = valor;
            this.prox = null;
        }
    }
    
    private NoPilha topo;
    private int tamanho;
    
    public PilhaPonteiro() {
        topo = null;
        tamanho = 0;
    }
    
    public boolean estaVazia() {
        return topo == null;
    }
    
    public void empilhar(int valor) {
        NoPilha novo = new NoPilha(valor);
        novo.prox = topo;
        topo = novo;
        tamanho++;
    }
    
    public int desempilhar() {
        if (estaVazia()) {
            System.out.println("Pilha vazia!");
            return -1;
        }
        int valor = topo.valor;
        topo = topo.prox;
        tamanho--;
        return valor;
    }
    
    public void heapSort() {
        if (tamanho <= 1) return;
        
        int[] temp = new int[tamanho];
        int n = tamanho;
        
        for (int i = 0; i < n; i++) {
            temp[i] = desempilhar();
        }
        
        // Build heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(temp, n, i);
        }
        
        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            int swap = temp[0];
            temp[0] = temp[i];
            temp[i] = swap;
            
            heapify(temp, i, 0);
        }
        
        for (int valor : temp) {
            empilhar(valor);
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