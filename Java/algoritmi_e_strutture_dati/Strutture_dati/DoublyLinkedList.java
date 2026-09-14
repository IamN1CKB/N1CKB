package algoritmi_e_strutture_dati.Strutture_dati;


public class DoublyLinkedList<E> implements DoublyLinkedListInterface<E> {

    // Classe innestata per i nodi bidirezionali della lista
    private static class Node<E> {
        private E element;           // Riferimento all'elemento informativo contenuto
        private Node<E> prev;        // Riferimento al nodo precedente nella lista
        private Node<E> next;        // Riferimento al nodo successivo nella lista

        private Node(E e, Node<E> p, Node<E> n) {
            this.element = e;
            this.prev = p;
            this.next = n;
        }

        public E getElement() {
            return element;
        }

        public Node<E> getPrev() {
            return prev;
        }

        public Node<E> getNext() {
            return next;
        }

        public void setPrev(Node<E> p) {
            this.prev = p;
        }

        public void setNext(Node<E> n) {
            this.next = n;
        }

        // Pulisce i riferimenti per facilitare il Garbage Collector
        public void clear() {
            this.element = null;
            this.prev = null;
            this.next = null;
        }
    }

    private Node<E> header;     // Nodo sentinella all'inizio della lista
    private Node<E> trailer;    // Nodo sentinella alla fine della lista
    private int size = 0;       // Numero di nodi attualmente presenti nella lista

    // Costruttore per creare una lista inizialmente vuota
    public DoublyLinkedList() {
        header = new Node<>(null, null, null);          // Nodo sentinella iniziale
        trailer = new Node<>(null, header, null);          // Nodo sentinella finale
        header.setNext(trailer);                                // Collega il nodo sentinella iniziale al nodo sentinella finale
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public E first() {
        if (isEmpty()) {
            return null;
        }
        // doppia lettura: prima si ottiene il nodo successivo al nodo sentinella iniziale, poi si ottiene l'elemento di quel nodo
        return header.getNext().getElement();
    }

    public E last() {
        if (isEmpty()) {
            return null;
        }
        // doppia lettura: prima si ottiene il nodo precedente al nodo sentinella finale, poi si ottiene l'elemento di quel nodo
        return trailer.getPrev().getElement();
    }

    private void addBetween(E element, Node<E> predecessor, Node<E> successor) {
        // Crea un nuovo nodo e lo inserisce tra il nodo predecessore e il nodo successore
        Node<E> newNode = new Node<>(element, predecessor, successor);
        // Aggiorna i riferimenti dei nodi adiacenti per includere il nuovo nodo
        predecessor.setNext(newNode);
        successor.setPrev(newNode);
        size++;
    }

    private E remove(Node<E> node) {
        Node<E> predecessor = node.getPrev();
        Node<E> successor = node.getNext();
        // Aggiorna i riferimenti dei nodi adiacenti per escludere il nodo da rimuovere
        predecessor.setNext(successor);
        successor.setPrev(predecessor);
        E element = node.getElement(); 
        node.clear(); // Azzera i riferimenti per il garbage collector
        size--;
        return element;
    }

    public void addFirst(E element) {
        addBetween(element, header, header.getNext());
    }

    public void addLast(E element) {
        addBetween(element, trailer.getPrev(), trailer);
    }

    public E removeFirst() {
        if (isEmpty()) return null;
        return remove(header.getNext());
        
    }

    public E removeLast() {
        if (isEmpty()) return null;
        return remove(trailer.getPrev());
    }

    public void stampa() {
        // Si parte dal primo elemento reale della lista (successivo al nodo sentinella iniziale) e si itera fino al nodo sentinella finale
        Node<E> corrente = header.getNext();
        while (corrente!=trailer) { // finché non si raggiunge il nodo sentinella finale
            E element = corrente.getElement();
            System.out.println(element);
            corrente=corrente.getNext(); //simile a un incremento
        }
        System.out.println("\n");
    }
}
