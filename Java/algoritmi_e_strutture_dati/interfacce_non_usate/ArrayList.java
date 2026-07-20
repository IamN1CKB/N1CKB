package algoritmi_e_strutture_dati.interfacce_non_usate;

/**
 * Questa classe implementa una lista generica basata su array statico. 
 * Non la useremo mai, siccome in Java esiste già la classe ArrayList in java.util, 
 * ma la scriviamo per esercizio.
 *
 * Infatti la classe ArrayList in java.util è molto più complessa e ottimizzata, 
 * siccome gestisce dinamicamente la capacità dell'array sottostante, mentre questa 
 * implementazione è statica e non ridimensiona l'array.
*/
public class ArrayList<E>{
    // Variabili di istanza
    private int size = 0; // Tiene traccia del numero reale di elementi inseriti
    private E[] data;     // Array di supporto per memorizzare i riferimenti agli oggetti

    /**
     * Costruttore della classe. Inizializza l'array con una capacità definita.
     * @param capacity La capacità fisica massima iniziale dell'array.
     */
    @SuppressWarnings("unchecked")
    public ArrayList(int capacity) {
        // Allocazione dell'array come Object[] e successivo cast generico
        data = (E[]) new Object[capacity];
    }

        /**
     * Ritorna il numero attuale di elementi memorizzati all'interno dell'array list.
     */
    public int size() {
        return size;
    }

    /**
     * Verifica se l'array list è vuoto (ossia se contiene zero elementi).
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Restituisce (senza rimuovere) l'elemento posizionato all'indice i.
     * @param i L'indice dell'elemento da leggere.
     * @throws IndexOutOfBoundsException Se l'indice non rientra nei confini logici [0, size - 1].
     */
    public E get(int i) throws IndexOutOfBoundsException {
        // Il limite superiore per l'accesso in lettura/modifica è 'size'
        checkIndex(i, size);
        return data[i];
    }

    /**
     * Sostituisce l'elemento all'indice i con il nuovo elemento e, ritornando il vecchio valore.
     * @param i L'indice dell'elemento da rimpiazzare.
     * @param e Il nuovo elemento da inserire.
     * @throws IndexOutOfBoundsException Se l'indice non rientra nei confini logici [0, size - 1].
     */
    public E set(int i, E e) throws IndexOutOfBoundsException {
        checkIndex(i, size);
        E temp = data[i]; // Salva l'elemento preesistente da restituire
        data[i] = e;      // Assegna il nuovo elemento
        return temp;
    }

    /**
     * Metodo di utilità interno per convalidare se un indice i rientra nell'intervallo [0, n - 1].
     * @param i L'indice da verificare.
     * @param n Il limite superiore non compreso (tipicamente size o size + 1).
     * @throws IndexOutOfBoundsException Se l'indice risulta negativo o maggiore/uguale a n.
     */
    protected void checkIndex(int i, int n) throws IndexOutOfBoundsException {
        if (i < 0 || i >= n) {
            throw new IndexOutOfBoundsException("Indice non valido: " + i);
        }
    }

        /**
     * Inserisce un nuovo elemento e in corrispondenza dell'indice i.
     * Tutti gli elementi dall'indice i in poi vengono spostati a destra di una posizione.
     * @param i L'indice in cui inserire il nuovo elemento.
     * @param e Il nuovo elemento da memorizzare.
     * @throws IndexOutOfBoundsException Se l'indice non rientra nei limiti dell'inserimento [0, size].
     * @throws IllegalStateException Se l'array di supporto è completamente pieno.
     */
    public void add(int i, E e) throws IndexOutOfBoundsException, IllegalStateException {
        // Per un inserimento, il limite superiore valido è size + 1 (accodamento ammesso)
        checkIndex(i, size + 1);

        // Verifica se l'array statico ha raggiunto la capacità fisica massima
        if (size == data.length) {
            throw new IllegalStateException("L'array ha raggiunto la capienza massima");
        }

        // Shifting a destra: si inizia dall'ultimo elemento spostando verso l'indice i
        for (int k = size - 1; k >= i; k--) {
            data[k + 1] = data[k];
        }

        data[i] = e; // Scrive il riferimento del nuovo elemento nella cella liberata
        size++;      // Incrementa la dimensione logica della lista
    }

    /**
     * Rimuove l'elemento memorizzato all'indice i, restituendo il valore cancellato.
     * Tutti gli elementi successivi all'indice i vengono traslati a sinistra di una posizione.
     * @param i L'indice dell'elemento da rimuovere.
     * @throws IndexOutOfBoundsException Se l'indice non rientra nei confini logici [0, size - 1].
     */
    public E remove(int i) throws IndexOutOfBoundsException {
        checkIndex(i, size);
        E temp = data[i]; // Salva l'elemento da rimuovere per la restituzione

        // Shifting a sinistra: si parte dall'elemento successivo a quello rimosso
        for (int k = i; k < size - 1; k++) {
            data[k] = data[k + 1];
        }

        // De-referenziazione dell'ultima cella per facilitare il Garbage Collector
        data[size - 1] = null;

        size--; // Decrementa la dimensione logica della lista
        return temp;
    }
}