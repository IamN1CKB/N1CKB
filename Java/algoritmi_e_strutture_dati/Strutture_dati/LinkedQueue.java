package algoritmi_e_strutture_dati.Strutture_dati;


public class LinkedQueue<E> implements Queue<E> {

    // Composizione: delega delle operazioni a una lista singolarmente concatenata
    private SinglyLinkedList<E> list = new SinglyLinkedList<>();

    public LinkedQueue() { }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public E first() {
        return list.first(); // Restituisce il valore in testa alla lista
    }

    @Override
    public void enqueue(E element) {
        list.addLast(element); // Inserisce in fondo alla lista (coda)
    }

    @Override
    public E dequeue() {
        return list.removeFirst(); // Rimuove e restituisce dalla testa della lista
    }
}