public class PilhaVetor {
    private static final int MAX = 1000000;
    private int[] dados;
    private int topo;

    public PilhaVetor() {
        dados = new int[MAX];
        topo = -1;
    }

    public boolean estaVazia() { return topo == -1; }
    public boolean estaCheia() { return topo == MAX - 1; }

    public void empilhar(int valor) {
        if (estaCheia()) throw new RuntimeException("Pilha cheia!");
        dados[++topo] = valor;
    }

    public int desempilhar() {
        if (estaVazia()) throw new RuntimeException("Pilha vazia!");
        return dados[topo--];
    }

    public void heapSort() {
        if (topo <= 0) return;

        heapSortArray(dados, topo + 1);
    }

    private void heapSortArray(int[] arr, int n) {
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