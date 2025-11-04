package strutture_dati;

public interface Queue<E> {
    public int size();
    public boolean isEmpty();
    E first();
    void enqueue(E element);
    E dequeue();
}
