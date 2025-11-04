package strutture_dati;

public class ArrayQueue<E> implements Queue<E>{

    private E[] data;
    private int f = 0;
    private int size = 0;

    @SuppressWarnings("unchecked")
    public ArrayQueue(int capacity) {
        data = (E[]) new Object[capacity];
    }

    
    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public E first() {
        if (isEmpty()) return null;
        return data[f];
    }

    @Override
    public void enqueue(E element) throws IllegalStateException {
        if (data.length == size) {
            throw new IllegalStateException("Queue is full"); 
        }
        data[(f+size)%data.length]= element;
    }

    @Override
    public E dequeue() {
        if (isEmpty()) {
            return null;
        }
        E element = data[f];
        size--;
        data[f]=null;
        f = (f+1)%data.length;
        return element;
    }
    
}
