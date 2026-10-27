package algoritmi_e_strutture_dati.Strutture_dati;

public class LinkedStack<E> implements Stack<E> {

    // Composizione: lo stack incapsula e delega le operazioni a una lista singola
    private SinglyLinkedList<E> list = new SinglyLinkedList<>();
		
		//costruttore vuoto
    public LinkedStack() { }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public E top() {
        // Equivale a leggere il nodo di testa
        return list.first();
    }

    @Override
    public void push(E element) {
        // Inserisce in testa alla lista
        list.addFirst(element);
    }

    @Override
    public E pop() {
        // Rimuove e restituisce il nodo di testa
        return list.removeFirst();
    }
}