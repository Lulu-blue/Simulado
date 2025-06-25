public class ListaVetor {
    private int[] dados;
    private int tamanho;
    
    public ListaVetor(int capacidade) {
        dados = new int[capacidade];
        tamanho = 0;
    }
    
    public void inserir(int valor) {
        if (tamanho >= dados.length) {
            System.out.println("Lista cheia!");
            return;
        }
        dados[tamanho++] = valor;
    }
    
    public void heapSort() {
        if (tamanho <= 1) return;

        for (int i = tamanho / 2 - 1; i >= 0; i--) {
            heapify(dados, tamanho, i);
        }

        for (int i = tamanho - 1; i > 0; i--) {
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