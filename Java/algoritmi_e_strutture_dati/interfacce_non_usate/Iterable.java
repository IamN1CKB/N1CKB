package algoritmi_e_strutture_dati.interfacce_non_usate;
/**
 * Questa interfaccia rappresenta una collezione di elementi che possono essere iterati. 
 * Fornisce un metodo per ottenere un iteratore che consente di scorrere gli elementi della 
 * collezione. Non useramo direttamente questa interfaccia, ma la scriviamo per esercizio, 
 * siccome in Java esiste già l'interfaccia Iterable in java.lang. che è molto più complessa 
 * e ottimizzata, siccome permette di usare il for-each loop e altre funzionalità avanzate.
 */
public interface Iterable<E> {
    /**
     * Restituisce un iteratore pronto a scorrere gli elementi della collezione.
     *
     * @return un'istanza di Iterator
     */
    Iterator<E> iterator();
}
