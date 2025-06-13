
public class PilhaPonteiro 
{
    private static class NoPilha
    {
        int valor;
        NoPilha prox;
    }

    private NoPilha topo;
    private int tamanho;

    public PilhaPonteiro() {inicializar();}

    public void inicializar()
    {
        topo = null;
        tamanho = 0;
    }

    public boolean estaVazia() {return topo == null;}

    public void empilhar(int valor)
    {
        NoPilha novo = new NoPilha();
        novo.valor = valor;
        novo.prox = topo;
        topo = novo;
        tamanho++;
    }

    public int desempilhar()
    {
        if (estaVazia())
        {
            System.out.println("Pilha vazia!");
            return -1;
        }
        int valor = topo.valor;
        topo = topo.prox;
        tamanho--;
        return valor;
    }

    public void heapSort()
    {
        if (tamanho <= 1) return;

        int[] temp = new int[tamanho];
        int n = tamanho;

        for (int i = 0; i < n; i++) {temp[i] = desempilhar();}

        for (int i = n / 2 - 1; i >= 0; i--) {heapify(temp, n, i);}

        for (int i = n - 1; i > 0; i--)
        {
            int tempVal = temp[0];
            temp[0] = temp[i];
            temp[i] = tempVal;

            heapify(temp, i, 0);
        }

        for (int i = 0; i < n; i++) {empilhar(temp[i]);}
    }

    private void heapify(int[] arr, int n, int i)
    {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        if (esq < n && arr[esq] > arr[maior]) { maior = esq;}

        if (dir < n && arr[dir] > arr[maior]){maior = dir;}

        if (maior != i)
        {
            int swap = arr[i];
            arr[i] = arr[maior];
            arr[maior] = swap;
            heapify(arr, n, maior);
        }
    }
}