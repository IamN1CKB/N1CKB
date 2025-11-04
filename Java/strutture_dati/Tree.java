package strutture_dati;
import java.util.Iterator;

public interface Tree<E> extends Iterable<E> {
    /**
     * Restituisce la posizione della radice dell'albero (null se l'albero è vuoto).
     */
    Position<E> root();

    /**
     * Restituisce la posizione del genitore di p.
     * Lancia IllegalArgumentException se p non è valido o è la radice.
     */
    Position<E> parent(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce un Iterable contenente tutte le posizioni dei figli di p.
     * Lancia IllegalArgumentException se p non è valido.
     */
    Iterable<Position<E>> children(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce il numero di figli di p.
     * Lancia IllegalArgumentException se p non è valido.
     */
    int numChildren(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce true se p è un nodo interno (ha almeno un figlio).
     * Lancia IllegalArgumentException se p non è valido.
     */
    boolean isInternal(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce true se p è un nodo esterno (foglia, nessun figlio).
     * Lancia IllegalArgumentException se p non è valido.
     */
    boolean isExternal(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce true se p è la radice dell'albero.
     * Lancia IllegalArgumentException se p non è valido.
     */
    boolean isRoot(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce il numero totale di nodi nell'albero.
     */
    int size();

    /**
     * Restituisce true se l'albero è vuoto.
     */
    boolean isEmpty();

    /**
     * Restituisce un iteratore sugli elementi contenuti nell'albero (in un ordine a
     * scelta dell'implementazione).
     */
    Iterator<E> iterator();

    /**
     * Restituisce un Iterable su tutte le posizioni dell'albero.
     */
    Iterable<Position<E>> positions();
}