public class ListaPonteiro {
    private class NoLista {
        int valor;
        NoLista prox;
        
        public NoLista(int valor) {
            this.valor = valor;
            this.prox = null;
        }
    }
    
    private NoLista inicio;
    private int tamanho;
    
    public ListaPonteiro() {
        inicio = null;
        tamanho = 0;
    }
    
    public void inserir(int valor) {
        NoLista novo = new NoLista(valor);
        novo.prox = inicio;
        inicio = novo;
        tamanho++;
    }
    
    public void heapSort() {
        if (tamanho <= 1) return;
        
        int[] temp = new int[tamanho];
        NoLista atual = inicio;
        
        for (int i = 0; i < tamanho; i++) {
            temp[i] = atual.valor;
            atual = atual.prox;
        }
        
        // Build heap
        for (int i = tamanho / 2 - 1; i >= 0; i--) {
            heapify(temp, tamanho, i);
        }
        
        // Extract elements from heap
        for (int i = tamanho - 1; i > 0; i--) {
            int swap = temp[0];
            temp[0] = temp[i];
            temp[i] = swap;
            
            heapify(temp, i, 0);
        }
        
        atual = inicio;
        for (int valor : temp) {
            atual.valor = valor;
            atual = atual.prox;
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