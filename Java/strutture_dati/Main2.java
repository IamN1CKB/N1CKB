package strutture_dati;

import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
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