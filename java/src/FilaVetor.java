public class FilaVetor {
    private static final int MAX = 1000000;
    private int[] dados;
    private int inicio;
    private int fim;
    private int tamanho;

    public FilaVetor() {
        dados = new int[MAX];
        inicio = 0;
        fim = -1;
        tamanho = 0;
    }

    public boolean estaVazia() { return tamanho == 0; }
    public boolean estaCheia() { return tamanho == MAX; }

    public void enfileirar(int valor) {
        if (estaCheia()) throw new RuntimeException("Fila cheia!");
        fim = (fim + 1) % MAX;
        dados[fim] = valor;
        tamanho++;
    }

    public int desenfileirar() {
        if (estaVazia()) throw new RuntimeException("Fila vazia!");
        int valor = dados[inicio];
        inicio = (inicio + 1) % MAX;
        tamanho--;
        return valor;
    }

    public void heapSort() {
        if (tamanho <= 1) return;

        int[] temp = new int[tamanho];
        for (int i = 0; i < temp.length; i++) {
            temp[i] = desenfileirar();
        }

        heapSortArray(temp);

        for (int val : temp) {
            enfileirar(val);
        }
    }

    private void heapSortArray(int[] arr) {
        // Same implementation as in FilaPonteiro
        int n = arr.length;
        
        for (int i = n/2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        
        for (int i = n-1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
            heapify(arr, i, 0);
        }
    }

    private void heapify(int[] arr, int n, int i) {
        // Same implementation as in FilaPonteiro
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }
}