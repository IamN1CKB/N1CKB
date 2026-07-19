package strutture_dati;

public interface Iterator<E> extends java.util.Iterator<E> {
    /**
     * Verifica la presenza di altri elementi nella sequenza.
     */
    boolean hasNext();

    /**
     * Restituisce il prossimo elemento e avanza il cursore.
     */
    E next();

    /**
     * Rimuove l'ultimo elemento restituito dall'iteratore (opzionale).
     */
    default void remove() {
        throw new UnsupportedOperationException("remove");
    }
}