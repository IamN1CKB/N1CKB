package algoritmi_e_strutture_dati.Strutture_dati;

public class ArrayStack<E> implements Stack<E> {
    private E[] data;       // Array di supporto per la memorizzazione dei dati
    private int t = -1;     // Indice dell'elemento in cima alla pila (-1 se vuota)

    @SuppressWarnings("unchecked")  // Annotazione per sopprimere l'avviso di cast non sicuro
    public ArrayStack(int capacity) {
        // Cast necessario a causa della cancellazione dei tipi nei generics di Java
        data = (E[]) new Object[capacity];
    }

    @Override
    public int size() {
        return (t + 1);
    }

    @Override
    public boolean isEmpty() {
        return (t == -1);
    }

    @Override
    public E top() {
        if (isEmpty()) return null;
        return data[t];
    }

    @Override
    public void push(E element) throws IllegalStateException {
        if (size() == data.length) {
            throw new IllegalStateException("Stack is full");
        }
        data[++t] = element; // Incrementa l'indice 't' e inserisce l'elemento
    }

    @Override
    public E pop() {
        if (isEmpty()) return null;
        E answer = data[t];

        // De-referenziazione dell'elemento per agevolare il Garbage Collector
        data[t] = null;

        t--;
        return answer;
    }
}