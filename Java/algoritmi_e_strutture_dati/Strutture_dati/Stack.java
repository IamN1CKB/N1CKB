package algoritmi_e_strutture_dati.Strutture_dati;

public interface Stack<E> {
    int size();
    boolean isEmpty();
    E top();
    void push(E element);
    E pop();
}
