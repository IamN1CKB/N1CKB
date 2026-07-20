package algoritmi_e_strutture_dati.Strutture_dati;

public interface BinaryTree<E> extends Tree<E> {
    /** Restituisce la posizione del figlio sinistro di p (o nulli se non esiste). */
    public Position<E> left(Position<E> p) throws IllegalArgumentException;

    /* Restituisce la posizione del figlio destro di p (o nulli se non esiste). */
    public Position<E> right(Position<E> p) throws IllegalArgumentException;
    
    /* Restituisce la posizione del fratello di p (o nulli se non esiste). */
    public Position<E> sibling(Position<E> p) throws IllegalArgumentException;

    /*
     * Ricordiamo gli altri metodi dell'interfaccia Tree<E> che sono ereditati da BinaryTree<E>:
        * - public Position<E> root();
        * - public Position<E> parent(Position<E> p) throws IllegalArgumentException;
        * - public Iterable<Position<E>> children(Position<E> p) throws IllegalArgumentException;
        * - public int numChildren(Position<E> p) throws IllegalArgumentException;
        * - public boolean isInternal(Position<E> p) throws IllegalArgumentException;
        * - public boolean isExternal(Position<E> p) throws IllegalArgumentException;
        * - public boolean isRoot(Position<E> p) throws IllegalArgumentException;
        * - public int size();
        * - public boolean isEmpty();
        * - public Iterable<E> iterator();
        * - public Iterable<Position<E>> positions(); 
     */
}
