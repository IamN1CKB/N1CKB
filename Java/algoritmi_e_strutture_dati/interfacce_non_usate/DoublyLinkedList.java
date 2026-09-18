package algoritmi_e_strutture_dati.interfacce_non_usate;
/**
 * Versione modificata della classe DoublyLinkedList presentata a lezione.
 * 
 * Rispetto all'implementazione originale, i membri e i metodi ausiliari 
 * (originariamente 'private') sono stati resi 'protected'. Questo incapsulamento 
 * meno restrittivo consente alle sottoclassi di ereditare e utilizzare direttamente 
 * le logiche interne e la struttura dei nodi della lista base.
 * 
 * Questa modifica è stata pensata specificamente per la traccia d'esame di 
 * Marzo 2026, la quale richiede di estendere la struttura dati implementando 
 * un metodo aggiuntivo in una sottoclasse, sfruttando i metodi ausiliari 
 * della classe padre.
 */
public class DoublyLinkedList<E> {

    // Classe innestata per i nodi
    protected static class Node<E> {
        private E element;
        private Node<E> prev;
        private Node<E> next;

        protected Node(E e, Node<E> p, Node<E> n) {
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

        public void clear() {
            this.element = null;
            this.prev = null;
            this.next = null;
        }
    }

    protected Node<E> header;
    protected Node<E> trailer;
    protected int size = 0;

    public DoublyLinkedList() {
        header = new Node<>(null, null, null);
        trailer = new Node<>(null, header, null);
        header.setNext(trailer);
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
        return header.getNext().getElement();
    }

    public E last() {
        if (isEmpty()) {
            return null;
        }
        return trailer.getPrev().getElement();
    }

    protected void addBetween(E element, Node<E> predecessor, Node<E> successor) {
        Node<E> newNode = new Node<>(element, predecessor, successor);
        predecessor.setNext(newNode);
        successor.setPrev(newNode);
        size++;
    }

    protected E remove(Node<E> node) {
        Node<E> predecessor = node.getPrev();
        Node<E> successor = node.getNext();
        predecessor.setNext(successor);
        successor.setPrev(predecessor);
        E element = node.getElement(); 
        node.clear(); // libera memoria
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
        Node<E> corrente = header.getNext();
        while (corrente!=trailer) {
            E element = corrente.getElement();
            System.out.println(element);
            corrente=corrente.getNext(); //simile a un incremento
        }
        System.out.println("\n");
    }
}
