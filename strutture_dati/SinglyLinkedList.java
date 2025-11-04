package strutture_dati;

public class SinglyLinkedList<E>{
	//---Classe innestata chiamata Node---/
	private static class Node<E> {
		private E element; //riferimento all'elemento contenuto nel nodo
		private Node<E> next; //riferimento al nodo successivo nella lista
		public Node(E e,Node<E> n){
			element = e;
			next = n;
		}
		public E getElement(){return element;}
		public Node<E> getNext() {return next;}
		public void setNext(Node<E> n){next = n;}
	}//fine classe nodo
	private Node<E> head = null; //nodo testa della lista(null se vuoto)
	private Node<E> tail = null; //stessa cosa solo che per la coda
	private int size = 0;
	public SinglyLinkedList(){}   //costruttore vuoto siccome non servono parametri
	//metodi di accesso qui
	public int size(){return size;}
	public boolean isEmpty() {return size==0;}
	public E first(){
		if(isEmpty()) return null;
		return head.getElement();
	}
	public E last(){
		if(isEmpty()) return null;
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