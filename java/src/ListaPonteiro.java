public class ListaPonteiro {
    private class NoLista {
        int valor;
        NoLista prox;
        NoLista(int v) { valor = v; }
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
        for (int i = 0; i < temp.length; i++) {
            temp[i] = atual.valor;
            atual = atual.prox;
        }

        heapSortArray(temp);

        atual = inicio;
        for (int i = 0; i < temp.length; i++) {
            atual.valor = temp[i];
            atual = atual.prox;
        }
    }

    private void heapSortArray(int[] arr) {
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
        int largest = i, left = 2*i + 1, right = 2*i + 2;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(arr, n, largest);
        }
    }
}