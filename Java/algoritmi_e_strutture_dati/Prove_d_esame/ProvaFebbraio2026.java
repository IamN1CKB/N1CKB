package algoritmi_e_strutture_dati.Prove_d_esame;

import algoritmi_e_strutture_dati.Strutture_dati.SinglyLinkedList;

/**
 * Scrivere un metodo che, a partire da una Lista semplicemente concatenata di bit 
 * (registro) passata come parametro genera in maniera casuale un'altra lista di bit della 
 * stessa dimensione (maschera) e modica la lista registro facendo un AND bit a bit con la 
 * lista maschera.
 * N.B. Non vanno usate strutture dati ausiliare.
 */
public class ProvaFebbraio2026 {


    public static SinglyLinkedList<Integer> generaMaschera(SinglyLinkedList<Integer> registro) {
        SinglyLinkedList<Integer> maschera = new SinglyLinkedList<>();
        for (int i = 0; i < registro.size(); i++) {
            int bitCasuale = (int) (Math.random() * 2); // Genera 0 o 1 casualmente
            maschera.addFirst(bitCasuale);
            System.out.println("Bit casuale generato: " + bitCasuale);
        }
        
        int l1,l2,l;
        int size = registro.size();
        for (int i = 0; i < size; i++) {
            l1 = registro.removeFirst();
            l2 = maschera.removeFirst();
            l = l1 & l2;
            System.out.println("Bit registro: " + l1 + ", Bit maschera: " + l2 + ", Risultato AND: " + l);
            registro.addLast(l);
        }
        return registro;

    }

    public static void main(String[] args) {
        // Esempio di utilizzo del metodo
        SinglyLinkedList<Integer> registro = new SinglyLinkedList<>();
        registro.addLast(1);
        registro.addLast(0);
        registro.addLast(1);
        registro.addLast(1);
        registro.addLast(0);
        registro.addLast(1);
        registro.addLast(1);
        registro.addLast(1);
        // registro originale : 1 0 1 1 0 1 1 1
        System.out.println("Dimensione del registro originale: " + registro.size());
        
        generaMaschera(registro);
        
        System.out.println("Dimensione del registro modificato: " + registro.size());
        System.out.println("Registro modificato dopo l'AND con la maschera:");
        int size = registro.size();
        for (int i = 0; i < size; i++) {
            System.out.print(registro.removeFirst() + " ");
        }
        System.out.println();
    }
}
