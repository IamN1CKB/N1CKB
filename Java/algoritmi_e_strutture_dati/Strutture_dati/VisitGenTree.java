package algoritmi_e_strutture_dati.Strutture_dati;

/**
 * Classe VisitGenTree<E>
 * Estende GenTree<E> introducendo i metodi necessari per l'attraversamento
 * dell'albero con algoritmi differenti.
 * Ciascun metodo effettua la stampa a console dell'elemento visitato.
 *
 * @param <E> il tipo degli elementi memorizzati nell'albero
 */
public class VisitGenTree<E> extends GenTree<E> {

    /**
     * Costruttore: inizializza un albero vuoto richiamando il costruttore della superclasse.
     */
    public VisitGenTree() {
        super();
    }

    /**
     * Effettua la visita dell'albero in pre-ordine (radice, poi figli ricorsivamente).
     * Stampa l'elemento di ogni nodo non appena viene incontrato.
     *
     * @param p la posizione di partenza (tipicamente root())
     */
    public void preOrder(Position<E> p) {
        if (p == null) return;
        System.out.println(p.getElement());
        for (Position<E> child : children(p)) {
            preOrder(child);
        }
    }

    /**
     * Effettua la visita dell'albero in post-ordine (figli ricorsivamente, poi radice).
     * Stampa l'elemento solo dopo aver esplorato l'intero sottoalbero del nodo corrente.
     *
     * @param p la posizione di partenza (tipicamente root())
     */
    public void postOrder(Position<E> p) {
        if (p == null) return;
        for (Position<E> child : children(p)) {
            postOrder(child);
        }
        System.out.println(p.getElement());
    }

    /**
     * Effettua la visita dell'albero in ampiezza (breadth-first, livello per livello).
     * Utilizza internamente una struttura dati a coda (FIFO) per memorizzare i nodi
     * da visitare.
     */
    public void breadthFirst() {
        if (!isEmpty()) {
            // Si istanzia una coda di posizioni (es. LinkedQueue)
            LinkedQueue<Position<E>> queue = new LinkedQueue<>();
            queue.enqueue(root()); // Enqueue della radice

            while (!queue.isEmpty()) {
                Position<E> p = queue.dequeue(); // Dequeue della testa
                System.out.println(p.getElement());   // Visita (stampa)

                // Enqueue di tutti i figli del nodo visitato
                for (Position<E> child : children(p)) {
                    queue.enqueue(child);
                }
            }
        }
    }
}