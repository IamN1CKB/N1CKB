package algoritmi_e_strutture_dati.Strutture_dati;

public class LinkedStack<E> implements Stack<E> {

    private SinglyLinkedList<E> list = new SinglyLinkedList<E>();


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
        return list.first();
    }

    @Override
    public void push(E element) {
        list.addFirst(element);
    }

    @Override
    public E pop() {
        return list.removeFirst(); //ritorna il primo elemento e lo rimuove
    }
    
}
