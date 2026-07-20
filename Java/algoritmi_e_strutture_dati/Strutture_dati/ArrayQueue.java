package algoritmi_e_strutture_dati.Strutture_dati;

public class ArrayQueue<E> implements Queue<E> {
    private E[] data;       // Array per la memorizzazione degli elementi
    private int f = 0;      // Indice del primo elemento (testa)
    private int sz = 0;     // Numero corrente di elementi nella coda

	@SuppressWarnings("unchecked")  // Annotazione per sopprimere l'avviso di cast non sicuro
    public ArrayQueue(int capacity) {
        // Cast generico dovuto alla cancellazione dei tipi a runtime
        data = (E[]) new Object[capacity];
    }

    @Override
    public int size() {
        return sz;
    }

    @Override
    public boolean isEmpty() {
        return sz == 0;
    }

    @Override
    public E first() {
        if (isEmpty()) {
            return null;
        }
        return data[f];
    }

    @Override
    public void enqueue(E element) throws IllegalStateException {
        if (sz == data.length) {
            throw new IllegalStateException("Coda piena (Capienza massima raggiunta)");
        }
        // Calcolo circolare dell'indice della prima posizione libera
        int r = (f + sz) % data.length;
        data[r] = element;
        sz++;
    }

    @Override
    public E dequeue() {
        if (isEmpty()) {
            return null;
        }
        E answer = data[f];
        data[f] = null; // Aiuta il Garbage Collector a deallocare la memoria

        // Spostamento circolare del puntatore di testa
        f = (f + 1) % data.length;
        sz--;
        return answer;
    }
}