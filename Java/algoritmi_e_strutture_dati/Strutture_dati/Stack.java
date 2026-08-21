package algoritmi_e_strutture_dati.Strutture_dati;

// Interfaccia per una pila generica
public interface Stack<E> {

    /**
     * Restituisce il numero di elementi nella pila
     * @return il numero di elementi nella pila
     */
    public int size();

    /**
     * Verifica se la pila è vuota
     * @return true se la pila è vuota, false altrimenti
     */
    public boolean isEmpty();

    /**
     * Restituisce l'elemento in cima alla pila senza rimuoverlo
     * @return l'elemento in cima alla pila
     */
    public E top();

    /**
     * Aggiunge un elemento in cima alla pila
     * @param element l'elemento da aggiungere
     */
    public void push(E element);

    /**
     * Rimuove e restituisce l'elemento in cima alla pila
     * @return l'elemento rimosso dalla cima della pila
     */
    public E pop();
}
