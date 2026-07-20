package algoritmi_e_strutture_dati.Strutture_dati;

/**
 * Classe VisitBinTree<E>
 * Estende LinkedBinaryTree<E> per introdurre i metodi di visita specializzati
 * adatti alla struttura dell'albero binario.
 */
public class VisitBinTree<E> extends LinkedBinaryTree<E> {

    /**
     * Costruttore: crea un albero binario vuoto richiamando la superclasse.
     */
    public VisitBinTree() {
        super();
    }

    /**
     * Visita l'albero in pre-ordine (radice, sottoalbero sinistro, sottoalbero destro).
     *
     * @param p posizione da cui partire
     */
    public void preorder(Position<E> p) {
        if (p == null) return;
        System.out.println(p.getElement()); // Visita corrente
        if (left(p) != null) {
            preorder(left(p));
        }
        if (right(p) != null) {
            preorder(right(p));
        }
    }

    /**
     * Visita l'albero in post-ordine (sottoalbero sinistro, sottoalbero destro, radice).
     *
     * @param p posizione da cui partire
     */
    public void postorder(Position<E> p) {
        if (p == null) return;
        if (left(p) != null) {
            postorder(left(p));
        }
        if (right(p) != null) {
            postorder(right(p));
        }
        System.out.println(p.getElement()); // Visita corrente
    }

    /**
     * Visita l'albero in ampiezza (livello per livello, da sinistra a destra).
     * Utilizza internamente una coda collegata per la gestione iterativa.
     */
    public void breadthfirst() {
        if (!isEmpty()) {
            java.util.LinkedList<Position<E>> queue = new java.util.LinkedList<>();
            queue.addLast(root()); // Enqueue della radice

            while (!queue.isEmpty()) {
                Position<E> p = queue.removeFirst(); // Dequeue
                System.out.println(p.getElement());   // Visita

                // Enqueue del figlio sinistro (se presente)
                if (left(p) != null) {
                    queue.addLast(left(p));
                }
                // Enqueue del figlio destro (se presente)
                if (right(p) != null) {
                    queue.addLast(right(p));
                }
            }
        }
    }
}
