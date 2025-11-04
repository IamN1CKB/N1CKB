package strutture_dati;

public class ArrayStack<E> implements Stack<E>{
    private E[] data;
    private int t = -1; //t+1 = size, quindi t =indice array
    
    @SuppressWarnings("unchecked")    //usato per non generare un warning nella conversione da Object a E
    public ArrayStack(int capacity) {
        data = (E[]) new Object[capacity];
    }

    @Override
    public int size() {
        return t+1;
    }

    @Override
    public boolean isEmpty() {
        return t==-1;    
    }

    @Override
    public E top() {
        if (isEmpty()) {
            return null;
        }
        return data[t];
    }

    @Override
    public void push(E element) throws IllegalStateException {
        if (size()==data.length) {
            throw new IllegalStateException("Stack is full");
        }
        data[++t] = element;
    }

    @Override
    public E pop() {
        if (isEmpty()) {
            return null;
        }
        E answer = data[t];
        data[t] = null;
        t--;
        return answer;
    }
    
}
