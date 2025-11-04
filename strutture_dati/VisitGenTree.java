/**
 * Classe VisitGenTree<E>
 * Estende GenTree<E> e fornisce metodi per visitare l'albero generico con diversi tipi di attraversamento:
 * - PreOrder: visita in profondità pre-ordine (radice, poi figli ricorsivamente)
 * - postOrder: visita in profondità post-ordine (figli ricorsivamente, poi radice)
 * - breadthFirst: visita in ampiezza (livello per livello, da sinistra a destra)
 * Ogni metodo stampa a video l'elemento visitato.
 */
package strutture_dati;

public class VisitGenTree<E> extends GenTree<E> {
    /**
     * Costruttore: crea un albero generico vuoto.
     */
    public VisitGenTree() {
        super();
    }

    /**
     * Visita l'albero in pre-ordine (radice, poi figli ricorsivamente).
     * Stampa l'elemento di ogni nodo nell'ordine di visita.
     * 
     * @param p posizione da cui partire (tipicamente la radice)
     */
    public void preOrder(Position<E> p) {
        System.out.println(p.getElement());
        for (Position<E> position : children(p)) {
            preOrder(position);
        }
    }

    /**
     * Visita l'albero in post-ordine (figli ricorsivamente, poi radice).
     * Stampa l'elemento di ogni nodo nell'ordine di visita.
     * 
     * @param p posizione da cui partire (tipicamente la radice)
     */
    public void postOrder(Position<E> p) {
        for (Position<E> positions : children(p)) {
            postOrder(positions);
        }
        System.out.println(p.getElement());
    }

    /**
     * Visita l'albero in ampiezza (breadth-first, livello per livello).
     * Stampa l'elemento di ogni nodo nell'ordine di visita.
     * Utilizza una coda per gestire i nodi da visitare.
     */
    public void breadthFirst() {
        if (!isEmpty()) {
            ListedQueue<Position<E>> queue = new ListedQueue<>();
            queue.enqueue(root());
            while (!queue.isEmpty()) {
                Position<E> p = queue.dequeue();
                System.out.println(p.getElement());
                for (Position<E> position : children(p)) {
                    queue.enqueue(position);
                }
            }
        }
    }
}