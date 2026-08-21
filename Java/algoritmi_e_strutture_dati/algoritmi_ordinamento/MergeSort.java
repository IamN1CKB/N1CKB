package algoritmi_e_strutture_dati.algoritmi_ordinamento;

import java.util.Arrays;
import java.util.Comparator;

public class MergeSort {

    /**
     * Unisce il contenuto degli array ordinati S1 e S2 nell'array S di dimensioni adeguate.
     */
    public static <K> void merge(K[] S1, K[] S2, K[] S, Comparator<K> comp) {
        int i = 0, j = 0;
        while (i + j < S.length) {
            if (j == S2.length || (i < S1.length && comp.compare(S1[i], S2[j]) < 0)) {
                S[i + j] = S1[i++]; // Copia l'elemento da S1 e incrementa l'indice i
            } else {
                S[i + j] = S2[j++]; // Copia l'elemento da S2 e incrementa l'indice j
            }
        }
    }

    /**
     * Ordina ricorsivamente l'array S utilizzando il comparatore comp.
     */
    public static <K> void merge_sort(K[] S, Comparator<K> comp) {
        int n = S.length;
        if (n < 2) {
            return; // Caso base: un array con meno di 2 elementi è già ordinato
        }
        int mid = n / 2;
        // Fase di divisione fisica dell'array originale in due sotto-array
        K[] S1 = Arrays.copyOfRange(S, 0, mid);
        K[] S2 = Arrays.copyOfRange(S, mid, n);

        // Chiamate ricorsive per ordinare i sotto-array
        merge_sort(S1, comp);
        merge_sort(S2, comp);

        // Fase di unione (conquista) dei sotto-array ordinati nell'array principale S
        merge(S1, S2, S, comp);
    }
    public static void main(String[] args) {
        Integer[] array = {38, 27, 43, 3, 9, 82, 10};
        System.out.println("Array originale: " + Arrays.toString(array));

        merge_sort(array, Integer::compareTo);

        System.out.println("Array ordinato: " + Arrays.toString(array));
    }
} 
