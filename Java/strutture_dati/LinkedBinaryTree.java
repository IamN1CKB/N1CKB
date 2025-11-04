/**
 * Classe BinaryTree<E>
 * Implementa un albero binario con nodi che hanno riferimenti a sinistra, destra e genitore.
 * Fornisce metodi per aggiungere radice, figli sinistro/destro, ottenere fratello, visitare l'albero in-order, ecc.
 * Ogni nodo è rappresentato dalla classe interna Node<E>.
 */
package strutture_dati;

import java.util.ArrayList;
import java.util.Iterator;

public class LinkedBinaryTree<E> implements BinaryTree<E> {
    /**
     * Nodo dell'albero binario, contiene elemento, riferimenti a genitore, sinistra
     * e destra.
     */
    protected static class Node<E> implements Position<E> {
        private E element; // elemento memorizzato nel nodo
        private Node<E> parent; // riferimento al nodo genitore
        private Node<E> left; // riferimento al figlio sinistro
        private Node<E> right; // riferimento al figlio destro

        /**
         * Costruttore del nodo binario.
         * 
         * @param e          elemento da memorizzare
         * @param above      genitore
         * @param leftChild  figlio sinistro
         * @param rightChild figlio destro
         */
        public Node(E e, Node<E> above, Node<E> leftChild, Node<E> rightChild) {
            element = e;
            parent = above;
            left = leftChild;
            right = rightChild;
        }

        /** Restituisce l'elemento memorizzato. */
        public E getElement() {
            return element;
        }

        /** Imposta l'elemento del nodo. */
        public void setElement(E element) {
            this.element = element;
        }

        /** Restituisce il genitore. */
        public Node<E> getParent() {
            return parent;
        }

        /** Imposta il genitore. */
        public void setParent(Node<E> parent) {
            this.parent = parent;
        }

        /** Restituisce il figlio sinistro. */
        public Node<E> getLeft() {
            return left;
        }

        /** Imposta il figlio sinistro. */
        public void setLeft(Node<E> left) {
            this.left = left;
        }

        /** Restituisce il figlio destro. */
        public Node<E> getRight() {
            return right;
        }

        /** Imposta il figlio destro. */
        public void setRight(Node<E> right) {
            this.right = right;
        }
    } // fine classe innestata

    /*
     * La classe Node è dichiarata protected perché le eventuali classi
     * che ereditano da LinkedBinaryTree_mod devono poter accedere
     * alla classe Node.
     */
    /**
     * Crea un nuovo nodo binario con elemento, genitore, figlio sinistro e destro.
     */
    protected Node<E> createNode(E e, Node<E> parent, Node<E> left, Node<E> right) {
        return new Node<E>(e, parent, left, right);
    }

    private int size = 0; // numero di nodi nell'albero
    protected Node<E> root = null; // radice dell'albero

    /** Costruttore: crea un albero binario vuoto. */
    public LinkedBinaryTree() {
    }

    /**
     * Converte una posizione in nodo e ne controlla la validità.
     * 
     * @param p posizione da validare
     * @return nodo corrispondente
     * @throws IllegalArgumentException se la posizione non è valida
     */
    private Node<E> validate(Position<E> p) throws IllegalArgumentException {
        if (!(p instanceof Node)) {
            throw new IllegalArgumentException("Not valid position type");
        }
        Node<E> node = (Node<E>) p;
        return node;
    }

    /**
     * Aggiunge la radice all'albero (solo se vuoto).
     * 
     * @param e elemento da inserire come radice
     * @return posizione della radice
     * @throws IllegalStateException se l'albero non è vuoto
     */
    public Position<E> addRoot(E e) throws IllegalStateException {
        if (!isEmpty()) {
            throw new IllegalStateException("Tree is not empty");
        }
        root = createNode(e, null, null, null);
        size = 1;
        return root;
    }

    /**
     * Restituisce la posizione della radice dell'albero.
     */
    @Override
    public Position<E> root() {
        return root;
    }

    /**
     * Restituisce il figlio sinistro di p.
     */
    public Position<E> left(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getLeft();
    }

    /**
     * Restituisce il figlio destro di p.
     */
    public Position<E> right(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getRight();
    }

    /**
     * Restituisce il genitore di p.
     */
    @Override
    public Position<E> parent(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getParent();
    }

    /**
     * Restituisce il fratello di p (null se non esiste).
     */
    public Position<E> sibling(Position<E> p) {
        Position<E> parent = parent(p);
        if (parent == null) {
            return null;
        } else if (p == left(parent)) {
            return right(parent);
        } else {
            return left(parent);
        }
    }

    /**
     * Aggiunge un figlio sinistro a p.
     * 
     * @param p posizione del genitore
     * @param e elemento da inserire come figlio sinistro
     * @return posizione del nuovo figlio sinistro
     * @throws IllegalArgumentException se p ha già un figlio sinistro
     */
    public Position<E> addLeft(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> parent = validate(p);
        if (parent.getLeft() != null) {
            throw new IllegalArgumentException("p has already left child");
        }
        Node<E> child = createNode(e, parent, null, null);
        parent.setLeft(child);
        size++;
        return child;
    }

    /**
     * Aggiunge un figlio destro a p.
     * 
     * @param p posizione del genitore
     * @param e elemento da inserire come figlio destro
     * @return posizione del nuovo figlio destro
     * @throws IllegalArgumentException se p ha già un figlio destro
     */
    public Position<E> addRight(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> parent = validate(p);
        if (parent.getRight() != null) {
            throw new IllegalArgumentException("p has already right child");
        }
        Node<E> child = createNode(e, parent, null, null);
        parent.setRight(child);
        size++;
        return child;
    }

    /**
     * Restituisce true se l'albero è vuoto.
     */
    @Override
    public boolean isEmpty() {
        return size() == 0;
    }

    /**
     * Restituisce il numero totale di nodi nell'albero.
     */
    @Override
    public int size() {
        return size;
    }

    /**
     * Restituisce true se p è un nodo interno (ha almeno un figlio).
     */
    @Override
    public boolean isInternal(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getLeft() != null || node.getRight() != null;
    }

    /**
     * Restituisce true se p è una foglia (nessun figlio).
     */
    @Override
    public boolean isExternal(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getLeft() == null && node.getRight() == null;
    }

    /**
     * Restituisce true se p è la radice dell'albero.
     */
    @Override
    public boolean isRoot(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node == root();
    }

    /**
     * Restituisce il numero di figli di p (0, 1 o 2).
     */
    @Override
    public int numChildren(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        int count = 0;
        if (node.getLeft() != null)
            count++;
        if (node.getRight() != null)
            count++;
        return count;
    }

    /**
     * Restituisce un Iterable con i figli (sinistro e destro) di p.
     */
    @Override
    public Iterable<Position<E>> children(Position<E> p) {
        ArrayList<Position<E>> snapshot = new ArrayList<>();
        if (left(p) != null) {
            snapshot.add(left(p));
        }
        if (right(p) != null) {
            snapshot.add(right(p));
        }
        return snapshot;
    }

    /**
     * Metodo ricorsivo di supporto per inOrder().
     * Visita ricorsivamente il sotto-albero radicato in p in ordine in-order e
     * aggiunge le posizioni a snapshot.
     */
    private void inOrderSubtree(Position<E> p, ArrayList<Position<E>> snapshot) {
        if (left(p) != null) {
            inOrderSubtree(left(p), snapshot);
        }
        snapshot.add(p);
        if (right(p) != null) {
            inOrderSubtree(right(p), snapshot);
        }
    }

    /**
     * Restituisce un Iterable con le posizioni dell'albero in ordine in-order.
     */
    public Iterable<Position<E>> inOrder() {
        ArrayList<Position<E>> snapshot = new ArrayList<>();
        if (!isEmpty()) {
            inOrderSubtree(root(), snapshot);
        }
        return snapshot;
    }

    /**
     * Restituisce un Iterable con tutte le posizioni dell'albero (in-order).
     */
    @Override
    public Iterable<Position<E>> positions() {
        return inOrder();
    }

    /**
     * Iteratore sugli elementi dell'albero (ordine in-order).
     */
    private class ElementIterator implements Iterator<E> {
        Iterator<Position<E>> posIterator = positions().iterator();

        public boolean hasNext() {
            return posIterator.hasNext();
        }

        public E next() {
            return posIterator.next().getElement();
        }

        public void remove() {
            posIterator.remove();
        }
    }

    /**
     * Restituisce un iteratore sugli elementi dell'albero (ordine in-order).
     */
    @Override
    public Iterator<E> iterator() {
        return new ElementIterator();
    }
}
