package algoritmi_e_strutture_dati.Prove_d_esame;
/**
 * Scrivere un metodo che a partire pila di interi passata come parametro di ingresso, 
 * utilizzando una lista doppiamente concatenata come struttura di appoggio, restituisce la 
 * stessa pila in cui vengono eliminati i valori pari a 0, e separati i valori positivi da 
 * quelli negativi mantenendo l'ordine relativo e inserendo prima i negativi e poi i positivi o 
 * viceversa a seconda del segno dell'ultimo elemento diverso da 0 estratto dalla pila.


---

Esempio:

Pila iniziale       Pila finale (Output)
   +----+                +----+
   | -2 |                | +8 |
   | -4 |                |+10 |
   | +8 |                | -2 |
   |+10 |                | -4 |
   | -3 |                | -3 |
   | -1 |                | -1 |
   |  0 |                +----+
   +----+
 */
import algoritmi_e_strutture_dati.Strutture_dati.DoublyLinkedList;
import algoritmi_e_strutture_dati.Strutture_dati.LinkedStack;
import java.util.Scanner;

public class ProvaMaggio2026 {
    /**
     * Riorganizza la pila eliminando gli zeri e raggruppando positivi/negativi 
     * in base all'ultimo elemento estratto, mantenendo l'ordine relativo.
     * 
     * @param pila La pila di interi da modificare
     */
    public LinkedStack<Integer> riorganizza(LinkedStack<Integer> pila) {
        if (pila.isEmpty()) {
            return pila; // Se la pila è vuota, non c'è nulla da fare
        }

        // Struttura di appoggio: Lista doppiamente concatenata
        // In Java, LinkedList implementa nativamente una Doubly Linked List
        DoublyLinkedList<Integer> listaPositivi = new DoublyLinkedList<>();
        DoublyLinkedList<Integer> listaNegativi = new DoublyLinkedList<>();

        int ultimoNonZero = 0;

        // FASE 1: Estrazione dalla pila
        // Estraiamo gli elementi dal Top al Bottom
        while (!pila.isEmpty()) {
            int valore = pila.pop();
            
            
            if (valore > 0) {
                listaPositivi.addLast(valore);
                ultimoNonZero = valore; 
            } else if (valore < 0) {
                listaNegativi.addLast(valore);
                ultimoNonZero = valore; 
            }
        }

        // Se la pila conteneva solo zeri, ora è vuota e abbiamo finito
        if (listaPositivi.isEmpty() && listaNegativi.isEmpty()) {
            return pila; // Ritorniamo la pila vuota
        }

        // Determiniamo l'ordine di inserimento
        boolean inserisciPrimaNegativi = (ultimoNonZero < 0);
        // Se l'ultimo elemento non-zero estratto è negativo, inseriamo prima i negativi,
        // altrimenti prima i positivi.


        // FASE 2: Reinserimento nella pila
        // Per mantenere l'ordine relativo (LIFO), dobbiamo scorrere la lista 
        // AL CONTRARIO (dalla coda alla testa) usando un iteratore discendente.
        
        if (inserisciPrimaNegativi) {
            // Passata A: Inseriamo prima i negativi (andranno sul fondo della pila)
            while (!listaNegativi.isEmpty()) {
                // Rimuoviamo il primo elemento dalla lista dei negativi e lo inseriamo
                //  nella pila
                pila.push(listaNegativi.removeFirst());
            }

            // Passata B: Inseriamo i positivi (andranno in cima alla pila)
            while (!listaPositivi.isEmpty()) {
                // Rimuoviamo il primo elemento dalla lista dei positivi e lo inseriamo
                //  nella pila
                pila.push(listaPositivi.removeFirst());
            }
            
            
        } else {
            // Passata A: Inseriamo prima i positivi (andranno sul fondo)
            while (!listaPositivi.isEmpty()) {
                // Rimuoviamo il primo elemento dalla lista dei positivi e lo inseriamo
                //  nella pila
                pila.push(listaPositivi.removeFirst());
            }
            
            // Passata B: Inseriamo i negativi (andranno in cima)
            while (!listaNegativi.isEmpty()) {
                // Rimuoviamo il primo elemento dalla lista dei negativi e lo inseriamo
                //  nella pila
                pila.push(listaNegativi.removeFirst());
            }
        }
        return pila; // Ritorniamo la pila modificata
    }



    public static void main(String[] args) {
        // Esempio di utilizzo della classe ProvaMaggio2026
        System.out.println("ProvaMaggio2026");
        ProvaMaggio2026 prova = new ProvaMaggio2026();
        LinkedStack<Integer> stack = new LinkedStack<>();
        // Popoliamo lo stack con alcuni valori di esempio
        Scanner scanner = new Scanner(System.in);
        int numeroElementi = 10;
        int[] array = new int[numeroElementi];
        for (int i = 0; i < numeroElementi; i++) {
            System.out.print("Inserisci un intero: ");
            int valore = scanner.nextInt();
            stack.push(valore);
            array[i] = valore;

        }
        
        System.out.println("Stack originale:");
        int i = 0;
        while (i < array.length) {
            System.out.println(array[i] + " \n");
            i++;
        }
        stack = prova.riorganizza(stack);
        System.out.println("Stack riordinato:");
        while (!stack.isEmpty()) {
            System.out.println(stack.pop() + " \n");
        }
        System.out.println();
        scanner.close();
    }
}
