public class FilaVetor {
    private int[] dados;
    private int inicio;
    private int fim;
    private int tamanho;
    
    public FilaVetor(int capacidade) {
        dados = new int[capacidade];
        inicio = 0;
        fim = -1;
        tamanho = 0;
    }
    
    public boolean estaVazia() {
        return tamanho == 0;
    }
    
    public boolean estaCheia() {
        return tamanho == dados.length;
    }
    
    public void enfileirar(int valor) {
        if (estaCheia()) {
            System.out.println("Fila cheia!");
            return;
        }
        fim = (fim + 1) % dados.length;
        dados[fim] = valor;
        tamanho++;
    }
    
    public int desenfileirar() {
        if (estaVazia()) {
            System.out.println("Fila vazia!");
            return -1;
        }
        int valor = dados[inicio];
        inicio = (inicio + 1) % dados.length;
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