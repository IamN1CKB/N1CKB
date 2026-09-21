package algoritmi_e_strutture_dati.Strutture_dati;
import java.util.ArrayList;
import java.util.Iterator;


/**
 * Classe che implementa un albero generico (n-ario) tramite nodi collegati.
 * Fornisce metodi per aggiungere la radice, i nodi figli e per gestire
 * l'iterazione su elementi e posizioni.
 */
public class GenTree<E> implements Tree<E> {

    // --- CLASSE INNESTATA PER LA CREAZIONE DEI NODI ---
    /**
     * Nodo dell'albero generico. Contiene l'elemento di business,
     * il riferimento al genitore e una lista dinamica per i figli.
     */
    protected static class Node<E> implements Position<E> {
        private E element;                       // Elemento memorizzato nel nodo
        private Node<E> parent;                  // Riferimento al nodo genitore
        private ArrayList<Position<E>> children; // Lista dinamica dei figli

        /**
         * Costruttore del nodo.
         *
         * @param e     l'elemento da memorizzare
         * @param above il nodo genitore (null per la radice)
         */
        public Node(E e, Node<E> above) {
            element = e;
            parent = above;
            children = new ArrayList<Position<E>>();
        }

        // Metodi di accesso dell'interfaccia Position
        @Override
        public E getElement() {
            return element;
        }

        public Node<E> getParent() {
            return parent;
        }

        // Metodi di aggiornamento (usati internamente da GenTree)
        public void setElement(E e) {
            element = e;
        }

        public void setParent(Node<E> parentNode) {
            parent = parentNode;
        }

        public ArrayList<Position<E>> getChildrenList() {
            return children;
        }
    } // Fine della classe Node

    /**
     * Factory method per la creazione di un nuovo nodo.
     */
    protected Node<E> createNode(E e, Node<E> parent) {
        return new Node<>(e, parent);
    }

    // Attributi di istanza di GenTree
    protected Node<E> root = null; // Radice dell'albero
    private int size = 0;          // Numero totale di nodi presenti

    /**
     * Costruttore: crea un albero inizialmente vuoto.
     */
    public GenTree() {
    }

    // --- METODO DI VALIDAZIONE INTERNO ---
    /**
     * Converte una Position generica nel nodo concreto dell'implementazione,
     * verificandone la validità strutturale.
     *
     * @param p la posizione da validare
     * @return il nodo castato internamente
     * @throws IllegalArgumentException se la posizione non è valida o di tipo errato
     */
    protected Node<E> validate(Position<E> p) throws IllegalArgumentException {
        if (!(p instanceof Node)) {
            throw new IllegalArgumentException("Tipo di posizione non valido");
        }
        Node<E> node = (Node<E>) p;
        // In un'implementazione reale, si potrebbe verificare se il nodo appartiene ancora all'albero
        return node;
    }

    // --- IMPLEMENTAZIONE METODI DELL'INTERFACCIA TREE ---

    @Override
    public Position<E> root() {
        return root;
    }

    @Override
    public boolean isRoot(Position<E> p) {
        return p == root();
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public Position<E> parent(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getParent();
    }

    @Override
    public int numChildren(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getChildrenList().size();
    }

    @Override
    public boolean isInternal(Position<E> p) throws IllegalArgumentException {
        return numChildren(p) > 0;
    }

    @Override
    public boolean isExternal(Position<E> p) throws IllegalArgumentException {
        return numChildren(p) == 0;
    }

    @Override
    public Iterable<Position<E>> children(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getChildrenList();
    }

    // --- METODI PER LA COSTRUZIONE/MANIPOLAZIONE ---

    /**
     * Inserisce un nodo radice in un albero vuoto.
     *
     * @param e l'elemento da memorizzare nella radice
     * @return la posizione della nuova radice
     * @throws IllegalStateException se l'albero contiene già dei nodi
     */
    public Position<E> addRoot(E e) throws IllegalStateException {
        if (!isEmpty()) {
            throw new IllegalStateException("L'albero non è vuoto");
        }
        root = createNode(e, null);
        size = 1;
        return root;
    }

    /**
     * Aggiunge un nuovo nodo figlio a una posizione genitore data.
     *
     * @param p la posizione del genitore
     * @param e l'elemento da inserire come figlio
     * @return la posizione del nuovo nodo figlio
     * @throws IllegalArgumentException se la posizione p non è valida
     */
    public Position<E> addChild(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> parentNode = validate(p);
        Node<E> childNode = createNode(e, parentNode);
        parentNode.getChildrenList().add(childNode);
        size++;
        return childNode;
    }

    // --- GESTIONE DELLE ITERAZIONI ---

    @Override
    public Iterable<Position<E>> positions() {
        ArrayList<Position<E>> snapshot = new ArrayList<Position<E>>();
        if (!isEmpty()) {
            preorderPositions(root(), snapshot);
        }
        return snapshot;
    }

    /**
     * Metodo di supporto ricorsivo per effettuare una visita in pre-ordine
     * e raccogliere le posizioni dei nodi all'interno di una lista snapshot.
     */
    private void preorderPositions(Position<E> p, ArrayList<Position<E>> snapshot) {
        snapshot.add(p); // Visita il nodo corrente (pre-ordine)
        for (Position<E> child : children(p)) {
            preorderPositions(child, snapshot);
        }
    }

    // Classe interna privata per l'iteratore degli elementi
    private class ElementIterator implements Iterator<E> {
        private final Iterator<Position<E>> posIterator = positions().iterator();

        @Override
        public boolean hasNext() {
            return posIterator.hasNext();
        }

        @Override
        public E next() {
            return posIterator.next().getElement();
        }

        @Override
        public void remove() {
            posIterator.remove();
        }
    }

    @Override
    public Iterator<E> iterator() {
        return new ElementIterator();
    }
}

