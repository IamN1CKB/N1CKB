package strutture_dati;

public class ListBasedStack<E> implements Stack<E> {

    private SinglyLinkedList<E> list = new SinglyLinkedList<E>();

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
