package algoritmi_e_strutture_dati.algoritmi_ordinamento;

import java.util.Comparator;

public class QuickSortInPlace {
    /**
     * Ordina un array S in-place nell'intervallo di indici [a, b] inclusi.
     *
     * @param S    l'array di elementi da ordinare
     * @param comp il comparatore per definire l'ordine degli elementi
     * @param l    l'indice iniziale del sotto-array
     * @param r    l'indice finale del sotto-array
     * @param <K>  il tipo generico degli elementi
     */
    public static <K> void quickSortInPlace(K[] S, Comparator<K> comp, int l, int r) {
        // Caso base: se gli indici si incrociano, il sotto-array è già ordinato
        if (l >= r) {
            return;
        }

        int left = l;
        int right = r - 1;   // usiamo r-1 siccome l'elemento all'indice r è il pivot
        K pivot = S[r]; // Utilizzo dell'ultimo elemento come pivot

        // Fase di partizionamento
        while (left <= right) {
            // Scansione da sinistra a destra per cercare elementi maggiori o uguali al pivot
            while (left <= right && comp.compare(S[left], pivot) < 0) {
                left++;
            }
            // Scansione da destra a sinistra per cercare elementi minori o uguali al pivot
            while (left <= right && comp.compare(S[right], pivot) > 0) {
                right--;
            }
            // Se gli indici non si sono incrociati, esegui lo scambio (swap)
            if (left <= right) {
                swap(S, left, right);
                left++;
                right--;
            }
        }

        // Riposizionamento del pivot nella sua posizione definitiva (indicata da left)
        swap(S, left, r);
        

        // Chiamate ricorsive sulle due partizioni escludendo il pivot appena posizionato
        quickSortInPlace(S, comp, l, left - 1);    //per la parte sinistra
        quickSortInPlace(S, comp, left + 1, r);    //per la parte destra
    }
    
    /**
		 * Metodo di appoggio per lo scambio tra gli elementi dell'array
		*/
    private static <K> void swap(K[] array, int i, int j) {
        K temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
        
		
    public static void main(String[] args) {
        Integer[] array = { 3, 6, 8, 10, 1, 2, 1 };
        for (Integer num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
        Comparator<Integer> comp = Integer::compareTo;
        quickSortInPlace(array, comp, 0, array.length - 1);
        for (Integer num : array) {
            System.out.print(num + " ");
        }
    }
}