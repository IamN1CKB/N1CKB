package algoritmi_e_strutture_dati.Strutture_dati;

public interface Stack<E> {
    public int size();
    public boolean isEmpty();
    public E top();
    public void push(E element);
    public E pop();
}
