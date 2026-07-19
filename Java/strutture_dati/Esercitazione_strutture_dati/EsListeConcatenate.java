package strutture_dati.Esercitazione_strutture_dati;

import java.util.Scanner;

import strutture_dati.DoublyLinkedList;
import strutture_dati.SinglyLinkedList;

public class EsListeConcatenate {
    public static void main(String[] args) {
        SinglyLinkedList<String> lista = new SinglyLinkedList<String>();
        // La lista è vuota, controlliamolo
        if (lista.isEmpty())
            System.out.println("la lista è vuota");

        // aggiungiamo nella lista "Ciao"
        lista.addFirst("Ciao");
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "Ciao"

        // aggiungiamo nella lista "A"
        lista.addFirst("A");
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "A", "Ciao"

        // aggiungiamo nella lista "B" come ultimo
        lista.addLast("B");
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "A", "Ciao", "B"

        // Rimuoviamo il primo
        lista.removeFirst();
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "Ciao", "B"

        System.out.println("la dimensione della lista è " + lista.size());

        DoublyLinkedList<Float> listaDoppia = new DoublyLinkedList<Float>();
        listaDoppia.addFirst(2.3f);
        listaDoppia.addFirst(3f);
        listaDoppia.addFirst(23f);
        listaDoppia.addLast(35.6f);
        System.out.println("il primo della lista doppiamente incatenata e' " + listaDoppia.first());
        listaDoppia.stampa();




        Scanner scanner = new Scanner(System.in);
        DoublyLinkedList<Integer> test = new DoublyLinkedList<>();

        System.out.println("--- Avvio Test Lista Doppiamente Concatenata ---");

        // Popolamento iniziale di 100 elementi (da 0 a 99) in coda
        for (int j = 0; j < 100; j++) {
            test.addLast(j);
        }

        System.out.print("Inserisci un intero da aggiungere in CODA: ");
        Integer a = scanner.nextInt();
        test.addLast(a);

        System.out.print("Inserisci un intero da aggiungere in TESTA: ");
        Integer b = scanner.nextInt();
        test.addFirst(b);
        test.stampa();

        // Verifica dello stato della lista
        System.out.println("\n--- Risultati Analisi Lista ---");
        System.out.println("Dimensione lista attuale: " + test.size());
        System.out.println("Primo elemento reale in lista: " + test.first());
        System.out.println("Ultimo elemento reale in lista: " + test.last());

        // Test di rimozione efficiente in coda (O(1))
        System.out.println("Rimozione dell'ultimo elemento: " + test.removeLast());
        System.out.println("Nuovo ultimo elemento in lista: " + test.last());

        // Visualizzazione dell'intero contenuto della lista
        System.out.println("\nStampa di tutti gli elementi:");
        test.stampa();

        scanner.close();
    }
}
