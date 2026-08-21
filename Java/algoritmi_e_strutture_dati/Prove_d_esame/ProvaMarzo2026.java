package algoritmi_e_strutture_dati.Prove_d_esame;
import algoritmi_e_strutture_dati.interfacce_non_usate.DoublyLinkedList;

/*
Scrivere un metodo aggiuntivo Converti alla classe Lista che restituisca un 
array di stringhe contenenti tutti gli elementi in posizione pari della Lista in ordine 
dalla testa alla coda. (Utilizzare il metodo toString()).
 */
public class ProvaMarzo2026 extends DoublyLinkedList<String> {

    public String[] converti() {
        int size = size(); // Otteniamo la dimensione della lista
        int newSize = (size + 1) / 2; // Calcoliamo la dimensione dell'array risultante
        String[] result = new String[newSize]; // Creiamo l'array di stringhe

        Node<String> current = header.getNext(); // Iniziamo dalla testa della lista
        int index = 0; // Indice per l'array risultante
        int position = 0; // Posizione corrente nella lista

        while (current != trailer) { // Finché non raggiungiamo la coda
            if (position % 2 == 0) { // Controlliamo se la posizione è pari
                result[index] = current.getElement().toString(); // Aggiungiamo l'elemento all'array
                index++; // Incrementiamo l'indice dell'array
            }
            current = current.getNext(); // Passiamo al nodo successivo
            position++; // Incrementiamo la posizione
        }

        return result; // Ritorniamo l'array risultante
    }
}
