package algoritmi_e_strutture_dati.Strutture_dati;

public interface DoublyLinkedListInterface<E> {

    /**
     * Restituisce il numero di elementi nella lista
     * 
     * @return il numero di elementi nella lista
     */
    public int size();

    /**
     * Verifica se la lista è vuota
     * 
     * @return true se la lista è vuota, false altrimenti
     */
    public boolean isEmpty();

    /**
     * Restituisce (senza rimuovere) il primo elemento della lista
     * 
     * @return il primo elemento della lista (null se la lista è vuota)
     */
    public E first();

    /**
     * Restituisce (senza rimuovere) l'ultimo elemento della lista
     * 
     * @return l'ultimo elemento della lista (null se la lista è vuota)
     */
    public E last();

    /**
     * Aggiunge un elemento all'inizio della lista
     * 
     * @param e l'elemento da aggiungere
     */
    public void addFirst(E element);

    /**
     * Aggiunge un elemento alla fine della lista
     * 
     * @param e l'elemento da aggiungere
     */
    public void addLast(E element);

    /**
     * Rimuove e restituisce il primo elemento della lista (null se la lista è vuota)
     * 
     * @return l'elemento rimosso o null se la lista è vuota
     */
    public E removeFirst();

    /**
     * Rimuove e restituisce l'ultimo elemento della lista (null se la lista è vuota)
     * 
     * @return l'elemento rimosso o null se la lista è vuota
     */
    public E removeLast();
}
