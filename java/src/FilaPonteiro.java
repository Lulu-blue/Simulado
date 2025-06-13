public class FilaPonteiro {
    private class NoFila {
        int valor;
        NoFila prox;
        NoFila(int v) { valor = v; }
    }

    private NoFila inicio;
    private NoFila fim;
    private int tamanho;

    public FilaPonteiro() {
        inicio = fim = null;
        tamanho = 0;
    }

    public boolean estaVazia() { return inicio == null; }

    public void enfileirar(int valor) {
        NoFila novo = new NoFila(valor);
        if (estaVazia()) inicio = novo;
        else fim.prox = novo;
        fim = novo;
        tamanho++;
    }

    public int desenfileirar() {
        if (estaVazia()) throw new RuntimeException("Fila vazia!");
        int valor = inicio.valor;
        inicio = inicio.prox;
        if (inicio == null) fim = null;
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
        int n = arr.length;
        
        // Build heap
        for (int i = n/2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        
        // Extract elements
        for (int i = n-1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
            heapify(arr, i, 0);
        }
    }

    private void heapify(int[] arr, int n, int i) {
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