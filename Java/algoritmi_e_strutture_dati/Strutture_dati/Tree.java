package algoritmi_e_strutture_dati.Strutture_dati;
import java.util.Iterator;
/**
 * Interfaccia generica per una struttura dati ad albero in cui
 * i nodi possono avere un numero arbitrario di figli.
 *
 * @param <E> il tipo degli elementi memorizzati nell'albero
 */
public interface Tree<E> extends Iterable<E> {

    /**
     * Restituisce la posizione della radice dell'albero (null se l'albero è vuoto).
     *
     * @return posizione della radice
     */
    Position<E> root();

    /**
     * Restituisce la posizione del genitore di p.
     *
     * @param p posizione di cui cercare il genitore
     * @return posizione del genitore
     * @throws IllegalArgumentException se la posizione p non è valida o è la radice
     */
    Position<E> parent(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce un Iterable contenente tutte le posizioni dei figli di p.
     *
     * @param p posizione del genitore
     * @return Iterable contenente le posizioni dei figli
     * @throws IllegalArgumentException se p non è valida
     */
    Iterable<Position<E>> children(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce il numero di figli di p.
     *
     * @param p posizione del genitore
     * @return numero di figli di p
     * @throws IllegalArgumentException se p non è valida
     */
    int numChildren(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce true se p è un nodo interno (ha almeno un figlio).
     *
     * @param p posizione da verificare
     * @return true se il nodo è interno, false altrimenti
     * @throws IllegalArgumentException se p non è valida
     */
    boolean isInternal(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce true se p è un nodo esterno (foglia, nessun figlio).
     *
     * @param p posizione da verificare
     * @return true se il nodo è esterno, false altrimenti
     * @throws IllegalArgumentException se p non è valida
     */
    boolean isExternal(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce true se p è la radice dell'albero.
     *
     * @param p posizione da verificare
     * @return true se il nodo è la radice, false altrimenti
     * @throws IllegalArgumentException se p non è valida
     */
    boolean isRoot(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce il numero totale di nodi presenti nell'albero.
     *
     * @return numero totale di nodi
     */
    int size();

    /**
     * Restituisce true se l'albero non contiene alcun nodo.
     *
     * @return true se l'albero è vuoto, false altrimenti
     */
    boolean isEmpty();

    /**
     * Restituisce un iteratore sugli elementi contenuti nell'albero.
     *
     * @return iteratore degli elementi
     */
    Iterator<E> iterator();

    /**
     * Restituisce un Iterable contenente tutte le posizioni dell'albero.
     *
     * @return Iterable di tutte le posizioni
     */
    Iterable<Position<E>> positions();
}