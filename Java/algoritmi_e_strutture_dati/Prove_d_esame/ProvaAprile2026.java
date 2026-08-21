package algoritmi_e_strutture_dati.Prove_d_esame;

import algoritmi_e_strutture_dati.Strutture_dati.VisitBinTree;
import algoritmi_e_strutture_dati.Strutture_dati.Position;
/*
Scrivere un metodo che a partire da un'array di V di n interi passato come parametro di 
ingresso effettua le seguenti operazioni:
* ordina il vettore in senso decrescente.
* inserisce come root di un albero binario di interi il valore max del vettore
* per ogni elemento successivo non negativo, sempre a partire dall'ultimo nodo inserito, 
    aggiunge l'elemento come figlio sinistro o come figlio destro in base al valore pari o dispari.
* il metodo restituisce l'albero creato.
*/
public class ProvaAprile2026 {

    public VisitBinTree<Integer> createAlbero(int[] array) {
        if (array == null || array.length == 0) {
            // Ritorna un albero vuoto se l'array è nullo o vuoto
            return new VisitBinTree<>(); 
        }
        // Ordina l'array in senso decrescente
        java.util.Arrays.sort(array);
        int[] sortedArray = new int[array.length];
        // Inverti l'array ordinato per ottenere l'ordine decrescente
        for (int i = 0; i < array.length; i++) {
            sortedArray[i] = array[array.length - 1 - i];
        }

        // Crea l'albero binario con il valore massimo come root
        VisitBinTree<Integer> albero = new VisitBinTree<>();
        albero.addRoot(sortedArray[0]); // Imposta il valore massimo come root

        // Aggiunge gli elementi successivi non negativi come figli sinistri o destri
        Position<Integer> currentNode = albero.root(); // Nodo corrente per l'inserimento
        for (int i = 1; i < sortedArray.length; i++) {
            if (sortedArray[i] >= 0) {
                if (sortedArray[i] % 2 == 0) {
                    // Se l'elemento è pari, aggiungilo come figlio sinistro
                    currentNode = albero.addLeft(currentNode, sortedArray[i]);
                } else {
                    // Se l'elemento è dispari, aggiungilo come figlio destro
                    currentNode = albero.addRight(currentNode, sortedArray[i]);
                }
            }
            else {
                // Se l'elemento è negativo, non viene aggiunto all'albero
                // siccome i prossimi elementi sono tutti negativi, possiamo 
                // interrompere il ciclo
                break;
            }
        }

        
        return albero;
    }
    public static void main(String[] args) {
        // Esempio di utilizzo della classe ProvaAprile2026
        ProvaAprile2026 prova = new ProvaAprile2026();
        int[] array = new int[5];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.println("Inserisci 5 interi:");
        for (int i = 0; i < 5; i++) {
            System.out.print("Inserisci l'Elemento " + (i + 1) + "-esimo: ");
            array[i] = scanner.nextInt();
        }
        scanner.close();
        VisitBinTree<Integer> albero = prova.createAlbero(array);
        albero.breadthfirst(); // Stampa l'albero in ampiezza (livello per livello)
    }
}
