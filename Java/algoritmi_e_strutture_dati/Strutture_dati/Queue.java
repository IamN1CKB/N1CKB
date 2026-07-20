package algoritmi_e_strutture_dati.Strutture_dati;

public interface Queue<E> {
    public int size();
    public boolean isEmpty();
    public E first();
    public void enqueue(E element);
    public E dequeue();
}
