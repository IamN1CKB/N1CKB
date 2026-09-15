package algoritmi_e_strutture_dati.Strutture_dati;

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
        if (node.getNext() == null) {   // Nodo rimosso o sentinella
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

    

    // Implementazione dell'iteratore per le posizioni

    private class PositionIterator implements Iterator<Position<E>> {
        private Position<E> cursor = first();   // Inizia dalla testa della lista
        private Position<E> recent = null;      // Memorizza l'ultimo elemento restituito

        // Verifica se vi sono altre posizioni da visitare
        public boolean hasNext() {
            return (cursor != null);
        }

        // Avanza il cursore e restituisce la posizione visitata
        public Position<E> next() throws NoSuchElementException {
            if (cursor == null) {
                throw new NoSuchElementException("Nessun'altra posizione disponibile");
            }
            recent = cursor;            // Salva la posizione corrente
            cursor = after(cursor);     // Avanza il cursore alla posizione successiva
            return recent;
        }

        // Rimuove l'ultimo elemento restituito dalla lista posizionale
        public void remove() {
            if (recent == null) {
                throw new IllegalStateException("Nessuna posizione valida da rimuovere");
            }
            LinkedPositionalList.this.remove(recent); // Rinvio alla rimozione della lista esterna
            recent = null; // Azzera il riferimento per impedire rimozioni consecutive non autorizzate
        }
    }

    
    private class PositionIterable implements Iterable<Position<E>> {
        public Iterator<Position<E>> iterator() {
            return new PositionIterator();
        }
    }

    public Iterable<Position<E>> positions() {
        return new PositionIterable();
    }

    // Implementazione dell'iteratore per gli elementi
    private class ElementIterator implements Iterator<E> {
        // Istanzia internamente il PositionIterator per sfruttare lo scorrimento dei nodi
        Iterator<Position<E>> posIterator = new PositionIterator();

        // Riferisce direttamente al comportamento del PositionIterator
        public boolean hasNext() {
            return posIterator.hasNext();
        }

        // Estrae l'elemento reale dal nodo restituito dal PositionIterator
        public E next() {
            return posIterator.next().getElement(); // Adatta l'output estraendo il dato generico
        }

        // Riferisce l'operazione di rimozione
        public void remove() {
            posIterator.remove();
        }
    }

    @Override
    public Iterator<E> iterator() {
        return new ElementIterator();
    }


    // Implementazione dell'iteratore inverso per le posizioni

    private class PositionIteratorB implements Iterator<Position<E>> {
        private Position<E> cursor = last();    // Il cursore inizia dall'ultimo elemento
        private Position<E> recent = null;       // Memorizza l'ultimo elemento restituito

        // Verifica se vi sono altre posizioni risalendo verso la testa
        public boolean hasNext() {
            return (cursor != null);
        }

        // Restituisce la posizione corrente e arretra il cursore
        public Position<E> next() throws NoSuchElementException {
            if (cursor == null) {
                throw new NoSuchElementException("Nessun'altra posizione disponibile a ritroso");
            }
            recent = cursor;            // Salva la posizione corrente
            cursor = before(cursor);    // Sposta il cursore sul nodo precedente (arretramento)
            return recent;
        }

        // Rimuove l'ultimo elemento restituito durante lo scorrimento inverso
        public void remove() throws IllegalStateException {
            if (recent == null) {
                throw new IllegalStateException("Nessuna posizione valida da rimuovere");
            }
            LinkedPositionalList.this.remove(recent); // Delega alla rimozione strutturale della lista
            recent = null; // Impedisce rimozioni multiple consecutive
        }
    }
    // Implementazione dell'iterable inverso per le posizioni
    private class PositionIterableB implements Iterable<Position<E>> {
        public Iterator<Position<E>> iterator() {
            return new PositionIteratorB();
        }
    }

    // Restituisce un iterable per scorrere le posizioni in ordine inverso
    public Iterable<Position<E>> positionsB() {
        return new PositionIterableB();
    }
}
