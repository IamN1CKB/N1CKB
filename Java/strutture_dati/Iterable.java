package strutture_dati;

public interface Iterable<E> extends java.lang.Iterable<E> {
    /**
     * Restituisce un iteratore pronto a scorrere gli elementi della collezione.
     *
     * @return un'istanza di Iterator
     */
    Iterator<E> iterator();
}
