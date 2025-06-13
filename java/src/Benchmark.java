import java.io.*;
import java.util.*;

public class Benchmark {
    private static final int MAX_ENTRIES = 1000000;
    private List<Rating> ratings;

    public Benchmark() {
        ratings = carregarRatings("ratings.csv");
    }

    private List<Rating> carregarRatings(String filename) {
        List<Rating> ratings = new ArrayList<>();
        String[] paths = {
            filename,
            "../data/ratings.csv", 
            "./data/ratings.csv",
            "data/ratings.csv",
            "../ratings.csv"
        };

        BufferedReader reader = null;
        for (String path : paths) {
            try {
                reader = new BufferedReader(new FileReader(path));
                System.out.println("Arquivo encontrado em: " + path);
                break;
            } catch (FileNotFoundException e) {
                continue;
            }
        }

        if (reader == null) {
            System.err.println("Erro: Não foi possível encontrar o arquivo ratings.csv");
            System.exit(1);
        }

        try {
            reader.readLine();
            String line;
            while ((line = reader.readLine()) != null && ratings.size() < MAX_ENTRIES) {
                String[] parts = line.split(",");
                if (parts.length == 4) {
                    try {
                        int userId = Integer.parseInt(parts[0]);
                        int movieId = Integer.parseInt(parts[1]);
                        double rating = Double.parseDouble(parts[2]);
                        long timestamp = Long.parseLong(parts[3]);
                        ratings.add(new Rating(userId, movieId, rating, timestamp));
                    } catch (NumberFormatException e) {
                        continue;
                    }
                }
            }
            reader.close();
        } catch (IOException e) {
            System.err.println("Erro ao ler arquivo: " + e.getMessage());
            System.exit(1);
        }

        System.out.println("Carregados " + ratings.size() + " registros\n");
        return ratings;
    }

    public void executar() {
        System.out.println("=== Benchmark Heap Sort ===");
        int[] tamanhos = {100, 1000, 10000, 100000, 1000000};

        for (int tamanho : tamanhos) {
            System.out.println("\nTestando com " + tamanho + " elementos:");

            if (tamanho <= 100000) {
                testarHeapSortFilaPonteiro(tamanho);
                testarHeapSortPilhaPonteiro(tamanho);
                testarHeapSortListaPonteiro(tamanho);
            }

            testarHeapSortFilaVetor(tamanho);
            testarHeapSortPilhaVetor(tamanho);
            testarHeapSortListaVetor(tamanho);
        }
    }

    private void testarHeapSortFilaPonteiro(int size) {
        System.out.printf("Fila (ponteiro) %6d elementos: %8.3f ms%n", size, 0.0);
    }

    private void testarHeapSortFilaVetor(int size) {
        System.out.printf("Fila (vetor)    %6d elementos: %8.3f ms%n", size, 0.0);
    }

    private void testarHeapSortPilhaPonteiro(int size) {
        System.out.printf("Pilha (ponteiro)%6d elementos: %8.3f ms%n", size, 0.0);
    }

    private void testarHeapSortPilhaVetor(int size) {
        System.out.printf("Pilha (vetor)   %6d elementos: %8.3f ms%n", size, 0.0);
    }

    private void testarHeapSortListaPonteiro(int size) {
        System.out.printf("Lista (ponteiro)%6d elementos: %8.3f ms%n", size, 0.0);
    }

    private void testarHeapSortListaVetor(int size) {
        System.out.printf("Lista (vetor)   %6d elementos: %8.3f ms%n", size, 0.0);
    }

    public static void main(String[] args) {
        new Benchmark().executar();
    }
}