package strutture_dati;

public class SinglyLinkedList<E> {

    // ---------------- nested Node class ----------------
    private static class Node<E> {
        private E element;       // Riferimento all'elemento informativo contenuto
        private Node<E> next;    // Riferimento al nodo successivo nella lista

        public Node(E e, Node<E> n) {
            this.element = e;
            this.next = n;
        }

        public E getElement() {
            return element;
        }

        public Node<E> getNext() {
            return next;
        }

        public void setNext(Node<E> n) {
            this.next = n;
        }
    } // ---------------- end of nested Node class ----------------

    // Variabili di istanza di SinglyLinkedList
    private Node<E> head = null; // Nodo di testa della lista (null se vuota)
    private Node<E> tail = null; // Nodo di coda della lista (null se vuota)
    private int size = 0;        // Numero di nodi attualmente presenti nella lista

    // Costruttore per creare una lista inizialmente vuota
    public SinglyLinkedList() { }

    // Metodi di accesso fondamentali
    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    // Restituisce (senza rimuovere) il primo elemento della lista
    public E first() {
        if (isEmpty()) return null;
        return head.getElement();
    }

    // Restituisce (senza rimuovere) l'ultimo elemento della lista
    public E last() {
        if (isEmpty()) return null;
        return tail.getElement();
    }
    

	public void addFirst(E e){
		head = new Node<>(e, head); //creazione nuovo nodo
		if(size == 0)
			tail = head;
		size++;
	}
	public void addLast(E e){
		Node<E> newest = new Node<>(e,null);
		if(isEmpty())
			head = newest;
		else
			tail.setNext(newest);
		tail = newest;
		size++;
	}

	public E removeFirst() {
		if(isEmpty()) return null;
		E answer = head.getElement();
		head = head.getNext();
		size--;
		if(size == 0)
			tail = null;
		return answer;
	}
}