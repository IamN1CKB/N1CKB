package strutture_dati;

public interface BinaryTree<E> extends Tree<E> {
    /** Restituisce la posizione del figlio sinistro di p (o nulli se non esiste). */
    Position<E> left(Position<E> p) throws IllegalArgumentException;

    /* Restituisce la posizione del figlio destro di p (o nulli se non esiste). */
    Position<E> right(Position<E> p) throws IllegalArgumentException;
    
    /* Restituisce la posizione del fratello di p (o nulli se non esiste). */
    Position<E> sibling(Position<E> p) throws IllegalArgumentException;
}
