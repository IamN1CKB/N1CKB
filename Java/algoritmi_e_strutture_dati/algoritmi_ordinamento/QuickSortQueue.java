package algoritmi_e_strutture_dati.algoritmi_ordinamento;

import algoritmi_e_strutture_dati.Strutture_dati.LinkedQueue;
import java.util.Comparator;

/**
 * Classe che implementa l'algoritmo Quick Sort basato su una struttura a coda.
 */
public class QuickSortQueue {

    /**
     * Algoritmo principale Quick Sort per l'ordinamento di una coda.
     *
     * @param S    la coda da ordinare
     * @param comp il comparatore per definire l'ordine degli elementi
     * @param <K>  tipo generico degli elementi
     */
    public static <K> void quickSort(LinkedQueue<K> S, Comparator<K> comp) {
        int n = S.size();

        // Caso base: una coda con meno di due elementi è già banalmente ordinata
        if (n < 2) {
            return;
        }

        // Fase 1: Dividi (Scelta del pivot e partizionamento)
        // Viene selezionato arbitrariamente il primo elemento della coda come pivot
        K pivot = S.first();

        LinkedQueue<K> L = new LinkedQueue<>();
        LinkedQueue<K> E = new LinkedQueue<>();
        LinkedQueue<K> G = new LinkedQueue<>();

        // Svuotamento di S e distribuzione degli elementi in L, E, G
        while (!S.isEmpty()) {
            K element = S.dequeue();
            int c = comp.compare(element, pivot);
            if (c < 0) {
                L.enqueue(element);       // Elemento minore del pivot
            } else if (c == 0) {
                E.enqueue(element);       // Elemento uguale al pivot
            } else {
                G.enqueue(element);       // Elemento maggiore del pivot
            }
        }

        // Fase 2: Ricorsione (Conquer)
        // Vengono ordinate separatamente le code contenenti elementi minori e maggiori del pivot
        quickSort(L, comp);
        quickSort(G, comp);

        // Fase 3: Conquista (Ricostruzione della coda originale S)
        // Reinserimento degli elementi ordinati in S rispettando l'ordine: L, poi E, infine G
        while (!L.isEmpty()) {
            S.enqueue(L.dequeue());
        }
        while (!E.isEmpty()) {
            S.enqueue(E.dequeue());
        }
        while (!G.isEmpty()) {
            S.enqueue(G.dequeue());
        }
    }
    public static void main(String[] args) {
        // Esempio di utilizzo dell'algoritmo Quick Sort con una coda di interi
        LinkedQueue<Integer> queue = new LinkedQueue<>();   
        queue.enqueue(3);
        queue.enqueue(6);
        queue.enqueue(8);
        queue.enqueue(10);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(1);

        quickSort(queue, Integer::compareTo);
        // Stampa della coda ordinata
        while (!queue.isEmpty()) {
            System.out.print(queue.dequeue() + " ");
        }
    }
}