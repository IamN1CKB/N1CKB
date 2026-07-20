package algoritmi_e_strutture_dati.interfacce_non_usate;

/**
 * Questa interfaccia rappresenta un iteratore per scorrere una sequenza di elementi.
 * Non useremo direttamente questa interfaccia, ma la scriviamo per esercizio, siccome in 
 * Java esiste già l'interfaccia Iterator in java.util. che è molto più complessa e 
 * ottimizzata, siccome permette di usare il for-each loop e altre funzionalità avanzate.
 */
public interface Iterator<E> {
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