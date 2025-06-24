public class FilaPonteiro {
    private class NoFila {
        int valor;
        NoFila prox;
        
        public NoFila(int valor) {
            this.valor = valor;
            this.prox = null;
        }
    }
    
    private NoFila inicio;
    private NoFila fim;
    private int tamanho;
    
    public FilaPonteiro() {
        inicio = null;
        fim = null;
        tamanho = 0;
    }
    
    public boolean estaVazia() {
        return inicio == null;
    }
    
    public void enfileirar(int valor) {
        NoFila novo = new NoFila(valor);
        if (estaVazia()) {
            inicio = novo;
        } else {
            fim.prox = novo;
        }
        fim = novo;
        tamanho++;
    }
    
    public int desenfileirar() {
        if (estaVazia()) {
            System.out.println("Fila vazia!");
            return -1;
        }
        int valor = inicio.valor;
        inicio = inicio.prox;
        if (inicio == null) {
            fim = null;
        }
        tamanho--;
        return valor;
    }
    
    public void heapSort() {
        if (tamanho <= 1) return;
        
        int[] temp = new int[tamanho];
        int n = tamanho;
        
        for (int i = 0; i < n; i++) {
            temp[i] = desenfileirar();
        }

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(temp, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            int swap = temp[0];
            temp[0] = temp[i];
            temp[i] = swap;
            
            heapify(temp, i, 0);
        }
        
        for (int valor : temp) {
            enfileirar(valor);
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