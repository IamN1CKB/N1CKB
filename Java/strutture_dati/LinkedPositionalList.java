package strutture_dati;

import java.util.NoSuchElementException;

import java.util.Iterator;

/**
 * Implementazione di una PositionalList tramite lista doppiamente concatenata
 * dotata di sentinelle di testa (header) e coda (trailer).
 * 
 * @param <E> il tipo di elementi memorizzati
 */
public class LinkedPositionalList<E> implements PositionalList<E> {

    // ------------------------------------------------------------------------
    // CLASSE INTERNA STATICA NODE
    // ------------------------------------------------------------------------
    private static class Node<E> implements Position<E> {
        private E element;       // Riferimento all'elemento memorizzato
        private Node<E> prev;    // Riferimento al nodo precedente
        private Node<E> next;    // Riferimento al nodo successivo

        public Node(E e, Node<E> p, Node<E> n) {
            element = e;
            prev = p;
            next = n;
        }

        public E getElement() throws IllegalStateException {
            if (next == null) { // Convenzione per nodo rimosso
                throw new IllegalStateException("Position no longer valid");
            }
            return element;
        }

        public Node<E> getPrev() { return prev; }
        public Node<E> getNext() { return next; }
        
        public void setElement(E e) { element = e; }
        public void setPrev(Node<E> p) { prev = p; }
        public void setNext(Node<E> n) { next = n; }
    }
    // ------------------------------------------------------------------------

    private Node<E> header;    // Sentinella di testa
    private Node<E> trailer;   // Sentinella di coda
    private int size = 0;      // Numero di elementi attivi

    /**
     * Costruttore: inizializza le sentinelle e stabilisce il legame iniziale.
     */
    public LinkedPositionalList() {
        header = new Node<>(null, null, null);
        trailer = new Node<>(null, header, null);
        header.setNext(trailer);
    }

    // Metodi ausiliari di validazione e conversione interna
    private Node<E> validate(Position<E> p) throws IllegalArgumentException {
        if (!(p instanceof Node)) {
            throw new IllegalArgumentException("Invalid p: la posizione non è del tipo Node corretto");
        }
        Node<E> node = (Node<E>) p;
        if (node.getNext() == null) {
            throw new IllegalArgumentException("p is no longer in the list: la posizione è defunta");
        }
        return node;
    }

    private Position<E> position(Node<E> node) {
        if (node == header || node == trailer) {
            return null; // Non esponiamo le sentinelle all'utente
        }
        return node;
    }

    // Metodi di accesso (Accessor)
    public int size() { return size; }
    
    public boolean isEmpty() { return size == 0; }

    public Position<E> first() { 
        return position(header.getNext()); 
    }

    public Position<E> last() { 
        return position(trailer.getPrev()); 
    }

    public Position<E> before(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return position(node.getPrev());
    }

    public Position<E> after(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return position(node.getNext());
    }

    // Metodo di utilità per l'inserimento
    private Position<E> addBetween(E e, Node<E> pred, Node<E> succ) {
        Node<E> newest = new Node<>(e, pred, succ);
        pred.setNext(newest);
        succ.setPrev(newest);
        size++;
        return newest;
    }

    // Metodi di aggiornamento (Update)
    public Position<E> addFirst(E e) {
        return addBetween(e, header, header.getNext());
    }

    public Position<E> addLast(E e) {
        return addBetween(e, trailer.getPrev(), trailer);
    }

    public Position<E> addBefore(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return addBetween(e, node.getPrev(), node);
    }

    public Position<E> addAfter(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> node = validate(p);
        return addBetween(e, node, node.getNext());
    }

    public E set(Position<E> p, E e) throws IllegalArgumentException {
        Node<E> node = validate(p);
        E answer = node.getElement();
        node.setElement(e);
        return answer;
    }

    public E remove(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        Node<E> predecessor = node.getPrev();
        Node<E> successor = node.getNext();
        
        predecessor.setNext(successor);
        successor.setPrev(predecessor);
        size--;
        
        E answer = node.getElement();
        
        // Pulizia riferimenti per aiutare il Garbage Collector
        node.setElement(null);
        node.setNext(null); // Segnala l'invalidità del nodo
        node.setPrev(null);
        
        return answer;
    }

    



    

    
    //Vediamo come poter iterare una lista posizionale
    //Il primo modo per iterare una lista posizionale, è attraverso un oggetto Iterable delle posizioni, che restituisce un iteratore delle posizioni

    public class PositionIterable implements Iterable<Position<E>> {
        public Iterator<Position<E>> iterator() {
            return new PositionIterator();
        }
    }
    
    //definiamo una funzione che restituisce l'oggetto Iterable
    public Iterable<Position<E>> positions() {
        return new PositionIterable();
    }


    //L'iteratore deve essere privato e 
    private class PositionIterator implements Iterator<Position<E>> {
        /** Una Position della lista contenitore, inizializzata alla prima posizione. */
        private Position<E> cursor = first(); // Accede al metodo first() della PositionalList esterna

        /** La Position dell'elemento più recente riportato (se presente). */
        private Position<E> recent = null;

        @Override
        public boolean hasNext() {
            return (cursor != null);
        }

        @Override
        public Position<E> next() throws NoSuchElementException {
            if (cursor == null) {
                throw new NoSuchElementException("non c'è nessuna posizione successivo");
            }
            //ogni volta che viene eseguito next, aggiorniamo recent e cursor
            recent = cursor;
            cursor = after(cursor); // Accede al metodo after() della PositionalList esterna
            return recent;
        }
        

        // Qui potresti implementare remove() che dovrebbe usare recent.
        // L'implementazione di remove() è più complessa in una PositionalList.
        @Override
        public void remove() throws IllegalStateException {
            if (recent == null) throw new IllegalStateException("nothing to remove");
            // logica per rimuovere l'elemento in 'recent' dalla PositionalList esterna
            // questo richiede un riferimento alla PositionalList o un modo per chiamare il suo remove(Position p)
            // Per semplicità, spesso si omette o si rende non supportato.
            //remove(recent); // Si assume che esista un metodo remove(Position p) nella PositionalList
            recent = null; // resetta recent per prevenire doppie rimozioni
        }
    }

    //Possiamo iterare una lista posizionale anche tramite iteratori di elementi che si basano sugli iteratori di posizioni associati
    private class ElementIterator implements Iterator<E> {
        private Iterator<Position<E>> posIterator = new PositionIterator(); // Crea un iteratore di posizioni

        @Override
        public boolean hasNext() {
            return posIterator.hasNext();
        }

        @Override
        public E next() {
            // Chiama next() sull'iteratore di posizioni e poi getElement() sulla posizione risultante
            return posIterator.next().getElement();
        }

        @Override
        public void remove() {
            posIterator.remove(); // Delega la rimozione all'iteratore di posizioni
        }
    }


    @Override
    public Iterator<E> iterator() {
        return new ElementIterator();
    }
}