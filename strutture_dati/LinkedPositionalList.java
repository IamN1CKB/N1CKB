package strutture_dati;

import java.util.NoSuchElementException;
import java.util.Iterator;

public class LinkedPositionalList<E> implements PositionalList<E> {
    // Classe annidata Node
    private static class Node<E> implements Position<E> {
        private E element;
        private Node<E> prev;
        private Node<E> next;

        public Node(E e, Node<E> p, Node<E> n) {
            element = e;
            prev = p;
            next = n;
        }

        public E getElement() throws IllegalStateException {
            if (next == null)  // nodo non valido
                throw new IllegalStateException("Posizione non piu' valida");
            return element;
        }

        // getter/setter ausiliari
        public Node<E> getPrev() { return prev; }
        public Node<E> getNext() { return next; }
        public void setElement(E e) { element = e; }
        public void setPrev(Node<E> p) { prev = p; }
        public void setNext(Node<E> n) { next = n; }
    }
    // Fine classe innesta Node

    private Node<E> header;
    private Node<E> trailer;
    private int size = 0;

    public LinkedPositionalList() {
        header = new Node<>(null, null, null);
        trailer = new Node<>(null, header, null);
        header.setNext(trailer);
    }

    // Validazione di una posizione
    private Node<E> validate(Position<E> p) throws IllegalArgumentException {
        if (!(p instanceof Node))
            throw new IllegalArgumentException("Invalid p");
        Node<E> node = (Node<E>) p;
        if (node.getNext() == null)  // nodo rimosso
            throw new IllegalArgumentException("La posizione non e' piu' nella lista");
        return node;
    }

    // Converte un nodo in una posizione, gestendo header e trailer
    private Position<E> position(Node<E> node) {
        if (node == header || node == trailer) return null;
        return node;
    }

    // Metodi principali
    public int size() { return size; }
    public boolean isEmpty() { return size == 0; }
    public Position<E> first() { return position(header.getNext()); }
    public Position<E> last() { return position(trailer.getPrev()); }

    private Position<E> addBetween(E e, Node<E> pred, Node<E> succ) {
        Node<E> newest = new Node<>(e, pred, succ);
        pred.setNext(newest);
        succ.setPrev(newest);
        size++;
        return newest;
    }

    public Position<E> addFirst(E e) {
	    return addBetween(e, header, header.getNext());
	  }
    public Position<E> addLast(E e) {
	    return addBetween(e, trailer.getPrev(), trailer);
	  }
    public Position<E> addBefore(Position<E> p, E e) {
        Node<E> node = validate(p);
        return addBetween(e, node.getPrev(), node);
    }
    public Position<E> addAfter(Position<E> p, E e) {
        Node<E> node = validate(p);
        return addBetween(e, node, node.getNext());
    }
    public E set(Position<E> p, E e) {
        Node<E> node = validate(p);
        E answer = node.getElement();
        node.setElement(e);
        return answer;  //ritorniamo il valore salvato precedentemente
    }
    public E remove(Position<E> p) {
        Node<E> node = validate(p);
        Node<E> predecessor = node.getPrev();
        Node<E> successor = node.getNext();
        predecessor.setNext(successor);
        successor.setPrev(predecessor);
        size--;
        E element = node.getElement();
        node.setElement(null);
        node.setNext(null);  // aiuta il garbage collector
        node.setPrev(null);
        return element;
    }

    

    @Override
    public Position<E> before(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        if (node.getPrev() == header) return null;
        return node.getPrev();
    }
    
    
    public Position<E> after(Position<E> p) throws IllegalArgumentException {
        Node<E> node = validate(p);
        if (node.getNext() == trailer) return null;
        return node.getNext();
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