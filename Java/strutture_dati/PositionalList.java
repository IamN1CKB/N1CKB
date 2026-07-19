package strutture_dati;
import java.util.Iterator;

/**
 * Interfaccia che definisce il comportamento di una lista posizionale.
 * Estende Iterable per consentire l'iterazione diretta sugli elementi della lista.
 *
 * @param <E> il tipo degli elementi memorizzati nella lista
 */
public interface PositionalList<E> extends Iterable<E> {

    /**
     * Restituisce il numero di elementi nella lista.
     * @return dimensione della lista
     */
    int size();

    /**
     * Verifica se la lista è vuota.
     * @return true se la lista non contiene elementi, false altrimenti
     */
    boolean isEmpty();

    /**
     * Restituisce la posizione del primo elemento della lista.
     * @return posizione del primo elemento, o null se la lista è vuota
     */
    Position<E> first();

    /**
     * Restituisce la posizione dell'ultimo elemento della lista.
     * @return posizione dell'ultimo elemento, o null se la lista è vuota
     */
    Position<E> last();

    /**
     * Restituisce la posizione immediatamente precedente a p.
     * @param p una posizione valida nella lista
     * @return la posizione precedente, o null se p è il primo elemento
     * @throws IllegalArgumentException se p non è una posizione valida per questa lista
     */
    Position<E> before(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce la posizione immediatamente successiva a p.
     * @param p una posizione valida nella lista
     * @return la posizione successiva, o null se p è l'ultimo elemento
     * @throws IllegalArgumentException se p non è una posizione valida per questa lista
     */
    Position<E> after(Position<E> p) throws IllegalArgumentException;

    /**
     * Inserisce un elemento all'inizio della lista.
     * @param e il nuovo elemento da inserire
     * @return la posizione del nuovo elemento
     */
    Position<E> addFirst(E e);

    /**
     * Inserisce un elemento alla fine della lista.
     * @param e il nuovo elemento da inserire
     * @return la posizione del nuovo elemento
     */
    Position<E> addLast(E e);

    /**
     * Inserisce un elemento immediatamente prima della posizione p.
     * @param p la posizione di riferimento
     * @param e il nuovo elemento da inserire
     * @return la posizione del nuovo elemento
     * @throws IllegalArgumentException se p non è una posizione valida
     */
    Position<E> addBefore(Position<E> p, E e) throws IllegalArgumentException;

    /**
     * Inserisce un elemento immediatamente dopo la posizione p.
     * @param p la posizione di riferimento
     * @param e il nuovo elemento da inserire
     * @return la posizione del nuovo elemento
     * @throws IllegalArgumentException se p non è una posizione valida
     */
    Position<E> addAfter(Position<E> p, E e) throws IllegalArgumentException;

    /**
     * Sostituisce l'elemento memorizzato alla posizione p con e.
     * @param p la posizione dell'elemento da sostituire
     * @param e il nuovo elemento da memorizzare
     * @return l'elemento precedentemente memorizzato in p
     * @throws IllegalArgumentException se p non è una posizione valida
     */
    E set(Position<E> p, E e) throws IllegalArgumentException;

    /**
     * Rimuove l'elemento alla posizione p, invalidando la posizione stessa.
     * @param p la posizione dell'elemento da rimuovere
     * @return l'elemento rimosso
     * @throws IllegalArgumentException se p non è una posizione valida
     */
    E remove(Position<E> p) throws IllegalArgumentException;

    /**
     * Restituisce un iteratore sugli elementi della lista.
     * @return un Iterator degli elementi
     */
    Iterator<E> iterator();

    /**
     * Restituisce una collezione iterabile di tutte le posizioni della lista,
     * consentendo di scorrere le posizioni anziché solo gli elementi.
     * @return una collezione Iterable di oggetti Position
     */
    Iterable<Position<E>> positions();
}
