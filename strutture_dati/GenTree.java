
// Implementazione di un albero generico (n-ario) che supporta operazioni di base e iterazione.
package strutture_dati;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * Classe che implementa un albero generico (n-ario) tramite nodi con lista di
 * figli.
 * Fornisce metodi per aggiungere radice, figli, e per l'iterazione sugli
 * elementi e sulle posizioni.
 */
public class GenTree<E> implements Tree<E> {

    // ---CLASSE INNESTATA PER LA CREAZIONE DEI NODI---//
    /**
     * Nodo dell'albero generico, contiene un elemento, il riferimento al genitore e
     * la lista dei figli.
     */
    /*
     * La classe Node è dichiarata protected per permettere che sia visibile e utilizzabile dalle sottoclassi di GenTree (ad esempio, se vuoi estendere GenTree per creare un nuovo tipo di albero), ma non dall’esterno del package strutture_dati o da altre classi che usano GenTree.
        In pratica:
        - protected consente l’accesso a Node solo a GenTree, alle sue sottoclassi e alle classi nello stesso package.
        - Se fosse private, solo GenTree potrebbe usarla, rendendo impossibile l’estensione.
        - Se fosse public, chiunque potrebbe creare nodi e manipolarli dall’esterno, rompendo l’incapsulamento.

        Quindi protected è una scelta che bilancia estendibilità e sicurezza dell’incapsulamento.
     */
    private static class Node<E> implements Position<E> {
        private E element; // elemento memorizzato nel nodo
        private Node<E> parent; // riferimento al nodo genitore
        private ArrayList<Position<E>> children; // lista dei figli

        /**
         * Costruttore del nodo.
         * 
         * @param e     elemento da memorizzare
         * @param above riferimento al genitore
         */
        public Node(E e, Node<E> above) {
            element = e;
            parent = above;
            children = new ArrayList<>();
        }

        // metodi di accesso
        /** Restituisce l'elemento memorizzato nel nodo. */
        public E getElement() {
            return element;
        }

        /** Restituisce il nodo genitore. */
        public Node<E> getParent() {
            return parent;
        }

        // metodi di aggiornamento
        /** Imposta l'elemento del nodo. */
        public void setElement(E e) {
            element = e;
        }

        /** Imposta il nodo genitore. */
        public void setParent(Node<E> parentNode) {
            parent = parentNode;
        }
    }// fine della classe node innestata

    /**
     * Crea un nuovo nodo con elemento e e genitore parent.
     * 
     * @param e      elemento da inserire
     * @param parent nodo genitore
     * @return nuovo nodo creato
     */
    protected Node<E> createNode(E e, Node<E> parent) {
        return new Node<>(e, parent);
    }

    // Attributi dell'albero
    protected Node<E> root = null; // radice dell'albero
    private int size = 0; // numero di nodi nell'albero


    // Costruttore: crea un albero vuoto.
    public GenTree() {
    }

    // ----INIZIO IMPLEMENTAZIONE METODI DELL'INTERFACCIA TREE-----//
    
    // Restituisce la posizione della radice dell'albero (null se vuoto).
    public Position<E> root() {
        return root;
    }

    /**
     * Controlla che la posizione sia valida e la converte in nodo.
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
     * Restituisce la posizione del genitore di p.
     * 
     * @param p posizione di cui trovare il genitore
     * @return posizione del genitore
     * @throws IllegalArgumentException se p non è valida
     */
    public Position<E> parent(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return node.getParent();
    }

    /**
     * Restituisce il numero di figli di p.
     * 
     * @param p posizione di cui contare i figli
     * @return numero di figli
     * @throws IllegalArgumentException se p non è valida
     */
    public int numChildren(Position<E> p) throws IllegalArgumentException {
        Node<E> parent = validate(p);
        return parent.children.size();
    }

    /**
     * Restituisce true se p è un nodo interno (ha almeno un figlio).
     */
    public boolean isInternal(Position<E> p) {
        return numChildren(p) > 0;
    }

    /**
     * Restituisce true se p è una foglia (nessun figlio).
     */
    public boolean isExternal(Position<E> p) {
        return numChildren(p) == 0;
    }

    /**
     * Restituisce true se p è la radice dell'albero.
     */
    public boolean isRoot(Position<E> p) {
        return p == root();
    }

    /**
     * Restituisce il numero totale di nodi nell'albero.
     */
    public int size() {
        return size;
    }

    /**
     * Restituisce true se l'albero è vuoto.
     */
    public boolean isEmpty() {
        return size == 0;
    }

    // METODI PER COSTRUIRE L'ALBERO
    /**
     * Aggiunge la radice all'albero (solo se vuoto).
     * 
     * @param e elemento da inserire come radice
     * @return posizione della radice
     * @throws IllegalStateException se l'albero non è vuoto
     */
    public Position<E> addRoot(E e) throws IllegalStateException {
        if (size() > 0) {
            throw new IllegalStateException("Tree is not empty");
        }
        root = createNode(e, null);
        size = 1;
        return root;
    }

    /**
     * Aggiunge un figlio a p con elemento e.
     * 
     * @param p posizione del genitore
     * @param e elemento da inserire come figlio
     * @return posizione del nuovo figlio
     * @throws IllegalArgumentException se p non è valida
     */
    public Position<E> addChild(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> parent = validate(p);
        Node<E> child = createNode(e, parent);
        int nChild = numChildren(p);
        parent.children.add(nChild, child);
        size++;
        return child;
    }


    // METODI E CLASSI PER ITERAZIONI DI ELEMENTI DELL'ALBERO
    // ATTRAVERSAMENTO PRE-ORDER//
    
    /**
     * Restituisce un Iterable con tutte le posizioni dei figli di p.
     * 
     * @param p posizione del nodo genitore
     * @return Iterable delle posizioni dei figli
     * @throws IllegalArgumentException se p non è valida
     */
    public Iterable<Position<E>> children(Position<E> p) throws IllegalArgumentException {
        Node<E> parent = validate(p);
        return parent.children;
        //questo metodo è creato siccome l'attributo children di Node è private e non accessibile direttamente da GenTree
    }

    /**
     * Restituisce un Iterable con tutte le posizioni dell'albero (ordine
     * pre-order).
     */
    public Iterable<Position<E>> positions() {
        ArrayList<Position<E>> snapshot = new ArrayList<>();
        if (!isEmpty()) {
            addChildren(root(), snapshot);
        }
        return snapshot;
    }

    /**
     * Metodo di supporto per la visita pre-order: aggiunge p e ricorsivamente tutti
     * i suoi discendenti a snapshot.
     * 
     * @param p        posizione da cui partire
     * @param snapshot lista in cui accumulare le posizioni
     */
    private void addChildren(Position<E> p, ArrayList<Position<E>> snapshot) {
        snapshot.add(p);
        for (Position<E> position : children(p)) {
            addChildren(position, snapshot);
        }
    }

    // Iteratore sugli elementi dell'albero (visita in profondità pre-order).
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
     * Restituisce un iteratore sugli elementi dell'albero (ordine pre-order) abilitando il for each.
     */
    public Iterator<E> iterator() {
        return new ElementIterator();
    }
}
