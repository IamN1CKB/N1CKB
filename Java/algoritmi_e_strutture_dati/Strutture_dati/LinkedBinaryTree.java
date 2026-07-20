/**
 * Classe BinaryTree<E>
 * Implementa un albero binario con nodi collegati aventi riferimenti espliciti
 * a sinistra, destra e genitore.
 * Fornisce metodi per aggiungere la radice, i nodi figli, ottenere il fratello,
 * ed effettuare l'iterazione in ordine simmetrico (in-order).
 */
package algoritmi_e_strutture_dati.Strutture_dati;

import java.util.ArrayList;
import java.util.Iterator;

public class LinkedBinaryTree<E> implements BinaryTree<E> {

    // --- CLASSE INNESTATA PER LA RAPPRESENTAZIONE DEI NODI ---
    /**
     * Nodo dell'albero binario. Implementa Position ed espone i puntatori
     * tipici della struttura binaria.
     */
    protected static class Node<E> implements Position<E> {
        private E element;     // Elemento memorizzato nel nodo
        private Node<E> parent; // Riferimento al nodo genitore
        private Node<E> left;   // Riferimento al figlio sinistro
        private Node<E> right;  // Riferimento al figlio destro

        /**
         * Costruttore del nodo binario.
         */
        public Node(E e, Node<E> above, Node<E> leftChild, Node<E> rightChild) {
            element = e;
            parent = above;
            left = leftChild;
            right = rightChild;
        }

        @Override
        public E getElement() {
            return element;
        }

        public void setElement(E element) {
            this.element = element;
        }

        public Node<E> getParent() {
            return parent;
        }

        public void setParent(Node<E> parent) {
            this.parent = parent;
        }

        public Node<E> getLeft() {
            return left;
        }

        public void setLeft(Node<E> left) {
            this.left = left;
        }

        public Node<E> getRight() {
            return right;
        }

        public void setRight(Node<E> right) {
            this.right = right;
        }
    } // Fine della classe innestata Node

    /**
     * Factory method per creare un nodo con puntatori specifici.
     */
    protected Node<E> createNode(E e, Node<E> parent, Node<E> left, Node<E> right) {
        return new Node<E>(e, parent, left, right);
    }

    // Attributi di istanza di BinaryTree
    private int size = 0;          // Numero complessivo di nodi nell'albero
    protected Node<E> root = null; // Riferimento alla radice dell'albero

    /**
     * Costruttore: crea un albero binario inizialmente vuoto.
     */
    public LinkedBinaryTree() {
    }

    // --- METODO DI VALIDAZIONE INTERNO ---
    /**
     * Verifica la validità di una posizione e la converte in nodo interno.
     */
    private Node<E> validate(Position<E> p) throws IllegalArgumentException {
        if (!(p instanceof Node)) {
            throw new IllegalArgumentException("Tipo di posizione non valido per questo albero");
        }
        return (Node<E>) p;
    }

    // --- METODI DI MUTAZIONE (BUILDERS) ---

    public Position<E> addRoot(E e) throws IllegalStateException {
        if (!isEmpty()) {
            throw new IllegalStateException("L'albero non è vuoto");
        }
        root = createNode(e, null, null, null);
        size = 1;
        return root;
    }

    public Position<E> addLeft(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> parent = validate(p);
        if (parent.getLeft() != null) {
            throw new IllegalArgumentException("Il nodo genitore ha già un figlio sinistro");
        }
        Node<E> child = createNode(e, parent, null, null);
        parent.setLeft(child);
        size++;
        return child;
    }

    public Position<E> addRight(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> parent = validate(p);
        if (parent.getRight() != null) {
            throw new IllegalArgumentException("Il nodo genitore ha già un figlio destro");
        }
        Node<E> child = createNode(e, parent, null, null);
        parent.setRight(child);
        size++;
        return child;
    }

    // --- IMPLEMENTAZIONE METODI DI NAVIGAZIONE ---

    @Override
    public Position<E> root() {
        return root;
    }

    public Position<E> left(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getLeft();
    }

    public Position<E> right(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getRight();
    }

    @Override
    public Position<E> parent(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getParent();
    }

    /**
     * Restituisce la posizione del fratello del nodo p.
     *
     * @param p posizione del nodo
     * @return posizione del fratello, o null se non esiste o se p è la radice
     */
    public Position<E> sibling(Position<E> p) {
        Position<E> parentNode = parent(p);
        if (parentNode == null) {
            return null; // p è la radice
        }
        if (p == left(parentNode)) {
            return right(parentNode); // Restituisce il destro (può essere null)
        } else {
            return left(parentNode);  // Restituisce il sinistro (può essere null)
        }
    }

    @Override
    public boolean isEmpty() {
        return size() == 0;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isInternal(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getLeft() != null || node.getRight() != null;
    }

    @Override
    public boolean isExternal(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getLeft() == null && node.getRight() == null;
    }

    @Override
    public boolean isRoot(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node == root();
    }

    @Override
    public int numChildren(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        int count = 0;
        if (node.getLeft() != null) count++;
        if (node.getRight() != null) count++;
        return count;
    }

    @Override
    public Iterable<Position<E>> children(Position<E> p) {
        ArrayList<Position<E>> snapshot = new ArrayList<>(2);
        if (left(p) != null) {
            snapshot.add(left(p));
        }
        if (right(p) != null) {
            snapshot.add(right(p));
        }
        return snapshot;
    }

    // --- GESTIONE ITERAZIONI SIMMETRICHE (IN-ORDER) ---

    /**
     * Restituisce un Iterable con le posizioni dell'albero in ordine simmetrico.
     */
    public Iterable<Position<E>> inOrder() {
        ArrayList<Position<E>> snapshot = new ArrayList<>();
        if (!isEmpty()) {
            inOrderSubtree(root(), snapshot);
        }
        return snapshot;
    }

    /**
     * Metodo di supporto ricorsivo per l'attraversamento simmetrico.
     */
    private void inOrderSubtree(Position<E> p, ArrayList<Position<E>> snapshot) {
        if (left(p) != null) {
            inOrderSubtree(left(p), snapshot);
        }
        snapshot.add(p); // Visita simmetrica
        if (right(p) != null) {
            inOrderSubtree(right(p), snapshot);
        }
    }

    /**
     * Sovrascrive positions() dell'albero generico per utilizzare
     * l'ordine simmetrico, specifico ed elettivo degli alberi binari.
     */
    @Override
    public Iterable<Position<E>> positions() {
        return inOrder();
    }

    // Classe interna privata per l'iterazione lineare degli elementi
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