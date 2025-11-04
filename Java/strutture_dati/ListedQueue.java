package strutture_dati;


public class ListedQueue<E> implements Queue<E> {
    SinglyLinkedList<E> list = new SinglyLinkedList<E>();


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
        return list.first();
    }

    @Override
    public void enqueue(E element) {
        list.addLast(element);
    }

    @Override
    public E dequeue() {
        return list.removeFirst();
    }
    
    
}
